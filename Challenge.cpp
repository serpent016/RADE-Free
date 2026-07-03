#include "Challenge.h"

void Challenge::Set(const std::string& name, float value) {
    aspects[name] = value;
}

float Challenge::Get(const std::string& name) const {
    auto it = aspects.find(name);
    if (it != aspects.end()) return it->second;
    return 0.0f;
}
