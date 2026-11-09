// from server: 75% by atomic.potato
struct S_func_0064a340
{
    int pad0[47];
    int m_value;
    void f(int value);
};

extern "C" void __cdecl f_00411f60(int);

void S_func_0064a340::f(int value)
{
    if (m_value != value)
    {
        m_value = value;
        f_00411f60(0x00cccf44);
    }
}
