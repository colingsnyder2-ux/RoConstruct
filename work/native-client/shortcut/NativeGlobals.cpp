// Shortcut (owner-authorized): real definitions of globals the exe constructs at startup; zero-filled stubs crash MFC.
#include <afxwin.h>
CString nativeCrashReportText;  // original 0096dcf0
bool silentCrashReport = false; // original; default not silent

// original 00412d50: returns the startup context; +0x130 holds the startup mode (0 = normal)
static struct StartupBlock { char bytes[0x400]; StartupBlock() { *reinterpret_cast<int*>(bytes + 0x130) = 5; } } startupBlock; // mode 5: no start page, open an empty place
void* nativeStartupContext() { return startupBlock.bytes; }
