// from server: 55% by atomic.potato
struct S_func_006b4640 {
    char pad0[0x30];
    void* m_p;
    char pad1[0x60];
    float m_f;
    float f();
};

extern "C" void __fastcall sub_00763470(void* p);

float S_func_006b4640::f()
{
    void* p = m_p;
    if (p) {
        sub_00763470(p);
        return *(float*)((char*)p + 0x14);
    }
    return m_f;
}
