#include "Dimension.h"

bool Dimension::operator<(const Dimension::self &rhs) const {
    if (m_x < rhs.m_x)
        return true;
    if (rhs.m_x < m_x)
        return false;
    return m_y < rhs.m_y;
}

bool Dimension::operator>(const Dimension::self &rhs) const {
    return rhs < *this;
}

bool Dimension::operator<=(const Dimension::self &rhs) const {
    return !(rhs < *this);
}

bool Dimension::operator>=(const Dimension::self &rhs) const {
    return !(*this < rhs);
}

bool Dimension::operator==(const Dimension::self &rhs) const {
    return m_x == rhs.m_x &&
           m_y == rhs.m_y;
}

bool Dimension::operator!=(const Dimension::self &rhs) const {
    return !(rhs == *this);
}

Dimension::self &Dimension::operator+=(const Dimension::self &rhs) {
    m_x += rhs.m_x;
    return *this;
}

Dimension::self &Dimension::operator-=(const Dimension::self &rhs) {
    *this += -rhs;
    return *this;
}


Dimension::self Dimension::operator+() const {
    return *this;
}

Dimension::self Dimension::operator-() const {
    return Dimension::self{-m_x, -m_y};
}

Dimension::self Dimension::operator+(const Dimension::self &rhs) const {
    self tmp(*this);
    tmp += rhs;
    return tmp;
}

Dimension::self Dimension::operator-(const Dimension::self &rhs) const {
    return *this + -rhs;
}
