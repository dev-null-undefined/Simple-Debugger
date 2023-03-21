#include "HistoryRecord.h"

std::istream &operator>>(std::istream &in, HistoryRecord &record) {
    record.read(in);
    return in;
}

std::ostream &operator<<(std::ostream &os, const HistoryRecord &record) {
    record.write(os);
    return os;
}

void HistoryRecord::read(std::istream &in) {
    std::string time;
    in >> time >> m_command;
    try {
        m_time = std::chrono::system_clock::from_time_t(std::stol(time));
    } catch (...) {
        m_time = std::chrono::system_clock::now();
        in.setstate(std::ios_base::failbit);
    }
}

void HistoryRecord::write(std::ostream &os) const {
    os << std::chrono::system_clock::to_time_t(m_time) << " " << m_command;
}

HistoryRecord::HistoryRecord(std::string command, std::chrono::time_point<std::chrono::system_clock> time) : m_command(
        std::move(command)), m_time(time) {}
