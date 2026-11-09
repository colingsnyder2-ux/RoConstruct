// from server: 90% by atomic.potato
struct S_008cc270 {
    char pad0[352];
    int m_160;
    int m_164;
    int m_168;
    void f(int *p);
};

void S_008cc270::f(int *p)
{
    p[0] = m_160;
    p[1] = m_164;
    p[2] = m_168;
}
