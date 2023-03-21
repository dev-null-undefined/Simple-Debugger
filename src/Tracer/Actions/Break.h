#ifndef SIMPLE_DEBUGGER_BREAK_H
#define SIMPLE_DEBUGGER_BREAK_H


#include "../Action.h"

class Break: public Action{
protected:
    std::string getName() const override;

public:
    void execute(Controller &controller, const std::vector<std::string> &args) override;

};


#endif //SIMPLE_DEBUGGER_BREAK_H
