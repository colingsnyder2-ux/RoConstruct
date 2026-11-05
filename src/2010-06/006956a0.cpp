// from server: 76% by atomic.potato
struct S_func_006956a0
{
    char pad0[180];
    float *m_value;
    void f(float value);
};

void S_func_006956a0::f(float value)
{
    m_value[52] = value;
}
