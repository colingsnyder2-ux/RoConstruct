// >>> native-status (generated) -- do not edit >>>
// ApplicationWindowClass | 2008-06 | inactive
// unmapped (no indexed address) | unmapped (no binary link) | by -
// <<< native-status | src 85aacb81 | roc native-status --write
#include <afxwin.h>

// 004495a0: register the application window class and create its MFC frame.
void nativeInitializeCom()
{
    WNDCLASS windowClass;
    windowClass.style = CS_HREDRAW | CS_VREDRAW;
    windowClass.lpfnWndProc = DefWindowProc;
    windowClass.cbClsExtra = 0;
    windowClass.cbWndExtra = 0;
    windowClass.hInstance = AfxGetModuleState()->m_hCurrentInstanceHandle;
    windowClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    windowClass.hCursor = LoadCursor(NULL, IDC_ARROW);
    windowClass.hbrBackground = NULL;
    windowClass.lpszMenuName = "Menu";
    windowClass.lpszClassName = "ROBLOX-ATOM";
    RegisterClass(&windowClass);
    CFrameWnd* frame = static_cast<CFrameWnd*>(RUNTIME_CLASS(CFrameWnd)->CreateObject());
    frame->Create(windowClass.lpszClassName, "ROBLOX", WS_OVERLAPPEDWINDOW,
                  CFrameWnd::rectDefault, NULL, NULL, 0, NULL);
}
