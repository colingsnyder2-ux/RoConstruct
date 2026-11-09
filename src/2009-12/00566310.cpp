// from server: 100% by atomic.potato
struct RakPeer
{
    char pad0[0xa7c];
    int m_value;
    void f(int value);
};

void RakPeer::f(int value)
{
    if (m_value == value)
        m_value = 0;
}
