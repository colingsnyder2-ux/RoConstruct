// from server: 83% by atomic.potato
struct S_func_007404f0 {
    char pad0[572];
    float m_x;
    float m_y;
    void f(float *out);
};

void S_func_007404f0::f(float *out)
{
    out[0] = m_x;
    out[1] = m_y;
}
