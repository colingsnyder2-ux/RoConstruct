// from server: 86% by atomic.potato
struct S_0052f820
{
    char pad0[0x87c];
    unsigned int m_87c;
    char pad1[0x428];
    int m_ca8;
    int f();
};

int S_0052f820::f()
{
    if (m_87c > 0)
        return 1;
    return m_ca8 != 0;
}
