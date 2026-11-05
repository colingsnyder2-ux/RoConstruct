// from server: 100% by atomic.potato
struct T4_004bfde0 {
    char pad[0xdc];
    void* m_dc;
};

extern "C" void* __fastcall get_004107f0(void*);
extern "C" int __cdecl check_004b37d0(void*);
extern "C" void __fastcall call_004b3880(void*);

void __cdecl f_004bfde0(void* arg)
{
    T4_004bfde0* p = (T4_004bfde0*)get_004107f0(arg);
    if (p == 0)
        return;
    void* q = p->m_dc;
    if (q == 0)
        return;
    if (check_004b37d0(q) == 0)
        return;
    call_004b3880(q);
}
