// from server: 74% by atomic.potato
struct UHistory {
    char pad_00[0x58];
    int m_count;
    char pad_5c[4];
    double m_value;
    char pad_68[0x70];
    unsigned int m_max;

    void f(unsigned int value);
};

double g_00a05248 = 4294967296.0;

void UHistory::f(unsigned int value)
{
    if (value > m_max)
        m_max = value;
    ++m_count;
    m_value += (double)value;
    if ((int)value < 0)
        m_value += g_00a05248;
}
