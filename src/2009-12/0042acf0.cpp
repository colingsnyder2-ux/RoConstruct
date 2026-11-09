// from server: 100% by atomic.potato
extern int g_00b7a2c4;
extern void G1_func_0042a8a0();

struct CMainFrame
{
    void f();
};

void CMainFrame::f()
{
    if (g_00b7a2c4 == 0)
    {
        *((unsigned char *)this + 0x109) = 1;
        G1_func_0042a8a0();
    }
}
