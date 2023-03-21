#include <ranges>
#include "Menu.h"
#include "MenuManager.h"
#include "../TerminalManager.h"

std::shared_ptr<Menu> MenuManager::getCurrentMenu() {
    while(!m_menuStack.empty() && m_menuStack.back()->isCompleted()){
        m_menuStack.back()->hide();
        m_menuStack.pop_back();
    }
    if(!m_menuStack.empty()) {
        return m_menuStack.back();
    }
    return nullptr;
}

void MenuManager::pushMenu(const std::shared_ptr<Menu> &menu) {
    m_menuStack.push_back(menu);
    auto current = getCurrentMenu();
    if(current != nullptr){
        current->show(TerminalManager::getTerminalSize(), *this);
    }
}

std::shared_ptr<Menu> MenuManager::propagateInput(int input) {
    bool handled = false;
    std::shared_ptr<Menu> lastUpdated = nullptr;
    for(auto &menu : m_menuStack | std::views::reverse){
        if(menu->input(input, handled, *this)){
            lastUpdated = menu;
        }
        if(handled) {
            return lastUpdated;
        }
    }
    return lastUpdated;
}

void MenuManager::update(const std::shared_ptr<Menu> &until) {
    for(auto &menu : m_menuStack | std::views::reverse){
        menu->update();
        if(menu == until){
            break;
        }
    }
}
