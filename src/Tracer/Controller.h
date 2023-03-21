#ifndef SIMPLE_DEBUGGER_CONTROLLER_H
#define SIMPLE_DEBUGGER_CONTROLLER_H


#include "Tracer.h"
class Action;
using ActionPtr = std::shared_ptr<Action>;

class Controller {
    static std::vector<ActionPtr> m_actions;
    std::vector<std::string> m_history;
    std::optional<Tracer> m_tracer;

    static ActionPtr getAction(const std::string &command);
public:
    static void addAction(const ActionPtr& action);

    Tracer &getTracer();
    void setTracer(Tracer &&tracer);
    void start();
};


#endif //SIMPLE_DEBUGGER_CONTROLLER_H
