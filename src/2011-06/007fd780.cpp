// from server: 37% by atomic.potato
typedef unsigned long DWORD;

struct S_func_007fd2f0
{
    void f();
};

struct S_func_008008c0
{
    void f(int);
};

extern "C" void __cdecl func_0080b15d(void *);

struct S_func_007fd780
{
    void f();
};

void S_func_007fd780::f()
{
    if (!(*(volatile DWORD *)0xd16c68 & 1))
    {
        *(volatile DWORD *)0xd16c68 |= 1;
        ((S_func_007fd2f0 *)0xd16ac0)->f();
        func_0080b15d((void *)0xa3f9f0);
    }
    ((S_func_008008c0 *)0xd16ac0)->f(0);
    *(DWORD *)0xd16278 = 0xd16ac0;
}
