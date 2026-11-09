// from server: 77% by atomic.potato
struct Marker
{
    int m_data;
    unsigned int m_offset;
    int m_unused;
    unsigned int m_size;
    int f(unsigned int value);
};

int __declspec(nothrow) __thiscall Marker::f(unsigned int value)
{
    unsigned int offset = m_offset;
    if (offset + value < m_size)
        return m_data + offset + value;
    return m_data + offset - m_size + value;
}
