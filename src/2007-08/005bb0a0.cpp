// from server: 100% by colin
struct S_func_005bb0a0 {
    char pad0[0xf9];
    unsigned char m_f9;
    char pad1[0x111 - 0xfa];
    unsigned char m_111;
    char pad2[0x12c - 0x112];
    unsigned char m_12c;
    void f(void* arg);
};

extern "C" void __stdcall sub_00541a90(void* arg);

void S_func_005bb0a0::f(void* arg)
{
    sub_00541a90(arg);
    m_12c = 1;
    m_f9 = 1;
    m_111 = 1;
}
