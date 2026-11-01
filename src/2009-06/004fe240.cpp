// from server: 100% by why2
struct RakPeer {
    char pad0[0xa];
    short m_field_a;
    void set(short value);
};

void RakPeer::set(short value)
{
    m_field_a = value;
}
