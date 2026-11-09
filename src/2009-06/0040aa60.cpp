// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct S_func_0040aa60 {
    void* m_vtbl0;
    char pad1[0x10];
    void* m_vtbl14;
    void* m_vtbl18;
    char pad2[4];
    void* m_vtbl20;
    S_func_0040aa60* f(unsigned int flag);
};

extern "C" void __cdecl sub_005d2b60();
extern "C" void __cdecl sub_00718a32(void* p);

S_func_0040aa60* S_func_0040aa60::f(unsigned int flag)
{
    m_vtbl0 = (void*)0x8ad4c4;
    m_vtbl14 = (void*)0x8ad4b8;
    m_vtbl18 = (void*)0x8ad4b0;
    m_vtbl20 = (void*)0x8ad4a8;
    sub_005d2b60();
    if (flag & 1) {
        sub_00718a32(this);
    }
    return this;
}
