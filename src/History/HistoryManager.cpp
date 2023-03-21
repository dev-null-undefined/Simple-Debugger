#include <limits>
#include <map>
#include <filesystem>
#include <pwd.h>
#include <csignal>
#include <fstream>
#include "HistoryManager.h"
#include "../Algorithms.h"
#include "HistoryRecord.h"

namespace fs = std::filesystem;

void HistoryManager::add(HistoryRecord record) {
    m_history.push_back(std::move(record));
    if (m_history.size() > HISTORY_LIMIT + MAX_OVER) {
        m_history.erase(m_history.begin(), m_history.begin() + MAX_OVER);
    }
}

std::vector<std::string> HistoryManager::search(const std::string &command) const {
    std::vector<std::string> results;
    std::map<double, std::string> fuzzy_results;
    double best_fuzzy = std::numeric_limits<double>::max();
    for (const auto &[history_command, time]: m_history) {
        if (hasPrefix(history_command, command)) {
            results.push_back(history_command);
        }
        double fuzzy = levenshteinDistance(command, history_command);
        if (fuzzy < best_fuzzy) {
            best_fuzzy = (fuzzy + best_fuzzy) / 2;
            fuzzy_results.emplace(fuzzy, history_command);
        } else if (fuzzy > best_fuzzy && fuzzy < best_fuzzy + 0.5) {
            fuzzy_results.insert({fuzzy, history_command});
        }
    }
    for (const auto &[fuzz, history_command]: fuzzy_results) {
        if (fuzz < best_fuzzy + 0.5) {
            results.push_back(history_command);
        }
    }
    return results;
}

const char *getHomeDir() {
    const char *home = getenv("HOME");
    if (home == nullptr) {
        home = getpwuid(getuid())->pw_dir;
    }
    return home;
}

HistoryManager::HistoryManager() {
    fs::path history_path = fs::path(getHomeDir()) / ".history";
    if (fs::exists(history_path)) {
        std::ifstream history_file(history_path);
        HistoryRecord record;
        while (history_file >> record) {
            m_history.push_back(record);
        }
    }
}

HistoryManager::~HistoryManager() {
    fs::path history_path = fs::path(getHomeDir()) / ".history";
    std::ofstream history_file(history_path);
    for (const auto &record: m_history) {
        history_file << record << std::endl;
    }
}
