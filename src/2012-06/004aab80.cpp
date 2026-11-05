// from server: 56% by atomic.potato
struct S_func_004aab80 {
    char pad0[0xac];
    float m_x;
    float m_y;
    void f();
};

extern float g_b62770;
float* sub_627310();

void S_func_004aab80::f()
{
    float* p = sub_627310();
    float v = g_b62770;
    m_x = p[0] + v;
    m_y = p[1] + v;
}
