#include "HistorySearch.h"
#include "../Debugger.h"

void HistorySearch::execute(Debugger &controller, const std::vector<std::string> &args) {
//    controller.reverseSearch();
}

std::string HistorySearch::getName() const {
    return "history-search";
}

bool HistorySearch::shortCutMatches(const std::string &command) const {
    return command == "^r" || command == "^R";
}
