#include "Debugger.h"
#include "../../../TerminalManager.h"
#include "ActionManager.h"
#include "../../../Algorithms.h"
#include "Actions/RegisterActions.h"

void Debugger::show(Dimension initial_size, MenuManager &manager) {
    curs_set(1);
    initscr();
    noecho();
    cbreak();
    keypad(stdscr, TRUE);
    m_window = newwin((int) initial_size.m_y, (int) initial_size.m_x, 0, 0);
    m_windowSize = initial_size - Dimension{2, 2};

    refresh();
    box(m_window, 0, 0);
    wrefresh(m_window);
    update();
}

void Debugger::resize(Dimension size) {

}

void Debugger::hide() {
    delwin(m_window);
    m_window = nullptr;
}

Tracer &Debugger::getTracer() {
    return *m_tracer;
}

void Debugger::setTracer(Tracer &&tracer) {
    m_tracer = std::move(tracer);
}

void Debugger::update() {
    wclear(m_window);
    box(m_window, 0, 0);
    wrefresh(m_window);
    std::vector<std::string> splitCommand = split(m_command, " ");
    auto action = ActionManager::getAction(splitCommand[0]);
    if ((action != nullptr && action->isShortcut()) || m_commandCompleted) {
        m_history.add(m_command);
        if (action == nullptr) {
            TerminalManager::print("Unknown command: " + m_command, m_window, {1, 1});
        } else {
            action->execute(*this, splitCommand);
        }
        m_command = "";
        m_commandCompleted = false;
    } else {
        TerminalManager::print(m_command, m_window, {1, 1});
    }
}

bool Debugger::input(int input, bool &handled, MenuManager &manager) {
    if (std::isprint(input) || std::isspace(input)) {
        if (input == '\r' || input == '\n') {
            m_commandCompleted = true;
        } else {
            m_command += (char) input;
        }
        handled = true;
        return true;
    }
    if (input == KEY_BACKSPACE || input == 127 || input == '\b') {
        if (!m_command.empty()) {
            m_command.pop_back();
        }
        handled = true;
        return true;
    }

    if (input >= 1 && input <= 26) {
        m_command += '^';
        m_command += (char) (input + 'a' - 1);
        handled = true;
        return true;
    }
    return false;
}

bool Debugger::isCompleted() const {
    return false;
}

Debugger::Debugger() {
    registerActions();
}

void Debugger::printLines(const std::vector<std::string> &lines) {
    for (int i = 0; i < lines.size() && i < m_windowSize.m_y - 2; ++i) {
        TerminalManager::print(lines[i], m_window, {1, i + 1});
    }
}
