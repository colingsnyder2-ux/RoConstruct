// from server: 100% by why2
struct S_func_006d40a0 {
    char pad[4];
    float m_value;
    char pad2[8];
    float m_result;
    void f();
};

extern float g_multiplier_008bad4c;

void S_func_006d40a0::f()
{
    m_result = m_value * g_multiplier_008bad4c;
}
