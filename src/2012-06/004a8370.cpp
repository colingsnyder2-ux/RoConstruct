// from server: 100% by atomic.potato
struct DxUserInput
{
    char pad0[0xb8];
    unsigned char m_flag;
    char pad1[0x1b8 - 0xb9];
    int m_value;
    bool f(int value);
};

extern "C" int __cdecl sub_4AD070(int value);

bool DxUserInput::f(int value)
{
    if (m_value != 0 && value == m_value)
        return true;
    return ((unsigned char*)(sub_4AD070(value) + (int)this + 0xb8))[0] >> 7;
}
