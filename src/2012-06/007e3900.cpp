// from server: 58% by atomic.potato
struct S_func_009f9be0
{
    char pad0[36];
    int m_x;
    int f();
};

int S_func_009f9be0::f()
{
    return m_x;
}

struct S
{
    int f();
};

int S::f()
{
    S_func_009f9be0* p = (S_func_009f9be0*)((char*)this + 8);
    int x = p->f();
    if (x)
    {
        p = (S_func_009f9be0*)x;
        x = p->f();
        if (x)
            return x - 8;
    }
    return 0;
}
