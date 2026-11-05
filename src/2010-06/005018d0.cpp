// from server: 50% by atomic.potato
struct S_func_0051d310
{
    char pad0[600];
    char m_x;
    void f();
};

void S_func_0051d310::f()
{
    m_x = (char)0;
}

struct S
{
    void f(void *);
};

void S::f(void *p)
{
    char *q = (char *)this + 0x1070;
    if (p)
    {
        *(void **)((char *)this + 4) = p;
        return;
    }
    ((S_func_0051d310 *)q)->f();
}
