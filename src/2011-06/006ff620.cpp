// from server: 51% by atomic.potato
struct S_func_006ff620 {
    char pad0[0x34];
    void* m_p34;
    char pad1[0x98 - 0x38];
    float m_f98;
    float f();
};

extern "C" void __stdcall sub_007b8e60();

float S_func_006ff620::f()
{
    void* p = m_p34;
    if (p) {
        sub_007b8e60();
        return *(float*)((char*)p + 0x14);
    }
    return m_f98;
}
