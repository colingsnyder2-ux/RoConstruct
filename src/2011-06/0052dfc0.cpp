// from server: 66% by atomic.potato
struct S_func_005367d0
{
    char pad0[600];
    char m_x;
    void f();
};

void S_func_005367d0::f()
{
    m_x = (char)0;
}

struct S
{
    void f(void *);
};

void S::f(void *p)
{
    char *q = (char *)this + 0xd28;
    if (p)
    {
        ((void (__thiscall *)(void *, void *))0x536780)(q, p);
    }
    else
    {
        ((void (__thiscall *)(void *))0x5367d0)(q);
    }
}
