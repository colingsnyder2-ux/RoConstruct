// from server: 90% by atomic.potato
extern "C" void __stdcall _invalid_parameter_noinfo();

struct S_func_00714940 {
    int m_capacity;
    int m_size;
    char pad8[8];
    double* m_data;
    char pad18[4];
    double* m_end;
    void push_back(double value, char check);
};

void S_func_00714940::push_back(double value, char check)
{
    unsigned idx = (unsigned)m_size;
    unsigned cap = (unsigned)((m_end - m_data) >> 3);
    if (idx >= cap) {
        _invalid_parameter_noinfo();
    }
    m_data[idx] = value;
    if (check) {
        unsigned next = (unsigned)m_size + 1;
        m_size = (int)(next % (unsigned)m_capacity);
    }
}
