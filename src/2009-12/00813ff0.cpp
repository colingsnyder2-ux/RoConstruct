// from server: 68% by atomic.potato
struct S
{
    void f(int);
    int m_b0;
    int *m_c8;
};

void S::f(int value)
{
    if (value)
    {
        m_c8[0x31] = 1;
        m_c8[0x2c] = 0;
    }
}
