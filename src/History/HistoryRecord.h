#ifndef SIMPLE_DEBUGGER_HISTORYRECORD_H
#define SIMPLE_DEBUGGER_HISTORYRECORD_H


#include <string>
#include <chrono>

struct HistoryRecord {
    HistoryRecord(std::string command = "",
                  std::chrono::time_point<std::chrono::system_clock> time = std::chrono::system_clock::now());

    std::string m_command;
    std::chrono::time_point<std::chrono::system_clock> m_time;

    void read(std::istream &in);

    void write(std::ostream &os) const;
};

std::istream &operator>>(std::istream &in, HistoryRecord &record);

std::ostream &operator<<(std::ostream &os, const HistoryRecord &record);

#endif //SIMPLE_DEBUGGER_HISTORYRECORD_H
