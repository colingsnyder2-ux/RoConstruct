// from server: 63% by atomic.potato
extern "C" int __cdecl sub_007f37b2(int, const char*);

struct DropperTool_006b3980 {
    char pad0[156];
    int m_value;
    int __cdecl f(char value);
};

int DropperTool_006b3980::f(char value)
{
    if (!m_value)
        return 0;
    return sub_007f37b2(m_value, &value) - 0x24;
}
