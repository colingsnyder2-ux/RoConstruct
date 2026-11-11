// >>> native-status (generated) -- do not edit >>>
// DebugSettingsSpecData | 2008-06 | draft (no current byte proof)
// no original address mapped to this file yet | by -
// <<< native-status | src 8f0191ae | roc native-status --write
#include "v8datamodel/DebugSettings.h"
#include "RenderLib/Profiler.h"

namespace RBX {
int DebugSettings::videoMemory() const { return Render::SpecData().videoMemory; }
int DebugSettings::cpuSpeed() const { return Render::SpecData().CPUSpeed; }
int DebugSettings::cpuCount() const { return Render::SpecData().CPUCount; }
int DebugSettings::ram() const { return Render::SpecData().ram; }
float DebugSettings::shaderModel() const { return Render::SpecData().shaderModel; }
std::string DebugSettings::glVendor() const { return Render::SpecData().glVendor; }
std::string DebugSettings::cpu() const { return Render::SpecData().cpu; }
std::string DebugSettings::resolution() const { return Render::SpecData().resolution; }
}
