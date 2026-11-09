// from server: 100% by atomic.potato
struct S_func_007588e0
{
    unsigned int m_capacity;
    unsigned int m_index;
    unsigned int m_reserved;
    double* m_values;
    void Set(double value, unsigned char advance);
};

void S_func_007588e0::Set(double value, unsigned char advance)
{
    m_values[m_index] = value;
    if (advance)
    {
        m_index = (m_index + 1) % m_capacity;
    }
}
