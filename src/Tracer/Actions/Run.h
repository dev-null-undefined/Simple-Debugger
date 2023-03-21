#ifndef SIMPLE_DEBUGGER_RUN_H
#define SIMPLE_DEBUGGER_RUN_H


#include "../Action.h"

class Run : public Action {
public:
protected:
    std::string getName() const override;

public:
    void execute(Controller &controller, const std::vector<std::string> &args) override;

};


#endif //SIMPLE_DEBUGGER_RUN_H
