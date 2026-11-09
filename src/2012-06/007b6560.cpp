// from server: 47% by atomic.potato
struct S_func_007b6560
{
    char pad[0x94];
    float m_value;
    float GetClamped() const;
};

extern float g_min_007b6560;
extern float g_max_007b6560;

float S_func_007b6560::GetClamped() const
{
    float v = m_value;
    if (g_min_007b6560 < v)
    {
        if (v >= g_max_007b6560)
            return g_min_007b6560;
        return v;
    }
    return g_min_007b6560;
}
