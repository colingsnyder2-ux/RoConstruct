// from server: 87% by atomic.potato
struct S_func_006d8a00 {
    char pad[156];
    float m_x;
    float m_y;
    float m_z;
    void f(float* out);
};

void S_func_006d8a00::f(float* out)
{
    out[0] = m_x;
    out[1] = m_y;
    out[2] = m_z;
}
