// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: partial, unverified draft. Layout and iterator types come from the disassembly only. I did not compile or diff it.
#include <windows.h>

extern "C" void fn_00557330(void (*once)(), long* flag);   // boost::call_once
extern "C" void fn_004d9930();
extern "C" void __fastcall fn_00563090(void* mutex, int unusedEdx);   // GuidRegistryMutex::lock
extern "C" void __fastcall fn_005630e0(void* mutex, int unusedEdx);   // GuidRegistryMutex::unlock
extern "C" int __fastcall fn_004e6cf0(void* self, int unusedEdx, int a1, int a2);
extern "C" int __fastcall fn_004e6c90(void* self, int unusedEdx, int a1, int a2);

// INFERRED: refcounted holder whose slot is cleared when its count is 1
struct RefBase {
    virtual void destroy(int del) = 0;
    int pad;
    int count;
    struct Node* nodes;
};
struct Node {
    struct Dtor { virtual void v0(); virtual void release(); }* obj;
    Node* next;
};

struct Registry {
    int pad0[2];
    void** buckets;   // +8
    int nbuckets;     // +0xc
    char mutex[1];    // +0x10
};

extern "C" Registry* g_00972738;
extern "C" long g_00972750;

static void releaseSlot(void** slot)
{
    if (!*slot)
        return;
    int* rc = (int*)((char*)*slot + 4);
    if (*rc != 1)
        return;
    if (InterlockedDecrement((volatile LONG*)rc) == 0) {
        Node* n = ((RefBase*)*slot)->nodes;
        while (n) {
            n->obj->release();
            Node* next = n->next;
            operator delete(n);
            n = next;
        }
        if (*slot)
            ((RefBase*)*slot)->destroy(1);
    }
    *slot = 0;
}

extern "C" void fn_004ec630()
{
    fn_00557330(fn_004d9930, &g_00972750);
    Registry* reg = g_00972738;
    fn_00563090(reg->mutex, 0);

    for (int i = 0; i < reg->nbuckets; ++i) {
        char* e = (char*)reg->buckets[i];
        if (!e)
            continue;
        // INFERRED: inner hash table at e+8; each node's slot at +0x10 is released
        void** inner = *(void***)(e + 0x10);
        int n = *(int*)(e + 0x14);
        for (int j = 0; j < n; ++j) {
            char* ie = (char*)inner[j];
            if (ie)
                releaseSlot((void**)(ie + 0x10));
        }
    }
    // INFERRED: remaining +0x1c / +0x34 map walks release slots at +0x1c / +0x24
    fn_005630e0(reg->mutex, 0);
}
