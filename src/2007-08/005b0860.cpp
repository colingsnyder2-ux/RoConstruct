// from server: 100% by colin
struct S_func_005b0860 {
    char pad0[0x10];
    int m_10;
    int m_14;
    char pad1[0x14];
    int m_2c;
    char pad2[0x14];
    int m_44;
    char pad3[0x14];
    int m_5c;
    char pad4[0x14];
    int m_74;
    char pad5[0x14];
    int m_8c;
    char pad6[0x58];
    int m_e8;
    void f();
};

extern "C" void __stdcall sub_5b03f0();

void S_func_005b0860::f()
{
    *(int*)((char*)this + 0) = 0x7b672c;
    *(int*)((char*)this + 4) = 0x7b6724;
    m_10 = 0x7b671c;
    m_14 = 0x7b670c;
    m_2c = 0x7b66fc;
    m_44 = 0x7b66ec;
    m_5c = 0x7b66dc;
    m_74 = 0x7b66cc;
    m_8c = 0x7b66bc;
    m_e8 = 0x7b66a4;
    sub_5b03f0();
}
