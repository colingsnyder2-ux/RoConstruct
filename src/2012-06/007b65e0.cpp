// from server: 47% by atomic.potato
struct S_func_007b65e0
{
    char pad[0x9c];
    float m_value;
    float GetClamped();
};

extern float g_min_007b65e0;
extern float g_max_007b65e0;

float S_func_007b65e0::GetClamped()
{
    float v = m_value;
    if (g_max_007b65e0 < v)
        return g_max_007b65e0;
    if (v < g_min_007b65e0)
        return v;
    return g_max_007b65e0;
}
