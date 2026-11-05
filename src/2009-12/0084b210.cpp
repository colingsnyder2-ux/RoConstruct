// from server: 74% by atomic.potato
typedef int BOOL;

struct POINT
{
    long x;
    long y;
};

extern "C" BOOL __stdcall GetCursorPos(POINT *);
extern "C" BOOL __stdcall ScreenToClient(void *, POINT *);

struct CXTPPrintingDialog
{
    void *m_hWnd;
    int f(POINT *);
};

int CXTPPrintingDialog::f(POINT *pt)
{
    GetCursorPos(pt);
    ScreenToClient(*(void **)((char *)this + 0x20), pt);
    return (int)this;
}
