// Runtime milestone M2: a Win32 shell window opens, pumps messages and closes cleanly, in an exe linked
// with the rebuilt rbxgs-app. The bootstrap (this file) is not authentic 2008 code. It also builds a small
// instance tree through the rebuilt engine, so the link pulls real engine code in, not just the window.
#include <winsock2.h>  // before windows.h, as the engine headers expect
#include <windows.h>
#include <cstdio>
#include "v8datamodel/Message.h"

static LRESULT CALLBACK windowProc(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp)
{
    if (msg == WM_CLOSE)
    {
        DestroyWindow(hwnd);
        return 0;
    }
    if (msg == WM_DESTROY)
    {
        PostQuitMessage(7);
        return 0;
    }
    return DefWindowProcA(hwnd, msg, wp, lp);
}

int main()
{
    boost::shared_ptr<RBX::Message> message = RBX::Creatable<RBX::Instance>::create<RBX::Message>();
    message->setName("Shell");

    WNDCLASSA wc = {0};
    wc.lpfnWndProc = windowProc;
    wc.hInstance = GetModuleHandleA(NULL);
    wc.lpszClassName = "RoConstructShell";
    if (!RegisterClassA(&wc)) { std::printf("register failed\n"); return 1; }
    HWND hwnd = CreateWindowA(wc.lpszClassName, message->getName().c_str(), WS_OVERLAPPEDWINDOW,
                              CW_USEDEFAULT, CW_USEDEFAULT, 320, 240, NULL, NULL, wc.hInstance, NULL);
    if (!hwnd) { std::printf("create failed\n"); return 2; }
    ShowWindow(hwnd, SW_SHOWNOACTIVATE);
    PostMessageA(hwnd, WM_CLOSE, 0, 0);

    MSG msg;
    int quit = -1;
    while (GetMessageA(&msg, NULL, 0, 0) > 0)
    {
        TranslateMessage(&msg);
        DispatchMessageA(&msg);
    }
    quit = (int)msg.wParam;
    bool closed = !IsWindow(hwnd);
    std::printf("window opened, quit=%d closed=%d\n", quit, closed ? 1 : 0);
    return quit == 7 && closed ? 0 : 3;
}
