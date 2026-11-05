// from server: 30% by atomic.potato
struct S_func_00464cf0
{
    char pad0[4];
    int m_x;
    int f();
};

int S_func_00464cf0::f()
{
    return m_x;
}

struct S_func_00561860
{
    unsigned short port;
    unsigned short value;
};

unsigned short S_func_00561860_f(S_func_00561860* p)
{
    return p->port;
}

struct S
{
    int value;
    unsigned short port;
    int f();
};

int S::f()
{
    S_func_00561860* p;
    S_func_00464cf0* q;
    unsigned short v;

    p = (S_func_00561860*)this;
    v = S_func_00561860_f(p);
    q = (S_func_00464cf0*)this;
    value = q->f();
    port = v;
    return (int)this;
}
