// from server: 87% by atomic.potato
struct S_func_006fb5d0 {
    char pad[164];
    float m_x;
    float m_y;
    float m_z;
    void f(float* out);
};

void S_func_006fb5d0::f(float* out)
{
    out[0] = m_x;
    out[1] = m_y;
    out[2] = m_z;
}
