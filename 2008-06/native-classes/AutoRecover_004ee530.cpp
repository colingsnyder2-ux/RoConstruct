// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: unknown callees declared via fn_ externs; the structure is guessed from the disassembly and has not been compiled or diffed.
extern "C" {
void fn_00557330(void (*fn)(), long* flag);                       // boost::call_once, cdecl
int __fastcall fn_00563090(void* self, int unusedEdx);            // GuidRegistryMutex::lock
int __fastcall fn_005630e0(void* self, int unusedEdx);            // GuidRegistryMutex::unlock
void* fn_00508580(unsigned size, unsigned align);                 // G3D::System::alignedMalloc
void fn_00508a30(void* p, unsigned char v, unsigned n);           // G3D::System::memset
int __fastcall fn_004e93b0(void* self, int unusedEdx, int a1, int a2);
int __fastcall fn_004d7e30(void* self, int unusedEdx);
int __fastcall fn_004e5cd0(void* self, int unusedEdx, int a1);
int __fastcall fn_004e7630(void* self, int unusedEdx, int a1, int a2);
int __fastcall fn_004e5d30(void* self, int unusedEdx, int a1);
int fn_006a0920(int a1);
int fn_004eca60(void);
int __fastcall fn_004fa590(void* self, int unusedEdx, int a1, int a2);  // TorsoMesh ctor
void __fastcall fn_00598fa0(void* self, int unusedEdx, void* p);        // setPointer
void __fastcall fn_0045ad90(void* self, int unusedEdx);                 // zeroWeakPointers
void fn_006a1598(void* p, unsigned size, int count, void (__stdcall* ctor)(void*), void (__stdcall* dtor)(void*));
void fn_006a165b(void* p, unsigned size, int count, void (__stdcall* dtor)(void*));
extern long __stdcall InterlockedIncrement(long volatile*);
extern long __stdcall InterlockedDecrement(long volatile*);
extern char g_onceFlag_00972748;
void init_004d9870();
extern unsigned char* g_registry_00972730;
}

extern "C" void* fn_004ee530(int pos, unsigned key)
{
    unsigned char* reg = g_registry_00972730;
    fn_00557330(init_004d9870, (long*)&g_onceFlag_00972748);
    void* mtx = reg + 0x10;
    fn_00563090(mtx, 0);

    unsigned char** buckets = *(unsigned char***)(reg + 8);
    unsigned nb = *(unsigned*)(reg + 0xc);
    unsigned char* n = buckets[key % nb];
    while (n && !(*(unsigned*)n == key && *(unsigned*)(n + 4) == key))
        n = *(unsigned char**)(n + 0x18);

    if (!n) {
        void* tmp = fn_00508580(0x28, 0x10);
        fn_00508a30(tmp, 0, 0x28);
        fn_004e93b0(reg, 0, (int)&key, (int)&tmp);
        fn_004d7e30(&tmp, 0);
        buckets = *(unsigned char***)(reg + 8);
        nb = *(unsigned*)(reg + 0xc);
        n = buckets[key % nb];
        while (n && !(*(unsigned*)n == key && *(unsigned*)(n + 4) == key))
            n = *(unsigned char**)(n + 0x18);
    }

    void* entry = n + 8;
    if (!fn_004e5cd0(entry, 0, pos)) {
        char tmp2[4];
        fn_004e7630(entry, 0, pos, (int)tmp2);
    }
    int* slot = (int*)fn_004e5d30(entry, 0, pos);
    int* obj = (int*)*slot;
    if (!obj) {
        void* mem = (void*)fn_006a0920(0x8c);
        obj = 0;
        if (mem)
            obj = (int*)fn_004fa590(mem, 0, pos, key);
        fn_00598fa0(slot, 0, obj);
        int cnt = ++*(int*)(reg + 0x5c);
        if (cnt % 100 == 0) {
            int* held = (int*)*slot;
            if (held)
                InterlockedIncrement((long*)(held + 1));
            fn_004eca60();
            if (held && InterlockedDecrement((long*)(held + 1)) == 0) {
                fn_0045ad90(held, 0);
                ((void (__thiscall*)(void*, int))(*(void***)held)[0])(held, 1);
            }
        }
    }
    fn_005630e0(mtx, 0);
    return obj;
}
