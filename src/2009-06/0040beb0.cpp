// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct S_func_0040beb0 {
    void* m_vtbl0;
    char pad1[0x10];
    void* m_vtbl14;
    void* m_vtbl18;
    char pad2[4];
    void* m_vtbl20;
    S_func_0040beb0* f(unsigned int flag);
};

extern "C" void __cdecl sub_005d2b60();
extern "C" void __cdecl sub_00718a32(void* p);

S_func_0040beb0* S_func_0040beb0::f(unsigned int flag)
{
    m_vtbl0 = (void*)0x8ad73c;
    m_vtbl14 = (void*)0x8ad730;
    m_vtbl18 = (void*)0x8ad728;
    m_vtbl20 = (void*)0x8ad720;
    sub_005d2b60();
    if (flag & 1) {
        sub_00718a32(this);
    }
    return this;
}
