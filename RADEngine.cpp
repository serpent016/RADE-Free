#include "RADEEngine.h"
#include <sstream>

void RADEEngine::LoadProfile(const RADEProfile& p) {
    profile = p;
}

float RADEEngine::Smooth(float current, float target, float smoothing) const {
    return current + (target - current) * smoothing;
}

float RADEEngine::Clamp(float value, float min, float max) const {
    if (value < min) return min;
    if (value > max) return max;
    return value;
}

void RADEEngine::Update(const PlayerSkill& skill, Challenge& challenge) {
    for (const auto& skillEntry : profile.links) {
        const std::string& skillName = skillEntry.first;
        float skillValue = skill.Get(skillName);

        for (const auto& challengeEntry : skillEntry.second) {
            const std::string& challengeName = challengeEntry.first;
            float multiplier = challengeEntry.second;

            float current = challenge.Get(challengeName);
            float target = current + skillValue * multiplier;

            float smoothed = Smooth(current, target, profile.smoothing);
            float clamped = Clamp(smoothed, profile.clampMin, profile.clampMax);

            challenge.Set(challengeName, clamped);

            std::ostringstream oss;
            oss << "Skill '" << skillName << "' (" << skillValue
                << ") -> Challenge '" << challengeName
                << "' updated to " << clamped;
            logger.Log(oss.str());
        }
    }
}
