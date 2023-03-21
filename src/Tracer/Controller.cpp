#include <string>
#include <iostream>
#include <vector>
#include <ranges>
#include <ncurses.h>
#include "Controller.h"
#include "../Menus/Menus/MainMenu.h"

void Controller::start() {
    m_menus.pushMenu(std::make_shared<MainMenu>());
    inputLoop();
}

void Controller::inputLoop() {
    while (true) {
        flushinp();
        auto currentMenu = m_menus.getCurrentMenu();
        if (currentMenu == nullptr) {
            break;
        }
        int input = getch();
        if (input == KEY_RESIZE) {
            currentMenu->resize(getResolution());
            currentMenu->update();
            continue;
        }
        if (input == ERR) {
            continue;
        }
        if (input == 4) {
            break;
        }
        auto menu = m_menus.propagateInput(input);
        if (menu != nullptr) {
            m_menus.update(menu);
        }
    }
}

Dimension Controller::getResolution() {
    size_t x, y;
    getmaxyx(stdscr, y, x);
    return {x, y};
}
