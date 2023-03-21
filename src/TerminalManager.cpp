#include "TerminalManager.h"
#include <ncurses.h>

Dimension TerminalManager::getTerminalSize() {
    size_t x, y;
    getmaxyx(stdscr, y, x);
    return {x, y};
}
