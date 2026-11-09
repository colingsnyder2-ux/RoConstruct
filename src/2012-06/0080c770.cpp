// from server: 68% by atomic.potato
struct S_func_0080c770 {
    char pad0[0x214];
    int m_field214;
    void f(int);
};

extern "C" void __stdcall sub_414da0(void*);

void S_func_0080c770::f(int a)
{
    if (m_field214 != a) {
        m_field214 = a;
        sub_414da0((void*)0xe4fe38);
        sub_414da0((void*)0xe4fde0);
    }
}
