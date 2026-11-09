// from server: 75% by atomic.potato
struct CXTPBitmapDC
{
    void f();
};

extern "C" void *__stdcall SelectObject(void *, void *);

void CXTPBitmapDC::f()
{
    void *a = *(void **)((char *)this + 0x10);
    void *b = *(void **)((char *)this + 0x0c);
    *(int *)this = 0x009fbbc0;
    SelectObject(b, a);
    *(int *)((char *)this + 4) = 0x009a1848;
    ((void (__thiscall *)(CXTPBitmapDC *))0x0040f230)(this);
}
