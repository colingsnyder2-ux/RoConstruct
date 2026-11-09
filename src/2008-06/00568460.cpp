// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_espeon_settingsprivatecallere764b97e6cf69938.cpp

// Candidate translation unit (score above; library headers required).
#define _CPPUNWIND 1
#include "util/FileSystem.h"
static __declspec(noinline) std::string settingsFile(){std::string result=RBX::FileSystem::getUserAppDataDirectory(true,0);if(result.length()>0)result.append("\\GlobalSettings7.xml");return result;}

extern void consumeSettingsPath(const std::string&);
void readSettingsPath(){consumeSettingsPath(settingsFile());}
