// from server: 100% by colin
struct S_func_005bbc20 {
    char pad0[0x150];
    unsigned char m_field;
    void f(unsigned char value);
};

void S_func_005bbc20::f(unsigned char value)
{
    if (m_field != value) {
        m_field = value;
        extern void __stdcall sub_00444710(unsigned int);
        sub_00444710(0x8c67dc);
    }
}
