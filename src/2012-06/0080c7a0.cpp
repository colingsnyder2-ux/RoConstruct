// from server: 68% by atomic.potato
struct S_func_0080c7a0 {
    char pad0[0x244];
    int m_field244;
    void f(int);
};

extern "C" void __stdcall sub_00414da0(void*);

void S_func_0080c7a0::f(int a)
{
    if (m_field244 != a) {
        m_field244 = a;
        sub_00414da0((void*)0x00e4fc44);
        sub_00414da0((void*)0x00e4fde0);
    }
}
