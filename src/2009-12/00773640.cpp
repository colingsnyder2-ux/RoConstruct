// from server: 100% by atomic.potato
struct S_func_00773640 {
    int m_data[4];
    int f(int index);
};

int S_func_00773640::f(int index)
{
    int value = m_data[index - 4];
    if (value)
        return value + 8;
    return 0;
}
