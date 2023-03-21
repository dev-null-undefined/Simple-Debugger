#ifndef SIMPLE_DEBUGGER_CONTINUE_H
#define SIMPLE_DEBUGGER_CONTINUE_H

#include "../Action.h"
#include "../Debugger.h"

class Continue : public Action {
public:
    void execute(Debugger &controller, const std::vector<std::string> &args) override;

protected:
    std::string getName() const override;

};


#endif //SIMPLE_DEBUGGER_CONTINUE_H
