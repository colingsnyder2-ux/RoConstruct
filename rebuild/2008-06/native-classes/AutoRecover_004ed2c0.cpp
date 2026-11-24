// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: structure is a loose analog; the real types are nested hash tables of
// ref-counted pointers plus two std::map-like trees, all cleared under a registry mutex.
#include <windows.h>

extern "C" void fn_00557330(void (*init)(), long* flag);
extern "C" void __fastcall fn_00563090(void* mutex, int unusedEdx);
extern "C" void __fastcall fn_005630e0(void* mutex, int unusedEdx);
extern "C" void fn_004d9810();
extern "C" long g_00972744;
extern "C" void* g_0097272c;

struct RefCountBase {
    virtual void destroy();
    virtual void dispose(int del);
};
struct RefNode { RefNode* next; };
struct RefCounted {
    void* vtbl;
    long count;
    RefNode* head;
};

// INFERRED: release one shared slot (InterlockedDecrement on count, free node list, delete)
static void releaseSlot(RefCounted** slot)
{
    RefCounted* rc = *slot;
    if (rc && rc->count == 1) {
        if (InterlockedDecrement(&rc->count) == 0) {
            RefNode* n = rc->head;
            while (n) {
                RefNode* next = n->next;
                operator delete(n);
                n = next;
            }
            if (*slot)
                (*(void (__fastcall **)(void*, int))(*(void***)*slot))(*slot, 1);
        }
        *slot = 0;
    }
}

struct Registry {
    char pad0[8];
    void** buckets;
    int bucketCount;
    char mutex[1];
};

struct TreeNode {
    char pad[0x10];
    RefCounted* a;
};

extern "C" void fn_004ed2c0()
{
    fn_00557330(fn_004d9810, &g_00972744);
    Registry* reg = (Registry*)g_0097272c;
    void* mutex = (char*)reg + 0x10;
    fn_00563090(mutex, 0);

    // INFERRED: walk outer hash buckets, then each entry's inner buckets, releasing slots
    for (int i = 0; i < reg->bucketCount; ++i) {
        char* outer = (char*)reg->buckets[i];
        if (!outer)
            continue;
        void** inner = *(void***)(outer + 0x10);
        int innerCount = *(int*)(outer + 0x14);
        for (int j = 0; j < innerCount; ++j) {
            char* node = (char*)inner[j];
            if (node)
                releaseSlot((RefCounted**)(node + 0x10));
        }
    }

    // INFERRED: two trees at +0x34 / +0x54, iterate and release slot at +0x1c / +0x24
    char* base = (char*)reg;
    for (char* n = **(char***)(base + 0x34); n != *(char**)(base + 0x34);
         n = *(char**)n)
        releaseSlot((RefCounted**)(n + 0x1c));
    for (char* n = **(char***)(base + 0x54); n != *(char**)(base + 0x54);
         n = *(char**)n)
        releaseSlot((RefCounted**)(n + 0x24));

    fn_005630e0(mutex, 0);
}
