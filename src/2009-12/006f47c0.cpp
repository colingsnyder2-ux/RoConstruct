// from server: 100% by atomic.potato
struct S_func_006f47c0 {
    char pad0[148];
    unsigned char m_flag;
    char pad1[19];
    int m_value;
    void f(const int* value);
};

void S_func_006f47c0::f(const int* value)
{
    if (m_flag)
        m_value = *value;
}
