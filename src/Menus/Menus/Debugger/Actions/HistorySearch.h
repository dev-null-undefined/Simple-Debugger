#ifndef SIMPLE_DEBUGGER_HISTORYSEARCH_H
#define SIMPLE_DEBUGGER_HISTORYSEARCH_H


#include "../Action.h"
#include "../../../../Tracer/ShortCut.h"
#include "../Debugger.h"

class HistorySearch: public ShortCut {
public:
    void execute(Debugger &controller, const std::vector<std::string> &args) override;
    [[nodiscard]] bool shortCutMatches(const std::string &command) const override;

protected:
    std::string getName() const override;
};


#endif //SIMPLE_DEBUGGER_HISTORYSEARCH_H
