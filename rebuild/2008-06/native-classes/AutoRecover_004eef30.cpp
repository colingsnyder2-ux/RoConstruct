// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: best-effort reconstruction, not compiled or diffed. Table layout is a guess from the disassembly.

extern "C" int __fastcall fn_004e96f0(void* self, int unusedEdx, int a1, int a2);
extern "C" int __fastcall fn_004d7e30(void* self, int unusedEdx);
extern "C" int __fastcall fn_004e5cd0(void* self, int unusedEdx, int a1);
extern "C" int __fastcall fn_004e7630(void* self, int unusedEdx, int a1, int a2);
extern "C" int __fastcall fn_004e5d30(void* self, int unusedEdx, int a1);
extern "C" int fn_006a0920(int a1);
extern "C" int fn_004ed2c0(void);
extern "C" void fn_00557330(void (*f)(), long* flag);
extern "C" void __fastcall fn_00563090(void* mutex, int unusedEdx);
extern "C" void __fastcall fn_005630e0(void* mutex, int unusedEdx);
extern "C" void __fastcall fn_004fd6b0(void* self, int unusedEdx, int vec, int type);
extern "C" void fn_004d9810(void);

// INFERRED: local stand-ins for the registry table and its hash nodes
struct Local_004eef30Node {
    unsigned key;
    unsigned key2;
    char value[0x10];
    Local_004eef30Node* next;
};

struct Local_004eef30Table {
    char pad[8];
    Local_004eef30Node** buckets;
    unsigned numBuckets;
    char mutex[0x4c];
    int counter;
};

extern Local_004eef30Table* g_0097272c;
extern long g_00972744;

extern "C" void* fn_004eef30(int vec, unsigned type)
{
    fn_00557330(fn_004d9810, &g_00972744);
    Local_004eef30Table* t = g_0097272c;
    fn_00563090(t->mutex, 0);

    Local_004eef30Node* n = t->buckets[type % t->numBuckets];
    for (; n; n = n->next)
        if (n->key == type && n->key2 == type)
            break;
    if (!n) {
        fn_004e96f0(t, 0, 0, 0);
        n = t->buckets[type % t->numBuckets];
        for (; n; n = n->next)
            if (n->key == type && n->key2 == type)
                break;
    }

    if (!fn_004e5cd0(n->value, 0, vec))
        fn_004e7630(n->value, 0, vec, 0);

    void** slot = (void**)fn_004e5d30(n->value, 0, vec);
    void* result = *slot;
    if (!result) {
        void* mem = (void*)fn_006a0920(0x8c);
        if (mem) {
            fn_004fd6b0(mem, 0, vec, (int)type);
            result = mem;
        }
        *slot = result;
        if (++t->counter % 100 == 0)
            fn_004ed2c0();
    }
    fn_005630e0(t->mutex, 0);
    return result;
}
