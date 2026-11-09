// from server: 100% by atomic.potato
extern "C" void __cdecl Function_008daac0();

struct S_func_008e5c80
{
    int m_00;
    int m_04;
    char pad_08[16];
    int m_18;
    int m_1c;
    char pad_20[96];
    int m_80;
    int m_84;
    void f();
};

void S_func_008e5c80::f()
{
    m_00 = 0x00BECAEC;
    m_04 = 0x00BECAE0;
    m_18 = 0x00BECAD4;
    m_1c = 0x00BECAC8;
    m_80 = 0x00BECAB8;
    m_84 = 0x00BECA8C;
    Function_008daac0();
}
