#include <sys/ptrace.h>
#include <stdexcept>
#include <iostream>
#include <ios>
#include "Breakpoint.h"

Breakpoint::Breakpoint(pid_t pid, std::intptr_t address) noexcept: m_pid{pid}, m_address{address},
                                                                   m_state{State::DISABLED},
                                                                   m_saved_data{} {
}

void Breakpoint::enable() {
    if (!m_pid) {
        m_state = State::TO_BE_ENABLED;
        return;
    }
    if (m_state == State::ENABLED) {
        return;
    }
    auto data = ptrace(PTRACE_PEEKDATA, m_pid, m_address, nullptr);
    m_saved_data = static_cast<uint8_t>(data & 0xff);
    uint64_t data_with_int3 = ((data & ~0xff) | INT3);
    ptrace(PTRACE_POKEDATA, m_pid, m_address, data_with_int3);
    m_state = State::ENABLED;
}

void Breakpoint::disable() {
    if (m_state == State::ENABLED) {
        auto data = ptrace(PTRACE_PEEKDATA, m_pid, m_address, nullptr);
        auto restored_data = ((data & ~0xff) | m_saved_data);
        ptrace(PTRACE_POKEDATA, m_pid, m_address, restored_data);
        std::cout << "Breakpoint at " << std::hex << m_address << " disabled, restored data" << std::hex
                  << restored_data << std::endl;
    }
    m_state = State::DISABLED;
}


bool Breakpoint::isEnabled() const {
    std::cout << "Breakpoint at " << std::hex << m_address << " is "
              << (m_state == State::ENABLED ? "enabled" : "disabled") << std::endl;
    return m_state == State::ENABLED;
}

std::intptr_t Breakpoint::getAddress() const {
    return m_address;
}

Breakpoint::operator bool() const {
    return isEnabled();
}

void Breakpoint::toggle() {
    if (isEnabled()) {
        disable();
    } else {
        enable();
    }
}

pid_t Breakpoint::getPid() const {
    return m_pid;
}

void Breakpoint::setPid(pid_t pid) {
    if (m_state == State::TO_BE_ENABLED) {
        m_pid = pid;
        enable();
    }
}

Breakpoint::State Breakpoint::getState() const {
    return m_state;
}
