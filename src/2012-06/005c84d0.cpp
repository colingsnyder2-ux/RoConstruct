// from server: 60% by atomic.potato
struct S_func_005c84d0 {
    char pad[16];
    double m_a;
    double m_b;
    int f();
};

int S_func_005c84d0::f()
{
    if (m_b >= m_a)
        return 1;
    if (m_b >= 0.0)
        return 0;
    return 1;
}
