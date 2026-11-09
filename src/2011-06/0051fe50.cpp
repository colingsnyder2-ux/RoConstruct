// from server: 35% by atomic.potato
struct S_0051fe50 {
    char pad[0x748];
    unsigned int m_count;
    char pad2[4];
    int m_value;
    float f();
};

float S_0051fe50::f()
{
    unsigned int count = m_count;
    if (count == 0)
        return 0.0f;
    int value = m_value;
    float fv = (float)value;
    if (value < 0)
        fv += 4294967296.0f;
    float fc = (float)count;
    if ((int)count < 0)
        fc += 4294967296.0f;
    return fv / fc;
}
