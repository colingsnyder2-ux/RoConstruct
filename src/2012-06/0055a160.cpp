// from server: 100% by atomic.potato
struct S_func_0055a160
{
    char pad0[160];
    int m_value;
    void f(int *value);
};

extern "C" void __stdcall S_func_00414da0(int);

void S_func_0055a160::f(int *value)
{
    int v = *value;
    if (v != m_value)
    {
        m_value = v;
        S_func_00414da0(0x00e23970);
    }
}
