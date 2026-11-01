// from server: 100% by atomic.potato
extern "C" void __stdcall sub_007f3e30();

struct CWebToolbox_004766c0 {
    void f(void *);
};

void CWebToolbox_004766c0::f(void *p)
{
    sub_007f3e30();
    *(int *)((char *)p + 0xc) = 0x32;
}
