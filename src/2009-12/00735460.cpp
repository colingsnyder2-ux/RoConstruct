// from server: 51% by atomic.potato
struct S_func_00735460 {
    char pad0[0x30];
    void* m_ptr;
    char pad1[0x94 - 0x34];
    float m_val;
    float f();
};

extern "C" void __stdcall sub_007bbb60();

float S_func_00735460::f()
{
    void* p = m_ptr;
    if (p) {
        sub_007bbb60();
        return *(float*)((char*)p + 0x14);
    }
    return m_val;
}
