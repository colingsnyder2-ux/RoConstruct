// from server: 68% by atomic.potato
struct S_func_00738f60 {
    char pad0[0x364];
    int m_field364;
    void f(int);
};

extern "C" void __stdcall sub_00414da0(void*);

void S_func_00738f60::f(int a)
{
    if (m_field364 != a) {
        m_field364 = a;
        sub_00414da0((void*)0xe34514);
        sub_00414da0((void*)0xe346b4);
    }
}
