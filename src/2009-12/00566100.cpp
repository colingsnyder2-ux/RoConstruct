// from server: 100% by atomic.potato
struct RakPeer {
    char pad0[0xb44];
    unsigned char m_value;
    void f(unsigned char value);
};

void RakPeer::f(unsigned char value)
{
    m_value = value;
}
