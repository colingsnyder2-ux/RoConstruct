// from server: 40% by atomic.potato
struct S_func_007b65a0 {
    char pad[152];
    float m_value;
    float f();
};

float S_func_007b65a0::f()
{
    float value = m_value;
    if (value <= 0.0f)
        return 0.0f;
    if (value >= 1.0f)
        return 0.0f;
    return value;
}
