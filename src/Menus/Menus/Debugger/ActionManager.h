#ifndef SIMPLE_DEBUGGER_ACTIONMANAGER_H
#define SIMPLE_DEBUGGER_ACTIONMANAGER_H


#include "Action.h"

class ActionManager {
    static std::vector<ActionPtr> ACTIONS;
public:
    static void addAction(const ActionPtr &action);

    static ActionPtr getAction(const std::string &command);
};


#endif //SIMPLE_DEBUGGER_ACTIONMANAGER_H
