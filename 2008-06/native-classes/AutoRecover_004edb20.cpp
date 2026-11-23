// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: best-effort draft. Types and the registry layout are guessed from the disassembly. It has not been compiled or diffed.

extern "C" {
void __cdecl fn_00557330(void (*once)(void), long* flag);
int __fastcall fn_00563090(void* mutex, int unusedEdx);
int __fastcall fn_005630e0(void* mutex, int unusedEdx);
int __fastcall fn_004e9070(void* self, int unusedEdx, int a1, int a2);
int __fastcall fn_004d7dc0(void* self, int unusedEdx);
int __fastcall fn_004e5c70(void* self, int unusedEdx, int a1);
int __fastcall fn_004e7450(void* self, int unusedEdx, int a1, int a2);
int __fastcall fn_004e5c10(void* self, int unusedEdx, int a1);
int __fastcall fn_004f4cb0(void* self, int unusedEdx, int a1, int a2);
int fn_006a0920(int a1);
int fn_004ec220(void);
void fn_004d9750(void);
void* __cdecl fn_00508580(unsigned size, unsigned align);
void __cdecl fn_00508a30(void* p, unsigned char v, unsigned n);
int __cdecl fn_00515780(int lo, int hi);
void __fastcall fn_00598fa0(void* slot, int unusedEdx, void* p);
void __fastcall fn_0045ad90(void* self, int unusedEdx);
}

struct RegNode {
    unsigned key0;
    unsigned key1;
    char pad[0x10];
    RegNode* next;
};

struct Registry {
    char pad0[8];
    RegNode** buckets;
    unsigned bucketCount;
    char mutex[0x4c];
    int counter;
};

extern long g_registryOnce;
extern Registry* g_registry;

extern "C" void* fn_004edb20(int a0, unsigned key)
{
    Registry* r = g_registry;
    fn_00557330(fn_004d9750, &g_registryOnce);
    fn_00563090(r->mutex, 0);

    void* result = 0;
    RegNode* n = r->buckets[key % r->bucketCount];
    while (n) {
        if (n->key0 == key && n->key1 == key)
            break;
        n = n->next;
    }
    if (!n) {
        void* mem = fn_00508580(0x28, 0x10);
        fn_00508a30(mem, 0, 0x28);
        fn_004e9070(r, 0, 0, 0);
        fn_004d7dc0(0, 0);
    }

    n = r->buckets[key % r->bucketCount];
    while (n) {
        if (n->key0 == key && n->key1 == key)
            break;
        n = n->next;
    }
    void* sub = (char*)n + 8;
    if (!fn_004e5c70(sub, 0, a0)) {
        fn_004e7450(sub, 0, a0, 0);
    }
    int arr = fn_004e5c10(sub, 0, a0);
    int idx = fn_00515780(0, 3);
    void** slot = (void**)(arr + idx * 4);
    if (!*slot) {
        int mem = fn_006a0920(0x8c);
        int obj = mem ? fn_004f4cb0((void*)mem, 0, a0, key) : 0;
        fn_00598fa0(slot, 0, (void*)obj);
        result = (void*)obj;
        r->counter++;
        if (r->counter % 100 == 0)
            fn_004ec220();
    } else {
        result = *slot;
    }
    fn_005630e0(r->mutex, 0);
    return result;
}
