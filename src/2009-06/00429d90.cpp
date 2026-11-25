// from server: 100% by colin
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: templates-boost-1_34_1 roc_manual_mainframe_0fe43c76eb69f1fe.cpp

// Candidate translation unit (score above; library headers required).
#define NDEBUG
#define _MBCS
#include <windows.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <boost/shared_ptr.hpp>
namespace RBX { struct StandardOut; }
boost::shared_ptr<RBX::StandardOut> rocStandardOutSingleton();
void rocStandardOutPrint(RBX::StandardOut* out, int type, const char* format, ...);
// 00430bf0 (2008-06) / 00429d90 (2009-06): the volatile result parameter copied into a const pointer at entry
// reproduces the original early `mov ebx,[ebp+8]` return-slot load (same ABI as returning DEVMODEA by value).
DEVMODEA* findDisplayMode(DEVMODEA* volatile result, const char* deviceName, int pixels)
{
    DEVMODEA* const pbest = result;
#define best (*pbest)
    DEVMODEA mode;
    memset(&mode, 0, sizeof(mode));
    mode.dmSize = sizeof(DEVMODEA);
    if (!EnumDisplaySettingsExA(deviceName, ENUM_CURRENT_SETTINGS, &mode, 0))
        rocStandardOutPrint(rocStandardOutSingleton().get(), 3, "EnumDisplaySettings failed. GetLastError() == %d", GetLastError());
    double aspect = (double)mode.dmPelsWidth / (double)mode.dmPelsHeight;
    best = mode;
    DWORD i = 0;
    while (EnumDisplaySettingsExA(deviceName, i, &mode, 0)) {
        ++i;
        if (fabs(aspect - (double)mode.dmPelsWidth / (double)mode.dmPelsHeight) * (1.0 / aspect) <= 0.1
            && best.dmBitsPerPel == mode.dmBitsPerPel && best.dmDisplayFrequency == mode.dmDisplayFrequency
            && abs(pixels - (int)(mode.dmPelsWidth * mode.dmPelsHeight)) < abs(pixels - (int)(best.dmPelsWidth * best.dmPelsHeight)))
            best = mode;
    }
    best.dmFields = DM_PELSWIDTH | DM_PELSHEIGHT;
    return pbest;
#undef best
}
