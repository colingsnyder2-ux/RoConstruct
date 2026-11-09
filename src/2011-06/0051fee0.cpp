// from server: 100% by atomic.potato
struct S_0051fee0
{
    char pad0[0x8ac];
    int m_value;
    void f(int value);
};

void S_0051fee0::f(int value)
{
    if (m_value == value)
        m_value = 0;
}
