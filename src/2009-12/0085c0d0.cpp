// from server: 86% by atomic.potato
typedef void* HWND;
typedef int BOOL;

extern "C" void func_007f3e30(void);
extern "C" void func_0085bda0(int, int);
extern "C" BOOL __stdcall InvalidateRect(HWND, const void*, BOOL);

struct S
{
    char padding[0x20];
    void* field20;
    void f(int, int, int);
};

void S::f(int, int, int)
{
    func_007f3e30();
    func_0085bda0(1, 0);
    InvalidateRect((HWND)field20, 0, 0);
}
