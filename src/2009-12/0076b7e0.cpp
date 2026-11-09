// from server: 54% by atomic.potato
struct S
{
    int f();
    void g();
    int m_94;
};

void S::g()
{
}

int S::f()
{
    g();
    return (short)*(short *)((char *)m_94 + 0xa2);
}
