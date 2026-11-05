// from server: 100% by atomic.potato
typedef long BOOL;

struct RECT
{
    long left;
    long top;
    long right;
    long bottom;
};

extern "C" BOOL (__stdcall *SetRectEmpty)(RECT *);

struct CXTPBitmapDC
{
    int *f(int);
};

int *CXTPBitmapDC::f(int value)
{
    int *result;
    result = (int *)this;
    *((int *)this + 1) = value;
    SetRectEmpty((RECT *)((char *)this + 8));
    *((int *)this) = 0;
    return result;
}
