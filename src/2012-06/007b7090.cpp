// from server: 47% by atomic.potato
struct S_func_007b7090 {
    char pad[0xa0];
    float m_value;
    float f();
};

extern float g_007b7090_max;
extern float g_007b7090_min;

float S_func_007b7090::f()
{
    float v = m_value;
    if (g_007b7090_max < v)
        return g_007b7090_max;
    if (v < g_007b7090_min)
        return v;
    return g_007b7090_max;
}
