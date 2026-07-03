RADE — Real-Time Adaptive Difficulty Engine (Free Version)
RADE is a lightweight C++ library that automatically adjusts game difficulty based on player performance.
It uses player skills, challenge variables, smoothing, clamping, and JSON profiles to make difficulty changes feel natural and predictable.

Features
Track player skills (reaction, accuracy, survival time, etc.)

Adjust challenge variables (speed, gap size, complexity)

Smooth difficulty changes to prevent spikes

Clamp values to safe ranges

Load difficulty profiles from JSON

Simple logging for debugging

Works with any C++ game engine or framework

Installation
Add the RADE folder to your project.

Include the headers:

cpp
#include "RADEngine.h"
#include "PlayerSkill.h"
#include "Challenge.h"
#include "RADEProfile.h"
Add json.hpp to your include path.

Compile normally — RADE is lightweight and engine‑agnostic.

Example
cpp
PlayerSkill skill;
Challenge challenge;
RADEngine rade;
RADEProfile profile;

profile.LoadFromJSON("easy.json");
rade.LoadProfile(profile);

skill.Set("reaction", 0.8f);
challenge.Set("speed", 1.0f);

rade.Update(skill, challenge);

float speed = challenge.Get("speed");
JSON Example
json
{
  "smoothing": 0.4,
  "clampMin": 0.5,
  "clampMax": 2.0,
  "links": {
    "reaction": { "speed": 0.05 }
  }
}
License
MIT License (Free Version)
