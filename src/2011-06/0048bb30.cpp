// from server: 88% by atomic.potato
typedef unsigned long DWORD;
typedef void* HWND;
typedef long LPARAM;
typedef unsigned int UINT;
typedef unsigned long WPARAM;
typedef long LRESULT;

extern "C" HWND __stdcall func_0080af5e(unsigned int);
extern "C" LRESULT __stdcall SendMessageA(HWND, UINT, WPARAM, LPARAM);

struct S
{
    int f();
    char pad[0x19c];
    int value;
};

int S::f()
{
    HWND h = func_0080af5e(0x412);
    LRESULT r = SendMessageA(h, 0xf0, 0, 0);
    value = r != 0;
    return value;
}
