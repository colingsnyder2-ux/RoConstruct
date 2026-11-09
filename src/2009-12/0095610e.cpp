// from server: 63% by atomic.potato
extern "C" void __cdecl func_007f49a4(void *, unsigned int, unsigned int, const void *);

struct seg_00950000
{
    void f();
};

void seg_00950000::f()
{
    char *p = (char *)this;
    func_007f49a4(p + 0x34, 0x20, 4, (const void *)0x434f30);
}
