#pragma once
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
