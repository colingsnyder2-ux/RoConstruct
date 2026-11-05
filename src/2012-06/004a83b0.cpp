// from server: 100% by atomic.potato
struct DxUserInput
{
    char pad0[483];
    unsigned char m_enabled;
    char pad1[16];
    int m_value;
    int f(int value);
};

int DxUserInput::f(int value)
{
    if (m_enabled && value != m_value)
        return 1;
    return 0;
}
