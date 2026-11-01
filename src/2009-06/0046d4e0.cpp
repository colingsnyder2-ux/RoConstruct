// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
typedef unsigned long DWORD;
typedef struct _OSVERSIONINFOA {
    DWORD dwOSVersionInfoSize; DWORD dwMajorVersion; DWORD dwMinorVersion;
    DWORD dwBuildNumber; DWORD dwPlatformId; char szCSDVersion[128];
} OSVERSIONINFOA;
extern "C" __declspec(dllimport) int __stdcall GetVersionExA(OSVERSIONINFOA* lpVersionInformation);
bool isVistaOrLater()
{
    OSVERSIONINFOA vi = { 0 };
    vi.dwOSVersionInfoSize = sizeof(vi);
    if (GetVersionExA(&vi) && vi.dwPlatformId == 2 && vi.dwMajorVersion >= 6)
        return true;
    return false;
}
