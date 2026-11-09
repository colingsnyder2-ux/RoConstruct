// from server: 100% by atomic.potato
struct S_func_006dbf60 {
    int m_0;
    int m_4;
    char pad8[16];
    int m_18;
    int m_1c;
    void f();
};

extern "C" void __cdecl sub_00637b00();

int g_009d9c2c;
int g_009d9c20;
int g_009d9c14;
int g_009d9c0c;

void S_func_006dbf60::f()
{
    m_0 = (int)&g_009d9c2c;
    m_4 = (int)&g_009d9c20;
    m_18 = (int)&g_009d9c14;
    m_1c = (int)&g_009d9c0c;
    sub_00637b00();
}
