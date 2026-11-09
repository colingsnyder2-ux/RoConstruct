// from server: 35% by atomic.potato
struct S_func_007b70d0 {
    char pad[0xa4];
    float m_value;
    float f();
};

float S_func_007b70d0::f()
{
    float v = m_value;
    if (*(float*)0xbb9610 < v)
        return *(float*)0xbb9610;
    if (v < *(float*)0xbb9880)
        return *(float*)0xbb9880;
    return v;
}
