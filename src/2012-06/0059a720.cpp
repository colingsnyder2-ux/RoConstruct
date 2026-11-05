// from server: 100% by atomic.potato
struct S_func_0059a720
{
    unsigned char* m_data;
    int m_index;
    int m_unused;
    int m_size;
    unsigned char f();
};

unsigned char S_func_0059a720::f()
{
    ++m_index;
    if (m_index == m_size)
        m_index = 0;
    if (m_index == 0)
        return m_data[m_size + m_index - 1];
    return m_data[m_index - 1];
}
