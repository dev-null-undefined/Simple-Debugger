#ifndef SIMPLE_DEBUGGER_MAINMENU_H
#define SIMPLE_DEBUGGER_MAINMENU_H


#include "../Menu.h"

class MainMenu: public Menu{
    bool m_shown = false;
public:
    void show(Dimension initial_size, MenuManager &manager) override;

    void resize(Dimension size) override;

    void hide() override;

    void update() override;

    bool isCompleted() const override;

    bool input(int input, bool &handled, MenuManager &manager) override;
};


#endif //SIMPLE_DEBUGGER_MAINMENU_H
