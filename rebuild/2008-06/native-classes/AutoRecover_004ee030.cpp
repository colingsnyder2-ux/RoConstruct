// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: simplified recovery; registry layout and helper types guessed from the disassembly.
extern "C" int __fastcall fn_004e9210(void* self, int unusedEdx, int a1, int a2);
extern "C" int __fastcall fn_004d7e30(void* self, int unusedEdx);
extern "C" int __fastcall fn_004e5cd0(void* self, int unusedEdx, int a1);
extern "C" int __fastcall fn_004e7630(void* self, int unusedEdx, int a1, int a2);
extern "C" int __fastcall fn_004e5d30(void* self, int unusedEdx, int a1);
extern "C" int fn_006a0920(int a1);
extern "C" int fn_004ec630(void);
extern "C" void __fastcall fn_004f7780(void* self, int unusedEdx, int a1, int a2);
extern "C" void fn_00557330(void (*f)(), long* flag);
extern "C" void __fastcall fn_00563090(void* self, int unusedEdx);
extern "C" void __fastcall fn_005630e0(void* self, int unusedEdx);
extern "C" void* __cdecl fn_00508580(unsigned size, unsigned align);
extern "C" void __cdecl fn_00508a30(void* p, unsigned char v, unsigned n);
extern "C" void __fastcall fn_00598fa0(void* self, int unusedEdx, void* p);
extern "C" void __fastcall fn_0045ad90(void* self, int unusedEdx);

struct Registry {
    char pad0[8];
    unsigned** buckets;   // 0x08
    unsigned count;       // 0x0c
    char mutex[1];        // 0x10
    char pad1[0x5c - 0x11];
    int counter;          // 0x5c
};

extern Registry* g_registry;   // 0x972738
extern long g_once;            // 0x972750
extern "C" void fn_004d9930();

extern "C" void* fn_004ee030(int a1, unsigned key)
{
    fn_00557330(fn_004d9930, &g_once);
    Registry* r = g_registry;
    fn_00563090(r->mutex, 0);

    unsigned* n = r->buckets[key % r->count];
    while (n && !(n[0] == key && n[1] == key))
        n = (unsigned*)n[6];
    if (!n) {
        void* mem = fn_00508580(0x28, 0x10);
        fn_00508a30(mem, 0, 0x28);
        fn_004e9210(r, 0, (int)&key, (int)mem);
        fn_004d7e30(mem, 0);
    }

    n = r->buckets[key % r->count];
    while (n && !(n[0] == key && n[1] == key))
        n = (unsigned*)n[6];

    void* slot = n + 2;
    if (!fn_004e5cd0(slot, 0, a1)) {
        fn_004e7630(slot, 0, a1, 0);
    }
    int* p = (int*)fn_004e5d30(slot, 0, a1);
    void* result = (void*)*p;
    if (!result) {
        void* mem = (void*)fn_006a0920(0x8c);
        result = 0;
        if (mem) {
            fn_004f7780(mem, 0, a1, (int)key);
            result = mem;
        }
        fn_00598fa0(p, 0, result);
        if (++r->counter % 100 == 0)
            fn_004ec630();
    }
    fn_005630e0(r->mutex, 0);
    return result;
}
