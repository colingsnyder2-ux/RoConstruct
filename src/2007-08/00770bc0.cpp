// from server: 100% by Yeetserama
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lang: cpp
// roc-lib: rbxgs roc_unit_resolution_3.cpp

// Candidate translation unit (score above; library headers required).
#include "v8datamodel/DebugSettings.h"
#include <string>

static RBX::Reflection::PropDescriptor<RBX::DebugSettings, std::string> prop_cpu("cpu", "Profile", &RBX::DebugSettings::cpu, NULL, RBX::Reflection::PropertyDescriptor::STANDARD);
static RBX::Reflection::PropDescriptor<RBX::DebugSettings, int> prop_ram("ram", "Profile", &RBX::DebugSettings::ram, NULL, RBX::Reflection::PropertyDescriptor::STANDARD);
static RBX::Reflection::PropDescriptor<RBX::DebugSettings, std::string> prop_resolution("resolution", "Profile", &RBX::DebugSettings::resolution, NULL, RBX::Reflection::PropertyDescriptor::STANDARD);
