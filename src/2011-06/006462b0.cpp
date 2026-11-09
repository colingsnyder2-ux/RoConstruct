// from server: 100% by atomic.potato
struct StarterGuiService
{
    void f();
};

extern "C" void G1_func_00645e60();

void StarterGuiService::f()
{
    *(long *)this = 0x00A984EC;
    *(long *)((char *)this + 4) = 0x00A984E4;
    *(long *)((char *)this + 0x18) = 0x00A984D8;
    *(long *)((char *)this + 0x1C) = 0x00A984CC;
    *(long *)((char *)this + 0x90) = 0x00A984C4;
    *(long *)((char *)this + 0x94) = 0x00A984BC;
    G1_func_00645e60();
}
