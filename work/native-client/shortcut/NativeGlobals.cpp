// Shortcut (owner-authorized): real definitions of globals the exe constructs at startup; zero-filled stubs crash MFC.
#include <afxwin.h>
CString nativeCrashReportText;  // original 0096dcf0
bool silentCrashReport = false; // original; default not silent

// original 00412d50: returns the startup context; +0x130 holds the startup mode (0 = normal)
static struct StartupBlock { char bytes[0x400]; StartupBlock() { *reinterpret_cast<int*>(bytes + 0x130) = 5; } } startupBlock; // mode 5: report view; mode 0 (CRobloxView) needs CRenderSettings singleton fixed. Really GlobalSettingsItem<CRenderSettings>::singleton (00412d50); +0x130 is a render-settings field
void* nativeStartupContext() { return startupBlock.bytes; }
