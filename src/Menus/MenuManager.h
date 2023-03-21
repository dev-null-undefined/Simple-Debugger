#ifndef SIMPLE_DEBUGGER_MENUMANAGER_H
#define SIMPLE_DEBUGGER_MENUMANAGER_H

#include <memory>
#include <list>

struct Menu;

class MenuManager {
    std::list<std::shared_ptr<Menu>> m_menuStack;
public:
    void pushMenu(const std::shared_ptr<Menu> &menu);

    std::shared_ptr<Menu> getCurrentMenu();

    std::shared_ptr<Menu> propagateInput(int input);

    void update(const std::shared_ptr<Menu> &until);
};


#endif //SIMPLE_DEBUGGER_MENUMANAGER_H
