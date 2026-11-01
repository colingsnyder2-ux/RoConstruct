// from server: 100% by tester
struct RakPeer {
    void setValue(short value);
    char m_pad[0xa];
    short m_value;
};

void RakPeer::setValue(short value)
{
    m_value = value;
}
