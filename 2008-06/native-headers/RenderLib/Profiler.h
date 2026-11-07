#pragma once
// >>> native-status (generated) -- do not edit >>>
// Profiler | 2008-06 | inactive
// unmapped (no binary link) | unmapped (no binary link) | by -
// <<< native-status | src d03e4358 | roc native-status --write
#include <string>

namespace RBX { namespace Render {
struct SpecData {
    const float shaderModel;
    const int videoMemory;
    const int CPUSpeed;
    const int CPUCount;
    const std::string glVendor;
    const std::string gfxcard;
    const std::string cpu;
    const int ram;
    const std::string resolution;

    static bool glLoaded;
    SpecData();
};
} }
