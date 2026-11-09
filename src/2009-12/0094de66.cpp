// from server: 65% by atomic.potato
extern "C" void __cdecl func_007f49a4(void *, int, int, const void *);

struct S_0094de66
{
    int value[0x29];
    void f();
};

void S_0094de66::f()
{
    func_007f49a4((char *)this + 0xa4, 8, 2, (const void *)0x52e530);
}
