// from server: 57% by atomic.potato
extern "C" void __cdecl T_func_007f4929(const void *);
extern "C" void __cdecl T_func_0074a320();

struct S {
    void f();
};

void S::f()
{
    T_func_0074a320();
    *(int *)0xb96ee4 = 0x9e3e00;
    T_func_007f4929((const void *)0x989070);
}
