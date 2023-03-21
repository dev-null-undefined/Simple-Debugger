#include <sys/ptrace.h>
#include <cassert>
#include <ranges>
#include <sys/wait.h>
#include "Tracer.h"

Tracer::Tracer(Program tracedProgram) noexcept: m_tracedProgram(std::move(tracedProgram)) {}

void Tracer::run() {
    m_state = State::Started;
    m_tracedProgram.run();
    m_pid = m_tracedProgram.getPid();
    wait_for_signal();
    m_state = State::Running;
    m_tracedProgram.checkBreakpoints(m_pid);
}

RegisterWrapper Tracer::getRegister(Register::Identifier registerName, bool cached) {
    if (!cached) {
        ptrace(PTRACE_GETREGS, m_tracedProgram.getPid(), nullptr, &m_cached_registers);
    }
    return {getRegisterReference(m_cached_registers, registerName), registerName, this};
}

void Tracer::setRegister(const RegisterWrapper &registerWrapper) {
    ptrace(PTRACE_GETREGS, m_tracedProgram.getPid(), nullptr, &m_cached_registers);
    getRegisterReference(m_cached_registers, registerWrapper.getRegisterName()) = *registerWrapper;
    ptrace(PTRACE_SETREGS, m_tracedProgram.getPid(), nullptr, &m_cached_registers);
}

void Tracer::dumpRegisters(std::ostream &os) {
    bool first = true;
    for (auto registerName: Register::ALL_REGISTERS) {
        auto reg = getRegister(registerName.identifier, !first);
        first = false;
        os << reg << std::endl;
    }
}

void Tracer::stepOverBreakpoint() {
    auto rip = getRegister(Register::Identifier::rip);
    --rip;
    auto ripValue = (std::intptr_t)*rip;
    if(m_tracedProgram.hasBreakpoint(ripValue)) {
        auto breakpoint = m_tracedProgram.getBreakpoint(ripValue);
        if(breakpoint) {
            std::cout << "Stepping over breakpoint at " << std::hex << ripValue << std::endl;
            breakpoint.disable();
            setRegister(rip);
            ptrace(PTRACE_SINGLESTEP, m_tracedProgram.getPid(), nullptr, nullptr);
            wait_for_signal();
            breakpoint.enable();
        }
    }
}

void Tracer::continueExecution() {
    stepOverBreakpoint();
    ptrace(PTRACE_CONT, m_tracedProgram.getPid(), nullptr, nullptr);
    wait_for_signal();
}

void Tracer::wait_for_signal() {
    auto options = 0;
    waitpid(m_pid, &m_waitStatus, options);
}

void Tracer::setBreakpoint(std::intptr_t address) {
    m_tracedProgram.setBreakpoint(address);
}

void Tracer::removeBreakpoint(std::intptr_t address) {
    m_tracedProgram.removeBreakpoint(address);

}

void Tracer::toggleBreakpoint(std::intptr_t address) {
    auto breakpoint = m_tracedProgram.getBreakpoint(address);
    breakpoint.toggle();
}

bool Tracer::hasBreakpoint(std::intptr_t address) {
    return m_tracedProgram.hasBreakpoint(address);
}

std::ostream &operator<<(std::ostream &os, const RegisterWrapper &registerWrapper) {
    registerWrapper.print(os);
    return os;
}
