// from server: 29% by atomic.potato
struct S_func_006fb660 {
    char pad[0xb4];
    float m_value;
    float f();
};

float S_func_006fb660::f()
{
    float lo = *(float*)0x00aab058;
    float hi = *(float*)0x00aab060;
    if (m_value > hi)
        return hi;
    if (m_value < lo)
        return m_value;
    return hi;
}
