#pragma once
#include "PlayerSkill.h"
#include "Challenge.h"
#include "RADEProfile.h"
#include "RADELogger.h"

class RADEngine {
public:
    RADEProfile profile;
    RADELogger logger;

    void LoadProfile(const RADEProfile& p);
    void Update(const PlayerSkill& skill, Challenge& challenge);

private:
    float Smooth(float current, float target, float smoothing) const;
    float Clamp(float value, float min, float max) const;
};
