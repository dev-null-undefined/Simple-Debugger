#include "TerminalManager.h"
#include <ncurses.h>
#include <iostream>

Dimension TerminalManager::getTerminalSize() {
    int x, y;
    getmaxyx(stdscr, y, x);
    std::cerr << "Terminal size: " << x << ", " << y << std::endl;
    return {x, y};
}

void TerminalManager::print(const std::string &text, WINDOW *window, Dimension dimension) {
    std::cerr << "Printing " << text << " at " << dimension.m_x << ", " << dimension.m_y << std::endl;
    mvwprintw(window, dimension.m_y, dimension.m_x, "%s", text.c_str());
    wrefresh(window);
}
