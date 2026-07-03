#include "PlayerSkill.h"

void PlayerSkill::Set(const std::string& name, float value) {
    skills[name] = value;
}

float PlayerSkill::Get(const std::string& name) const {
    auto it = skills.find(name);
    if (it != skills.end()) return it->second;
    return 0.0f;
}
