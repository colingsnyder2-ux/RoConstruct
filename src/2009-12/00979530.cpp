// from server: 100% by atomic.potato
typedef unsigned int DWORD;

struct C
{
    void f();
};

struct T
{
    void __thiscall sub_00738640(void *, void *, unsigned int, unsigned int, unsigned int);
};

extern "C" void __cdecl sub_007f4929(const void *);

void C::f()
{
    ((T *)0xB96298)->sub_00738640((void *)0x9E1C50, (void *)0x9E1C48, 0x184, 0xF, 0);
    sub_007f4929((const void *)0x988590);
}
