// from server: 100% by colin
struct S_func_0046a4b0 {
    unsigned short m_a;
    unsigned short m_b;
    int m_p;
    int m_x8;
    int m_xc;
    int m_x10;
    void f();
};

extern "C" void __cdecl sub_006a094a(int);

void S_func_0046a4b0::f()
{
    m_x10 = 0;
    if (m_p != 0) {
        sub_006a094a(m_p);
        m_p = 0;
    }
    m_x8 = 0;
    m_xc = 0;
    m_a = 0;
    m_b = 0x4e4;
}
