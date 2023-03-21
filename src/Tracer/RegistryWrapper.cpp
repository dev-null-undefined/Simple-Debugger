#include "RegistryWrapper.h"

bool RegisterWrapper::operator<(const RegisterWrapper &rhs) const {
    return m_value < rhs.m_value;
}

bool RegisterWrapper::operator>(const RegisterWrapper &rhs) const {
    return rhs < *this;
}

bool RegisterWrapper::operator<=(const RegisterWrapper &rhs) const {
    return !(rhs < *this);
}

bool RegisterWrapper::operator>=(const RegisterWrapper &rhs) const {
    return !(*this < rhs);
}

bool RegisterWrapper::operator==(const RegisterWrapper &rhs) const {
    return m_value == rhs.m_value;
}

bool RegisterWrapper::operator!=(const RegisterWrapper &rhs) const {
    return !(rhs == *this);
}


RegisterWrapper::self &RegisterWrapper::operator+=(const RegisterWrapper::self &rhs) {
    m_value += rhs.m_value;
    return *this;
}

RegisterWrapper::self &RegisterWrapper::operator-=(const RegisterWrapper::self &rhs) {
    *this += -rhs;
    return *this;
}

RegisterWrapper::self &RegisterWrapper::operator*=(const RegisterWrapper::self &rhs) {
    m_value *= rhs.m_value;
    return *this;
}

RegisterWrapper::self &RegisterWrapper::operator/=(const RegisterWrapper::self &rhs) {
    m_value /= rhs.m_value;
    return *this;
}

RegisterWrapper::self &RegisterWrapper::operator%=(const RegisterWrapper::self &rhs) {
    m_value %= rhs.m_value;
    return *this;
}

RegisterWrapper::self &RegisterWrapper::operator&=(const RegisterWrapper::self &rhs) {
    m_value &= rhs.m_value;
    return *this;
}

RegisterWrapper::self &RegisterWrapper::operator|=(const RegisterWrapper::self &rhs) {
    m_value |= rhs.m_value;
    return *this;
}

RegisterWrapper::self &RegisterWrapper::operator^=(const RegisterWrapper::self &rhs) {
    m_value ^= rhs.m_value;
    return *this;
}

RegisterWrapper::self &RegisterWrapper::operator<<=(const RegisterWrapper::self &rhs) {
    m_value <<= rhs.m_value;
    return *this;
}

RegisterWrapper::self &RegisterWrapper::operator>>=(const RegisterWrapper::self &rhs) {
    m_value >>= rhs.m_value;
    return *this;
}

RegisterWrapper::self &RegisterWrapper::operator++() {
    *this += 1;
    return *this;
}

RegisterWrapper::self &RegisterWrapper::operator--() {
    *this -= 1;
    return *this;
}

RegisterWrapper::self RegisterWrapper::operator++(int) { // NOLINT(cert-dcl21-cpp)
    RegisterWrapper tmp(*this);
    ++*this;
    return tmp;
}

RegisterWrapper::self RegisterWrapper::operator--(int) { // NOLINT(cert-dcl21-cpp)
    RegisterWrapper tmp(*this);
    --*this;
    return tmp;
}

RegisterWrapper::self RegisterWrapper::operator+() const {
    return *this;
}

RegisterWrapper::self RegisterWrapper::operator-() const {
    self tmp(*this);
    tmp.m_value = -tmp.m_value;
    return tmp;
}

RegisterWrapper::self RegisterWrapper::operator~() const {
    self tmp(*this);
    tmp.m_value = ~tmp.m_value;
    return tmp;
}

RegisterWrapper::self RegisterWrapper::operator+(const RegisterWrapper::self &rhs) const {
    self tmp(*this);
    tmp += rhs;
    return tmp;
}

RegisterWrapper::self RegisterWrapper::operator-(const RegisterWrapper::self &rhs) const {
    self tmp(*this);
    tmp -= rhs;
    return tmp;
}

RegisterWrapper::self RegisterWrapper::operator*(const RegisterWrapper::self &rhs) const {
    self tmp(*this);
    tmp *= rhs;
    return tmp;
}

RegisterWrapper::self RegisterWrapper::operator/(const RegisterWrapper::self &rhs) const {
    self tmp(*this);
    tmp /= rhs;
    return tmp;
}

RegisterWrapper::self RegisterWrapper::operator%(const RegisterWrapper::self &rhs) const {
    self tmp(*this);
    tmp %= rhs;
    return tmp;
}

RegisterWrapper::self RegisterWrapper::operator&(const RegisterWrapper::self &rhs) const {
    self tmp(*this);
    tmp &= rhs;
    return tmp;
}

RegisterWrapper::self RegisterWrapper::operator|(const RegisterWrapper::self &rhs) const {
    self tmp(*this);
    tmp |= rhs;
    return tmp;
}

RegisterWrapper::self RegisterWrapper::operator^(const RegisterWrapper::self &rhs) const {
    self tmp(*this);
    tmp ^= rhs;
    return tmp;
}

RegisterWrapper::self RegisterWrapper::operator<<(const RegisterWrapper::self &rhs) const {
    self tmp(*this);
    tmp <<= rhs;
    return tmp;
}

RegisterWrapper::self RegisterWrapper::operator>>(const RegisterWrapper::self &rhs) const {
    self tmp(*this);
    tmp >>= rhs;
    return tmp;
}

RegisterWrapper::RegisterWrapper(Register::register_value value, Register::Identifier registerName,
                                 Tracer *tracer) noexcept:
        m_value(value),
        m_register(registerName),
        m_tracer(tracer) {}

RegisterWrapper::operator Register::register_value() const {
    return getValue();
}

void RegisterWrapper::write() const {
    if (m_tracer) {
        m_tracer->setRegister(*this);
    } else {
        throw std::runtime_error("Tracer is not set");
    }
}

void RegisterWrapper::bind(Tracer *tracer) {
    m_tracer = tracer;
}

void RegisterWrapper::print(std::ostream &os) const {
    os << m_register << " 0x" << std::setfill('0') << std::setw(16) << std::hex << m_value;
}

Register::Identifier RegisterWrapper::getRegisterName() const {
    return m_register;
}

Register::register_value RegisterWrapper::getValue() const {
    return m_value;
}

Register::register_value RegisterWrapper::operator*() const {
    return getValue();
}
