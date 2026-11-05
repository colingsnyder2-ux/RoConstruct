// from server: 32% by atomic.potato
struct S_func_0051f370 {
    unsigned short m_count;
    char pad0[618];
    unsigned char *m_data;
    int f();
};

int S_func_0051f370::f()
{
    unsigned int i;
    int result = 0;

    for (i = 0; i < (unsigned int)m_count; ++i) {
        if (*m_data)
            ++result;
        m_data += 0x1760;
    }

    return result;
}
