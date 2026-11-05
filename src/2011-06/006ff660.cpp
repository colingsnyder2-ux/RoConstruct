// from server: 91% by atomic.potato
struct S_func_006ff660 {
    char pad0[0x34];
    void* m_ptr34;
    char pad1[0x74 - 0x38];
    char m_buf74[0x24];
    void* f(void* arg);
};

extern "C" void __fastcall sub_007b8e60(void* p);
extern "C" void __fastcall sub_00540050(void* dst, void* src);
extern "C" void __cdecl sub_006ccec0(void* dst, void* src);

void* S_func_006ff660::f(void* arg)
{
    char local[0x24];
    void* p = m_ptr34;
    void* src;
    if (p != 0) {
        sub_007b8e60(p);
        src = (char*)p + 0x18;
    } else {
        src = m_buf74;
    }
    sub_00540050(local, src);
    sub_006ccec0(arg, local);
    return arg;
}
