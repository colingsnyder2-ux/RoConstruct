// from server: 100% by atomic.potato
struct S_007aa600 {
    int m_0;
    int m_4;
    char pad8[16];
    int m_18;
    int m_1c;
    void f();
};

void S_007aa600::f()
{
    m_0 = 0x00bb6a44;
    m_4 = 0x00bb6a3c;
    m_18 = 0x00bb6a30;
    m_1c = 0x00bb6a24;
    extern void g();
    g();
}
