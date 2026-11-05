// from server: 100% by atomic.potato
struct S_func_004ece30 {
    unsigned int m_end;
    unsigned int m_data;
    unsigned int m_pos;
    unsigned char *m_bytes;
    unsigned char f(unsigned char *out);
};

unsigned char S_func_004ece30::f(unsigned char *out)
{
    if (m_pos + 8 > m_end)
        return 0;
    *out = ((unsigned char *)m_bytes)[m_pos >> 3];
    m_pos += 8;
    return 1;
}
