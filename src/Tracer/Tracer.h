#ifndef SIMPLE_DEBUGGER_TRACER_H
#define SIMPLE_DEBUGGER_TRACER_H


#include <sys/user.h>
#include <optional>
#include <iostream>
#include "../Traced/Program.h"
#include "../Registry.h"
#include "RegistryWrapper.h"

class RegisterWrapper;

class Tracer {
public:

    explicit Tracer(Program tracedProgram) noexcept;

    void run();

    RegisterWrapper getRegister(Register::Identifier registerName, bool cached = false);
    void setRegister(const RegisterWrapper &registerWrapper);

    void dumpRegisters(std::ostream &os = std::cout);
    void continueExecution();

    void setBreakpoint(std::intptr_t address);
    void removeBreakpoint(std::intptr_t address);
    void toggleBreakpoint(std::intptr_t address);
    bool hasBreakpoint(std::intptr_t address);

private:
    using self = Tracer;

    enum class State {
        Started,
        Running,
        Stopped
    };

    State m_state = State::Stopped;

    Program m_tracedProgram;

    user_regs_struct m_cached_registers;

    pid_t m_pid;

    int m_waitStatus = 0;



    void wait_for_signal();

    void stepOverBreakpoint();
};


#endif //SIMPLE_DEBUGGER_TRACER_H
