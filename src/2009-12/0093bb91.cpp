// from server: 65% by atomic.potato
extern "C" void __cdecl func_007f49a4(void *, int, int, void *);

struct S
{
    void f();
};

void S::f()
{
    func_007f49a4((char *)this + 0x54c, 0x1c, 1, (void *)0x570480);
}
