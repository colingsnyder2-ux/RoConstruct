// from server: 38% by atomic.potato
struct S_func_0060ab90 {
    char pad0[216];
    char m_data[36];
    void f(const char* src);
};

void S_func_0060ab90::f(const char* src)
{
    int i;
    for (i = 0; i < 36; i += 4)
        *(int*)(m_data + i) = *(const int*)(src + i);
}
