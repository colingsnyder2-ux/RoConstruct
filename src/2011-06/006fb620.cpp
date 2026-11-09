// from server: 45% by atomic.potato
struct S_func_006fb620 {
    char pad[0xb0];
    float m_value;
    float f();
};

extern float g_006fb620_min;
extern float g_006fb620_max;

float S_func_006fb620::f()
{
    float v = m_value;
    if (g_006fb620_min < v)
        return g_006fb620_min;
    if (v >= g_006fb620_max)
        return g_006fb620_min;
    return v;
}
