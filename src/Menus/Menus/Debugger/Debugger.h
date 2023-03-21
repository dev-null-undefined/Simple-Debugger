#ifndef SIMPLE_DEBUGGER_DEBUGGER_H
#define SIMPLE_DEBUGGER_DEBUGGER_H


#include <ncurses.h>
#include "../../Menu.h"
#include "../../../Tracer/Tracer.h"
#include "../../../History/HistoryManager.h"

class Debugger : public Menu {

public:
    Debugger();

    void show(Dimension initial_size, MenuManager &manager) override;

    void resize(Dimension size) override;

    void hide() override;

    void update() override;

    [[nodiscard]] bool isCompleted() const override;

    bool input(int input, bool &handled, MenuManager & manager) override;


    Tracer &getTracer();

    void setTracer(Tracer &&tracer);
private:

    std::optional<Tracer> m_tracer;
    std::string m_command;
    bool m_commandCompleted = false;
    WINDOW * m_window = nullptr;
    Dimension m_windowSize;
    HistoryManager m_history;

};

#endif //SIMPLE_DEBUGGER_DEBUGGER_H
