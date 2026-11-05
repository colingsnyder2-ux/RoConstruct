// from server: 100% by tester
struct S {
    char pad[0x294];
    int m_294;
    int m_298;
    S* f(int);
};

extern "C" void __stdcall sub_005f9e70();
extern "C" void (__cdecl *p_free)(void*);

S* S::f(int a)
{
    sub_005f9e70();
    m_294 = 0x7a4cac;
    int* p = (int*)m_298;
    int v = p[1];
    *(int*)(v + (int)this + 0x298) = 0x7a4ca4;
    if (a & 1) {
        p_free(this);
    }
    return this;
}
