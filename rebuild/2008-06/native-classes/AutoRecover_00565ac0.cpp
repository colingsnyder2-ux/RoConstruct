// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// 00565ac0: 2008 RBX::DebugSettings ctor. Base GlobalSettingsItem ctor (005655b0) runs first,
// then vtables are set, then the members, then setName("Diagnostics") (0055af90).
#include "v8datamodel/DebugSettings.h"
#include <string>

namespace RBX
{
	DebugSettings::DebugSettings()
		: stackTracingEnabled(true), ioEnabled(false), soundWarnings(false), errorReporting(Prompt) // +0x130/+0x131/+0x133/+0x134
	{
		setName("Diagnostics");
	}
}
