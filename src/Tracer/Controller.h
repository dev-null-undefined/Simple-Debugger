#ifndef SIMPLE_DEBUGGER_CONTROLLER_H
#define SIMPLE_DEBUGGER_CONTROLLER_H


#include "Tracer.h"
#include "../TerminalManager.h"
#include "../History/HistoryManager.h"
#include "../Menus/Menu.h"
#include "../Menus/MenuManager.h"

class Action;

using ActionPtr = std::shared_ptr<Action>;

class Controller {
    MenuManager m_menus;

    static Dimension getResolution();

    void inputLoop();

public:
    void start();
};


#endif //SIMPLE_DEBUGGER_CONTROLLER_H
