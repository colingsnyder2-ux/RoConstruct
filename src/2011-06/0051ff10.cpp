// from server: 100% by atomic.potato
struct ProfiledRakPeer
{
    char pad0[0xa64];
    int m_value0;
    int m_value1;
    void f(int value0, int value1);
};

void ProfiledRakPeer::f(int value0, int value1)
{
    m_value0 = value0;
    m_value1 = value1;
}
