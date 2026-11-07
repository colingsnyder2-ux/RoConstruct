#pragma once
// >>> native-status (generated) -- do not edit >>>
// AuthoringSettings | 2008-06 | inactive
// unmapped (no binary link) | unmapped (no binary link) | by -
// <<< native-status | src 64e4ec9a | roc native-status --write
#include "v8datamodel/GlobalSettings.h"

// Inactive layout recovery. RTTI .?AVAuthoringSettings@@ (global namespace) via
// GlobalSettingsItem<AuthoringSettings, sAuthoringSettings>. Creatable<Instance>::create 0040d410
// allocates 0x134; constructor 0040d140 stores +0x130=0 and +0x131=1. Bound bool properties
// "ShowDepricatedObjects" (+0x130, spelled so in the binary) and "ShowPreliminaryObjects" (+0x131),
// category "Browsing", from dynamic initializers 007ee980/007ee950. The binary's ClassName
// parameter is const char* const*; the shared donor templates take const char** (mangling only).
extern char sAuthoringSettings[];
class AuthoringSettings : public RBX::GlobalSettingsItem<AuthoringSettings, sAuthoringSettings> {
public:
    bool showDepricatedObjects;
    bool showPreliminaryObjects;
    AuthoringSettings();
    ~AuthoringSettings() {}
};
