// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// 2008-06 native CRobloxWnd::CRobloxWnd(int) 0045c730 (inactive; File->New builds one inside every CRobloxView).
// Evidence: CWnd ctor, the IRunView/IMetric vtable stores (implicit), zeroed slots 0x64..0x7c, flag 0x80 = 1, double at 0x90 from
// the constant 666.0 (008199d0), byte 0x88 = the argument, 0x89/0x8a = 0, 0x8b = 1, a 0xc048-byte CodeProfiler("Render") at
// 0x98, zeroed render-device slots 0x9c..0xb8, then the render mode: startup mode 0096d358 (taken from CRenderSettings +0x130
// when still unset) stored at 0x5c, with mode 1 mapped to 3.
#include "CRobloxView.h"
#include "../native-headers/CRenderSettings.h"
#include "util/Profiling.h"

extern int nativeStartupMode;   // 0096d358

CRobloxWnd::CRobloxWnd(int arg)
{
	slots_64_6b[0] = 0;
	slots_64_6b[1] = 0;
	dataModel = 0;
	slot_78 = 0;
	slot_7c = 0;
	flag_80 = true;
	userInput = 0;
	pendingThrottle = 666.0;
	flags_88_8b[0] = static_cast<unsigned char>(arg);
	flags_88_8b[1] = false;
	flags_88_8b[2] = false;
	flags_88_8b[3] = true;
	source_98 = new RBX::Profiling::CodeProfiler("Render");
	flag_9c = false;
	slot_a0 = 0;
	adorn = 0;
	flag_a8 = false;
	renderDevice = 0;
	slot_b0 = 0;
	slot_b4 = 0;
	visualEngine = 0;
	retries_60 = 0;
	CRenderSettings& settings = CRenderSettings::singleton();
	if (!nativeStartupMode)
		nativeStartupMode = settings.graphicsMode;
	mode_5c = nativeStartupMode;
	if (mode_5c == 1)
		mode_5c = 3;
}
