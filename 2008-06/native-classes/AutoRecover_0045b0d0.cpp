// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <windows.h>

// INFERRED: AFX_MODULE_STATE is private to MFC sources, so it is forward-declared
// here and accessed by raw offsets to match the disassembly.
class AFX_MODULE_STATE;
AFX_MODULE_STATE* __stdcall AfxGetModuleState();

// INFERRED: layout from the disassembly:
// state+4    = m_pCurrentWinApp
// app+0x20   = m_pMainWnd (CWinThread)
// wnd+0x20   = m_hWnd (CWnd)
// wnd+0xf8   = a byte flag in the derived main window class
extern "C" void fn_0045b0d0()
{
    char* state = reinterpret_cast<char*>(AfxGetModuleState());
    char* app = *reinterpret_cast<char**>(state + 4);
    char* wnd = *reinterpret_cast<char**>(app + 0x20);

    if (*reinterpret_cast<unsigned char*>(wnd + 0xf8) != 0)
    {
        HWND hWnd = *reinterpret_cast<HWND*>(wnd + 0x20);
        PostMessageA(hWnd, WM_COMMAND, 0x80f4, 0);
    }
}
