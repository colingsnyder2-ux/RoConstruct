// from server: 96% by atomic.potato
struct ProfiledRakPeer {
    unsigned int m_bits;
    char pad[8];
    unsigned char* m_data;
    void WriteBits(const unsigned char* src);
};

extern "C" void __stdcall sub_4ecbd0(void* p, unsigned int n);
extern "C" bool __stdcall sub_4e7240();

void ProfiledRakPeer::WriteBits(const unsigned char* src)
{
    unsigned int bits = m_bits;
    unsigned int aligned = bits - ((bits - 1) & 7);
    m_bits = aligned + 7;

    sub_4ecbd0(this, 0x18);

    if (!sub_4e7240()) {
        unsigned int b = m_bits >> 3;
        m_data[b] = src[0];
        b = m_bits >> 3;
        m_data[b + 1] = src[1];
        b = m_bits >> 3;
        m_data[b + 2] = src[2];
    } else {
        unsigned int b = m_bits >> 3;
        m_data[b] = src[3];
        b = m_bits >> 3;
        m_data[b + 1] = src[2];
        b = m_bits >> 3;
        m_data[b + 2] = src[1];
    }
    m_bits += 0x18;
}
