// from server: 31% by atomic.potato
struct S_func_005e6df0 {
    char pad0[216];
    char m_data[36];
    void f(const char* source);
};

void S_func_005e6df0::f(const char* source)
{
    int i;
    for (i = 0; i < 36; ++i)
        m_data[i] = source[i];
}
