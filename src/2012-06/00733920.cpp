// from server: 82% by atomic.potato
struct S_func_00733920 {
    char pad0[0x84];
    char m_field84;
    char pad1[0xdd - 0x85];
    char m_fieldDD;
    void f(char);
    char sub_007338E0();
};

extern "C" void __stdcall sub_00684660(char);

extern "C" void __stdcall sub_00675C40();

void S_func_00733920::f(char arg)
{
    sub_00684660(arg);
    char r = sub_007338E0();
    if (r != m_fieldDD) {
        m_fieldDD = r;
        sub_00675C40();
    }
}
