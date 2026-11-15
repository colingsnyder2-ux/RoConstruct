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
