// from server: 74% by atomic.potato
extern "C" void __stdcall _invalid_parameter_noinfo();

struct S_func_0077e4a0 {
    unsigned int m_capacity;
    unsigned int m_size;
    char pad[8];
    double* m_data;
    double* m_end;
    void f(double value, int flag);
};

void S_func_0077e4a0::f(double value, int flag)
{
    unsigned int count = (unsigned int)((m_end - m_data));
    if (m_size >= count)
        _invalid_parameter_noinfo();
    m_data[m_size] = value;
    if (flag)
        m_size = (m_size + 1) % m_capacity;
}
