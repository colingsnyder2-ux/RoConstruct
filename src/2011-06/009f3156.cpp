// from server: 65% by atomic.potato
extern "C" void __cdecl func_0080b1d8(void *, int, int, void *);

struct S
{
    void f();
};

void S::f()
{
    func_0080b1d8((void *)((char *)this + 0xa4), 8, 2, (void *)0x63de40);
}
