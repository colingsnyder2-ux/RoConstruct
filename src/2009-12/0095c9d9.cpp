// from server: 65% by atomic.potato
extern "C" void __cdecl func_007f49a4(void *, int, int, void *);

struct S
{
    void f();
};

void S::f()
{
    func_007f49a4((char *)this + 0x2a4, 0x5c, 0x10, (void *)0x83dd90);
}
