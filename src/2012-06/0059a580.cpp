// from server: 100% by atomic.potato
struct S_func_0059a580
{
    unsigned int m_base;
    unsigned int m_data;
    unsigned int m_unused;
    unsigned int m_limit;
    unsigned int f(unsigned int index);
};

unsigned int S_func_0059a580::f(unsigned int index)
{
    unsigned int value = m_data + index;
    if (value >= m_limit)
        return m_base + ((m_data - m_limit + index) << 4);
    return m_base + (value << 4);
}
