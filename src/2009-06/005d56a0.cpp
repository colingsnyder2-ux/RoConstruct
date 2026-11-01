// from server: 100% by atomic.potato
struct S_func_005d56a0 {
    void* m_vtbl0;
    char pad1[0x10];
    void* m_vtbl14;
    void* m_vtbl18;
    char pad2[4];
    void* m_vtbl20;
    S_func_005d56a0* f(unsigned int flag);
};

extern "C" void __cdecl sub_005d2b60();
extern "C" void __cdecl sub_00718a32(void* p);

S_func_005d56a0* S_func_005d56a0::f(unsigned int flag)
{
    m_vtbl0 = (void*)0x8d5354;
    m_vtbl14 = (void*)0x8d5348;
    m_vtbl18 = (void*)0x8d5340;
    m_vtbl20 = (void*)0x8d5338;
    sub_005d2b60();
    if (flag & 1) {
        sub_00718a32(this);
    }
    return this;
}
