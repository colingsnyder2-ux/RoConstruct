// from server: 100% by atomic.potato
struct S_func_007a1920 {
    char pad0[28];
    int m_1c;
    int m_20;
    int m_24;
    int m_28;
    S_func_007a1920* f();
};

extern "C" void func_007edbb0();

S_func_007a1920* S_func_007a1920::f()
{
    func_007edbb0();
    m_1c = 0;
    m_20 = 0;
    m_24 = 0;
    *(int*)this = (int)func_007edbb0;
    return this;
}
