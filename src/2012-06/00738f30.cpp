// from server: 68% by atomic.potato
struct S_func_00738f30 {
    char pad0[0x334];
    int m_field334;
    void f(int);
};

extern "C" void __stdcall sub_00414da0(int);

void S_func_00738f30::f(int a)
{
    if (m_field334 != a) {
        m_field334 = a;
        sub_00414da0(0xe3470c);
        sub_00414da0(0xe346b4);
    }
}
