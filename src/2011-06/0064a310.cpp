// from server: 75% by atomic.potato
extern "C" void __cdecl S_func_00411f60(int);

struct S_func_0064a310 {
    char pad0[184];
    int m_value;
    void f(int value);
};

void S_func_0064a310::f(int value)
{
    if (m_value != value) {
        m_value = value;
        S_func_00411f60(0xcccedc);
    }
}
