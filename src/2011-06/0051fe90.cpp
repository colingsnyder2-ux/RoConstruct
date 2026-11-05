// from server: 35% by atomic.potato
struct S_0051fe90 {
    char pad[0x74c];
    unsigned int m_count;
    char pad2[0x754 - 0x74c - 4];
    int m_value;
    float f();
};

float S_0051fe90::f()
{
    if (m_count == 0)
        return 0.0f;
    float a = (float)m_value;
    if (m_value < 0)
        a += 4294967296.0f;
    float b = (float)m_count;
    if ((int)m_count < 0)
        b += 4294967296.0f;
    return a / b;
}
