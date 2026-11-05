// from server: 93% by atomic.potato
struct CMainFrame
{
    void f(void *);
};

extern "C" void __stdcall sub_007f3e30(CMainFrame *);

void CMainFrame::f(void *arg)
{
    sub_007f3e30(this);
    if (*((unsigned char *)this + 0xfc) != 0 ||
        *((unsigned char *)this + 0xfe) != 0)
        return;
    *((unsigned long *)((unsigned char *)arg + 0x18)) |= 3;
}
