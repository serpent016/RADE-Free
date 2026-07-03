#include "RADELogger.h"
#include <iostream>

void RADELogger::Log(const std::string& message) {
    if (enabled) {
        std::cout << "[RADE] " << message << std::endl;
    }
}
