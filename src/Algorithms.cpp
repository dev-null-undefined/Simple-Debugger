#include "Algorithms.h"
#include <algorithm>
#include <iostream>
#include <iomanip>

std::vector<std::string> split(const std::string &s, const std::string &delim) {
    size_t pos_start = 0, pos_end, delim_len = delim.length();
    std::string token;
    std::vector<std::string> res;
    while ((pos_end = s.find(delim, pos_start)) != std::string::npos) {
        token = s.substr(pos_start, pos_end - pos_start);
        pos_start = pos_end + delim_len;
        res.push_back(token);
    }
    res.push_back(s.substr(pos_start));
    return res;
}

bool hasPrefix(const std::string &s, const std::string &prefix) {
    return s.find(prefix) == 0;
}

struct Matrix {
    size_t N;
    size_t M;
    double *data;

    Matrix(size_t n, size_t m) : N(n), M(m), data(new double[n * m]{}) {}

    Matrix(const Matrix &) = delete;

    Matrix &operator=(const Matrix &) = delete;

    ~Matrix() {
        delete[] data;
    }

    double &operator()(size_t i, size_t j) {
        return data[i * N + j];
    }
};

double levenshteinDistance(const std::string &s1, const std::string &s2) {
    size_t n = s1.size() + 1;
    size_t m = s2.size() + 1;
    Matrix d(n, m);
    for (size_t i = 0, im = 0; i < m; ++i, ++im) {
        for (size_t j = 0, jn = 0; j < n; ++j, ++jn) {
            if (i == 0)
                d(i, j) = j * 0.5;
            else if (j == 0)
                d(i, j) = i * 0.5;
            else
                d(i, j) = 0;
        }
    }
    for (size_t i = 1, im = 0; i < m; ++i, ++im) {
        for (size_t j = 1, jn = 0; j < n; ++j, ++jn) {
            if (s1[jn] == s2[im]) {
                d(i, j) = d(i - 1, j - 1);
            } else {
                double distance = std::tolower(s1[jn]) == std::tolower(s2[im]) ? 0.75 : 1;
                d(i, j) = std::min({d(i - 1, j) + 0.5, /* A deletion. */
                                    d(i, j - 1) + 0.5, /* An insertion. */
                                    d(i - 1, j - 1) + distance}); /* A substitution. */
            }
        }
    }

#ifdef DEBUG
    for (size_t i = 0; i < m; ++i) {
        for (size_t j = 0; j < n; ++j) {
            std::cout << std::setw(4) << d(i, j) << " ";
        }
        std::cout << std::endl;
    }
#endif

    return d(n, m);
}
