#ifndef SIMPLE_DEBUGGER_HISTORYMANAGER_H
#define SIMPLE_DEBUGGER_HISTORYMANAGER_H
#include <vector>
#include <string>
#include "HistoryRecord.h"

class HistoryManager {
    static constexpr size_t HISTORY_LIMIT = 1'000'000;
    static constexpr size_t MAX_OVER = 100;
    std::vector<HistoryRecord> m_history;
public:
    HistoryManager();
    HistoryManager(const HistoryManager & other) = delete;
    HistoryManager(HistoryManager && other) = delete;
    ~HistoryManager();

    void add(HistoryRecord command);
    std::vector<std::string> search(const std::string &command) const;
};


#endif //SIMPLE_DEBUGGER_HISTORYMANAGER_H
