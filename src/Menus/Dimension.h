#ifndef SIMPLE_DEBUGGER_DIMENSION_H
#define SIMPLE_DEBUGGER_DIMENSION_H


#include <cstdlib>

struct Dimension {
    using self = Dimension;
    int m_x;
    int m_y;

    self &operator+=(const self &rhs);

    self &operator-=(const self &rhs);

    self operator+() const;

    self operator-() const;

    self operator+(const self &rhs) const;

    self operator-(const self &rhs) const;

    bool operator==(const self &rhs) const;

    bool operator!=(const self &rhs) const;

    bool operator<(const self &rhs) const;

    bool operator>(const self &rhs) const;

    bool operator<=(const self &rhs) const;

    bool operator>=(const self &rhs) const;
};


#endif //SIMPLE_DEBUGGER_DIMENSION_H
