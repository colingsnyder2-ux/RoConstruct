// from server: 41% by atomic.potato
float g_007136e0_limit = 0.0f;

struct S_func_007136e0 {
    char pad[168];
    float m_value;
    float f();
};

float S_func_007136e0::f()
{
    float value = m_value;
    if (value <= 0.0f)
        return 0.0f;
    if (value >= g_007136e0_limit)
        return 0.0f;
    return value;
}
