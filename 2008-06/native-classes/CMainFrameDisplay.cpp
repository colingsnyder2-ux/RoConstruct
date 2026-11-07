// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/mfc-noinline-pcxstr /I{headers}/std-noinline-string
// >>> native-status (generated) -- do not edit >>>
// CMainFrameDisplay | 2008-06 | inactive
// unmapped (no binary link) | unmapped (no binary link) | by -
// <<< native-status | src a003c746 | roc native-status --write
#include "CMainFrame.h"
#include "util/standardout.h"
#include "util/scopedassign.h"
#include <G3D/Vector2int16.h>

#include "CRenderSettings.h"

// 00430bf0 (96%: the original loads the return-slot pointer into ebx at entry): the display mode closest to the requested pixel count with the current mode's
// aspect ratio (within 10%), colour depth and refresh rate.
DEVMODEA findDisplayMode(LPCSTR deviceName, int pixels)
{
    DEVMODEA best;
    DEVMODEA mode;
    memset(&mode, 0, sizeof(mode));
    mode.dmSize = sizeof(DEVMODEA);
    if (!EnumDisplaySettingsExA(deviceName, ENUM_CURRENT_SETTINGS, &mode, 0))
        RBX::StandardOut::singleton()->print(RBX::MESSAGE_ERROR, "EnumDisplaySettings failed. GetLastError() == %d", GetLastError());
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
    return best;
}

// 004318b0: switch the frame's monitor to the configured fullscreen resolution.
void CMainFrame::configureFullscreen()
{
    if (monitor == NULL) {
        RBX::StandardOut::singleton()->print(RBX::MESSAGE_ERROR, "CMainFrame::ChangeResolution hm is NULL");
        return;
    }
    RBX::ScopedAssign<bool> changing(stateFA, true);
    MONITORINFOEXA info;
    info.cbSize = sizeof(info);
    if (!GetMonitorInfoA(monitor, &info)) {
        RBX::StandardOut::singleton()->print(RBX::MESSAGE_ERROR, "GetMonitorInfo failed");
        return;
    }
    G3D::Vector2int16 resolution = CRenderSettings::singleton().getFullscreenSize();
    DEVMODEA mode;
    mode = findDisplayMode(info.szDevice, resolution.x * resolution.y);
    LONG result = ChangeDisplaySettingsExA(info.szDevice, &mode, NULL, CDS_FULLSCREEN, NULL);
    if (result == DISP_CHANGE_SUCCESSFUL) {
        ModifyStyle(WS_CAPTION | WS_THICKFRAME, 0, 0);
        CRect area = XTPMultiMonitor()->GetScreenArea(this);
        int cxBorder = GetSystemMetrics(SM_CXBORDER);
        int cyBorder = GetSystemMetrics(SM_CYBORDER);
        SetWindowPos(NULL, area.left - cxBorder, area.top - cyBorder,
                     area.right - area.left + 2 * cxBorder, area.bottom - area.top + 2 * cyBorder, SWP_NOZORDER);
    } else {
        RBX::StandardOut::singleton()->print(RBX::MESSAGE_ERROR, "ChangeDisplaySettings == %d", result);
    }
}
