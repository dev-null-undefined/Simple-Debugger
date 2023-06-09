#ifndef SIMPLE_DEBUGGER_ALGORITHMS_H
#define SIMPLE_DEBUGGER_ALGORITHMS_H

#include <string>
#include <vector>

std::vector<std::string> split(const std::string &s, const std::string &delim);

bool hasPrefix(const std::string &s, const std::string &prefix);

double levenshteinDistance(const std::string &s1, const std::string &s2);

#endif //SIMPLE_DEBUGGER_ALGORITHMS_H
