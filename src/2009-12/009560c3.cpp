// from server: 50% by atomic.potato
extern "C" void __cdecl func_007f49a4(void *, unsigned int, unsigned int, unsigned int);

struct S
{
    void f();
};

void S::f()
{
    func_007f49a4((void *)0x434f30, 4, 32, (unsigned int)this + 0x34);
}
