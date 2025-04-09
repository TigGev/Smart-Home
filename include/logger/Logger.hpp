#ifndef LOGGER_HPP
#define LOGGER_HPP
#include <string>

class Logger {
    public:
        ~Logger() = default;
        void log(const std::string& message);
};

#endif