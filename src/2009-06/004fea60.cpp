// from server: 100% by why2
struct RakPeer {
    char pad0[0xb44];
    unsigned char m_field_b44;
    void f(unsigned char a1);
};

void RakPeer::f(unsigned char a1)
{
    m_field_b44 = a1;
}
