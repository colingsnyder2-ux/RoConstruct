// from server: 86% by atomic.potato
typedef int BOOL;
typedef void *HWND;
typedef struct tagRECT
{
    long left;
    long top;
    long right;
    long bottom;
} RECT;

extern "C" BOOL __stdcall IsWindow(HWND);
extern "C" BOOL __stdcall GetWindowRect(HWND, RECT *);
extern "C" int __stdcall SetRectEmpty(RECT *);

struct S
{
    int f(HWND);
};

int S::f(HWND h)
{
    if (IsWindow(h))
    {
        GetWindowRect(h, 0);
        return (int)this;
    }
    SetRectEmpty(0);
    return (int)this;
}
