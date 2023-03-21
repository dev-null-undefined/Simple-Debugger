#ifndef SIMPLE_DEBUGGER_TERMINALMANAGER_H
#define SIMPLE_DEBUGGER_TERMINALMANAGER_H

#include <optional>
#include <string>
#include "Menus/Dimension.h"

class TerminalManager {
public:
    static Dimension getTerminalSize();

    static constexpr int CTRL_MASK = 0x1F;
};


#endif //SIMPLE_DEBUGGER_TERMINALMANAGER_H
