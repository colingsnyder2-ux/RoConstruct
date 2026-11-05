// from server: 100% by atomic.potato
struct P
{
    int g();
};

struct S
{
    char pad[360];
    P* m_p;
    int f();
};

int S::f()
{
    return m_p->g() + 0x3c;
}
