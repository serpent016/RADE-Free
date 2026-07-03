#pragma once
#include <string>

class RADELogger {
public:
    bool enabled = false;

    void Log(const std::string& message);
};
