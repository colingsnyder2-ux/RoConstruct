// from server: 65% by atomic.potato
extern "C" void __cdecl func_00983270(void *, unsigned int, unsigned int, const void *);

struct S_seg_00ab0000
{
    void f();
};

void S_seg_00ab0000::f()
{
    func_00983270((char *)this + 0xba8, 0x10, 0x20, (const void *)0x5bc4a0);
}
