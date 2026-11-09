// from server: 100% by atomic.potato
struct S_func_006f3030 {
    int m_0;
    int m_4;
    char pad8[16];
    int m_18;
    int m_1c;
    void f();
};

extern "C" void S_func_005980d0();

void S_func_006f3030::f()
{
    m_0 = 0x00aa9684;
    m_4 = 0x00aa967c;
    m_18 = 0x00aa9670;
    m_1c = 0x00aa9664;
    S_func_005980d0();
}
