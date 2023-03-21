#ifndef SIMPLE_DEBUGGER_BREAKPOINT_H
#define SIMPLE_DEBUGGER_BREAKPOINT_H

#include <csignal>
#include <cstdint>



class Breakpoint {
public:
    enum class State {
        ENABLED,
        DISABLED,
        TO_BE_ENABLED,
    };

    Breakpoint(pid_t pid, std::intptr_t addr) noexcept;

    void enable();
    void disable();
    void toggle();

    [[nodiscard]] bool isEnabled() const;
    [[nodiscard]] State getState() const;
    [[nodiscard]] std::intptr_t getAddress() const;

    void setPid(pid_t pid);
    [[nodiscard]] pid_t getPid() const;

    explicit operator bool() const;

    static constexpr uint8_t INT3 = 0xcc;
private:

    pid_t m_pid;
    std::intptr_t m_address;
    State m_state;
    uint8_t m_saved_data;
};


#endif //SIMPLE_DEBUGGER_BREAKPOINT_H
