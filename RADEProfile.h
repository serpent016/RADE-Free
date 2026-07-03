#pragma once
#include <string>
#include <unordered_map>
#include "json.hpp"  // nlohmann::json

class RADEProfile {
public:
    bool LoadFromJSON(const std::string& path);

    float smoothing = 0.4f;
    float clampMin = 0.5f;
    float clampMax = 2.0f;

    // links[skillName][challengeName] = multiplier
    std::unordered_map<std::string,
        std::unordered_map<std::string, float>> links;

private:
    using json = nlohmann::json;
};
