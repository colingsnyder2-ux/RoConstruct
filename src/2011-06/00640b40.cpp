// from server: 57% by atomic.potato
struct S_func_00640b40 {
    char pad0[0x44];
    S_func_00640b40* m_p44;

    int f(S_func_00640b40* p);
};

extern "C" void* __stdcall sub_80b2ea(void*, void*, void*, void*, void*);
extern "C" void* __stdcall sub_48d4d0(void*);
extern "C" void* __stdcall sub_4b17f0(void*);
extern "C" char __stdcall sub_4267d0(void*, void*);

int S_func_00640b40::f(S_func_00640b40* p)
{
    if (p != 0)
        return 0;
    S_func_00640b40* eax = p->m_p44;
    if (eax != 0) {
        void* ecx = eax->m_p44;
        if (ecx != 0) {
            sub_48d4d0(ecx);
        }
    } else {
        eax = p;
    }
    if (eax == 0)
        return 0;
    void* r = sub_80b2ea(eax, 0, (void*)0xc071f8, (void*)0xc0c3e0, 0);
    if (r == 0)
        return 0;
    void* r2 = sub_4b17f0(r);
    if (r2 == 0)
        return 0;
    void* ecx2 = p->m_p44;
    if (r2 != ecx2) {
        if (ecx2 == 0)
            return 0;
        if (!sub_4267d0(r2, ecx2))
            return 0;
    }
    return 1;
}
