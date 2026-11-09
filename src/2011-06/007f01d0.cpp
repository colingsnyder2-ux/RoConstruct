// from server: 32% by atomic.potato
struct S_func_007f01d0
{
    char pad0[160];
    int m_count;
    int m_data[1];

    int f(int index);
};

int S_func_007f01d0::f(int index)
{
    int count = m_count;
    m_data[index] = m_data[count - 1];
    --m_count;
    return 0;
}
