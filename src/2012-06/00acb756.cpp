// from server: 65% by atomic.potato
extern "C" void __cdecl func_00983270(void *, int, int, const void *);

struct S
{
    void f();
};

void S::f()
{
    func_00983270((char *)this + 0x98, 8, 2, (const void *)0x877440);
}
