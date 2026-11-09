// from server: 90% by atomic.potato
struct CRobloxView
{
    void f();
};

extern "C" void __stdcall sub_45fdd0(int, int);
extern "C" void __stdcall sub_4764b0(void *, int);

void CRobloxView::f()
{
    sub_45fdd0(1, 1);
    sub_4764b0(*(void **)((char *)this + 0x210), 9);
}
