// from server: 69% by atomic.potato
struct S_func_00688a80 {
    char pad[68];
    void *m_value;
    void f();
};

extern "C" int __cdecl sub_0080b2ea(void *, void *, void *, int, int);

void S_func_00688a80::f()
{
    int value = sub_0080b2ea(m_value, (void *)0xc071f8, (void *)0xc59fa4, 0, 0);
    if (value)
    {
        void *next = (void *)value;
        ((void (__thiscall *)(void *))0x00689280)(next);
    }
}
