#include "MainMenu.h"
#include "Debugger/Debugger.h"

void MainMenu::show(Dimension initial_size, MenuManager &manager) {
    manager.pushMenu(std::make_shared<Debugger>());
    m_shown = true;
}

void MainMenu::resize(Dimension size) {

}

void MainMenu::hide() {

}

void MainMenu::update() {

}

bool MainMenu::isCompleted() const {
    return m_shown;
}

bool MainMenu::input(int input, bool &handled, MenuManager &manager) {
    return false;
}
