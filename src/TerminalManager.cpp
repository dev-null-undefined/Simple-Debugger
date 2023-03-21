#include "TerminalManager.h"
#include <ncurses.h>

Dimension TerminalManager::getTerminalSize() {
    int x, y;
    getmaxyx(stdscr, y, x);
    return {x, y};
}
