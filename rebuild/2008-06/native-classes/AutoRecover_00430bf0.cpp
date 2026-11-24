// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <windows.h>
#include <math.h>
#include <string.h>
#include "util/StandardOut.h"

// INFERRED: header path and MESSAGE_ERROR enum name
DEVMODEA findDisplayMode(const char* deviceName, int targetPixels)
{
    DEVMODEA dm;
    memset(&dm, 0, sizeof(dm));
    dm.dmSize = sizeof(DEVMODEA);

    if (!EnumDisplaySettingsExA(deviceName, ENUM_CURRENT_SETTINGS, &dm, 0))
    {
        RBX::StandardOut::singleton()->print(RBX::MESSAGE_ERROR,
            "EnumDisplaySettings failed. GetLastError() == %d", GetLastError());
    }

    double aspect = (double)dm.dmPelsWidth / (double)dm.dmPelsHeight;

    DEVMODEA best = dm;

    int i = 0;
    while (EnumDisplaySettingsExA(deviceName, i, &dm, 0))
    {
        double inv = 1.0 / aspect;
        ++i;
        // INFERRED: tolerance constant (value at 0x811230)
        if (fabs(aspect - (double)dm.dmPelsWidth / (double)dm.dmPelsHeight) * inv <= 0.01
            && best.dmBitsPerPel == dm.dmBitsPerPel
            && best.dmDisplayFrequency == dm.dmDisplayFrequency)
        {
            int bestDiff = abs(targetPixels - (int)(best.dmPelsHeight * best.dmPelsWidth));
            int curDiff = abs(targetPixels - (int)(dm.dmPelsHeight * dm.dmPelsWidth));
            if (curDiff < bestDiff)
                best = dm;
        }
    }

    best.dmFields = DM_PELSWIDTH | DM_PELSHEIGHT;
    return best;
}
