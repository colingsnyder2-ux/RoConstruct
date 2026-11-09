// from server: 100% by atomic.potato
struct DxUserInput
{
    char pad0[360];
    int m_value;
    void f(int value, unsigned char enabled);
};

void DxUserInput::f(int value, unsigned char enabled)
{
    m_value = enabled ? value : 0;
}
