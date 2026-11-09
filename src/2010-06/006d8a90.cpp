// from server: 45% by atomic.potato
extern float g_00a1f624;

struct S_func_006d8a90
{
    char pad[172];
    float m_depth;
    float f();
};

float S_func_006d8a90::f()
{
    float depth = m_depth;
    if (depth > 0.0f)
    {
        if (depth < g_00a1f624)
            return depth;
    }
    return 0.0f;
}
