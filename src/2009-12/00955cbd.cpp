// from server: 65% by atomic.potato
extern "C" void __cdecl func_007f49a4(void *, int, int, const void *);

struct seg_00950000
{
    void f();
};

void seg_00950000::f()
{
    func_007f49a4((char *)this + 0x1a0, 0x0c, 2, (const void *)0x4d62e0);
}
