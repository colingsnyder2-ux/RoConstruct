// from server: 95% by atomic.potato
typedef unsigned int UINT;
typedef unsigned long WPARAM;
typedef long LPARAM;
typedef long LRESULT;

extern "C" LRESULT __declspec(dllimport) __stdcall SendMessageA(void *, UINT, WPARAM, LPARAM);

struct CMainFrame
{
    int f();
};

int CMainFrame::f()
{
    void *p = *((void **)((char *)this + 0x13c));
    if (p != 0)
    {
        SendMessageA(*((void **)((char *)p + 0x20)), 0x4bc, 0, 0);
        *((void **)((char *)this + 0x13c)) = 0;
    }
    return 0;
}
