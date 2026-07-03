#pragma once
#include <unordered_map>
#include <string>

class Challenge {
public:
    void Set(const std::string& name, float value);
    float Get(const std::string& name) const;

private:
    std::unordered_map<std::string, float> aspects;
};
