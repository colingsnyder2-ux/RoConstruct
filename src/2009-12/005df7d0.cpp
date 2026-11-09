// from server: 100% by atomic.potato
struct S_005df7d0 {
    int pad0[3];
    int m_value;
    int f(int value);
};

int S_005df7d0::f(int value)
{
    return value * 0x34 + m_value;
}
