// from server: 100% by atomic.potato
struct S_func_0070c270 {
    int m_0;
    int m_4;
    char pad[16];
    int m_18;
    int m_1c;
    void f();
};

extern "C" void __declspec(noreturn) continuation();

void S_func_0070c270::f()
{
    m_0 = 0xba004c;
    m_4 = 0xba0040;
    m_18 = 0xba0034;
    m_1c = 0xba0028;
    continuation();
}
