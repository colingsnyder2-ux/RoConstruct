// from server: 84% by atomic.potato
typedef unsigned int HWND;
typedef unsigned int UINT;
typedef unsigned int WPARAM;
typedef long LPARAM;
typedef int BOOL;

extern "C" HWND __cdecl sub_80A31C();
extern "C" BOOL __stdcall PostMessageA(HWND, UINT, WPARAM, LPARAM);

struct LockPlayModeVerb
{
    void f();
};

void LockPlayModeVerb::f()
{
    HWND h = sub_80A31C();
    h = *(HWND *)(h + 4);
    h = *(HWND *)(h + 0x20);
    h = *(HWND *)(h + 0x20);
    PostMessageA(h, 0x111, 0x80ff, 0);
}
