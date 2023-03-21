#ifndef SIMPLE_DEBUGGER_REGISTRYWRAPPER_H
#define SIMPLE_DEBUGGER_REGISTRYWRAPPER_H


#include "../Registry.h"
#include "Tracer.h"

class Tracer;

class RegisterWrapper {
    using self = RegisterWrapper;
    Register::register_value m_value;
    Register::Identifier m_register;

    Tracer *m_tracer = nullptr;
public:

    RegisterWrapper(Register::register_value value, Register::Identifier registerName = Register::Identifier::rax,
                    Tracer *tracer = nullptr) noexcept; // NOLINT(google-explicit-constructor)
    void write() const;


    void bind(Tracer *tracer);

    void print(std::ostream &os) const;

    [[nodiscard]] Register::Identifier getRegisterName() const;

    explicit operator Register::register_value() const;

    [[nodiscard]] Register::register_value getValue() const;

    [[nodiscard]] Register::register_value operator*() const;

    self &operator+=(const self &rhs);

    self &operator-=(const self &rhs);

    self &operator*=(const self &rhs);

    self &operator/=(const self &rhs);

    self &operator%=(const self &rhs);

    self &operator&=(const self &rhs);

    self &operator|=(const self &rhs);

    self &operator^=(const self &rhs);

    self &operator<<=(const self &rhs);

    self &operator>>=(const self &rhs);

    self &operator++();

    self &operator--();

    self operator++(int); // NOLINT(cert-dcl21-cpp)
    self operator--(int); // NOLINT(cert-dcl21-cpp)

    self operator+() const;

    self operator-() const;

    self operator~() const;

    self operator+(const self &rhs) const;

    self operator-(const self &rhs) const;

    self operator*(const self &rhs) const;

    self operator/(const self &rhs) const;

    self operator%(const self &rhs) const;

    self operator&(const self &rhs) const;

    self operator|(const self &rhs) const;

    self operator^(const self &rhs) const;

    self operator<<(const self &rhs) const;

    self operator>>(const self &rhs) const;

    bool operator==(const self &rhs) const;

    bool operator!=(const self &rhs) const;

    bool operator<(const self &rhs) const;

    bool operator>(const self &rhs) const;

    bool operator<=(const self &rhs) const;

    bool operator>=(const self &rhs) const;
};

std::ostream &operator<<(std::ostream &os, const RegisterWrapper &registerWrapper);


#endif //SIMPLE_DEBUGGER_REGISTRYWRAPPER_H
