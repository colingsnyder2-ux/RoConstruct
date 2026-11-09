// from server: 45% by colin
struct S_func_00459ce0 {
    void* m_vtable;
    int m_arg;
    char pad8[4];
    void m_sub(int);
    S_func_00459ce0(int);
};

extern "C" void __stdcall sub_0047ad80(void*, int);

S_func_00459ce0::S_func_00459ce0(int arg)
{
    m_vtable = (void*)0x79362c;
    m_arg = arg;
    sub_0047ad80(&pad8[0], 0xa00000);
}
