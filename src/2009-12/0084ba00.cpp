// from server: 100% by atomic.potato
struct RECT
{
    long left;
    long top;
    long right;
    long bottom;
};

extern "C" void (__stdcall *SetRectEmpty)(RECT *);

struct CXTPBitmapDC
{
    CXTPBitmapDC(RECT *);
};

CXTPBitmapDC::CXTPBitmapDC(RECT *rect)
{
    *(RECT **)((char *)this + 4) = rect;
    SetRectEmpty((RECT *)((char *)this + 8));
    *(int *)this = 0;
}
