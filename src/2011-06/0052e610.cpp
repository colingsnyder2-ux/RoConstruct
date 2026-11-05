// from server: 100% by atomic.potato
struct S_0052e610 {
    int m_base;
    int m_offset;
    char pad8[4];
    int m_limit;
    int f(int value);
};

int S_0052e610::f(int value)
{
    unsigned int end = (unsigned int)m_offset + (unsigned int)value;
    if (end >= (unsigned int)m_limit)
        return m_base + m_offset - m_limit + value;
    return m_base + m_offset + value;
}
