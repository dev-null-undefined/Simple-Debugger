#ifndef SIMPLE_DEBUGGER_MENU_H
#define SIMPLE_DEBUGGER_MENU_H

#include "Dimension.h"
#include "MenuManager.h"

/**
 * @brief Virtual class representing single ncurses scene/menu.
 */
class Menu {
public:

    virtual ~Menu() = default;

    virtual void show(Dimension initial_size, MenuManager &manager) = 0;

    virtual void resize(Dimension size) = 0;

    virtual void hide() = 0;

    virtual void update() = 0;

    virtual bool isCompleted() const = 0;

    virtual bool input(int input, bool &handled, MenuManager &manager) = 0;

};

#endif //SIMPLE_DEBUGGER_MENU_H
