#include "RADEProfile.h"
#include <fstream>

bool RADEProfile::LoadFromJSON(const std::string& path) {
    std::ifstream file(path);
    if (!file.is_open()) return false;

    json j;
    file >> j;

    if (j.contains("smoothing"))  smoothing = j["smoothing"].get<float>();
    if (j.contains("clampMin"))   clampMin = j["clampMin"].get<float>();
    if (j.contains("clampMax"))   clampMax = j["clampMax"].get<float>();

    if (j.contains("links")) {
        for (auto& [skillName, challengeMap] : j["links"].items()) {
            for (auto& [challengeName, multiplier] : challengeMap.items()) {
                links[skillName][challengeName] = multiplier.get<float>();
            }
        }
    }

    return true;
}
