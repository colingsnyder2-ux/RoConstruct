// from server: 80% by atomic.potato
typedef void *HDC;
typedef void *HGDIOBJ;

extern "C" HGDIOBJ (__stdcall *SelectObject)(HDC, HGDIOBJ);

struct CXTPBitmapDC
{
    void f();
};

void CXTPBitmapDC::f()
{
    HGDIOBJ a = *(HGDIOBJ *)((char *)this + 0x10);
    HDC b = *(HDC *)((char *)this + 0x0c);
    *(int *)this = 0x9fbbb8;
    SelectObject(b, a);
    *(int *)((char *)this + 4) = 0x9fbb10;
}
