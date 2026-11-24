// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: layouts guessed from the disassembly; the registry is a singleton with a mutex
// at +0x10, a hash container at +8/+0xc, and two std::map-like trees at +0x34 and +0x54.
#include <windows.h>

extern "C" int __fastcall fn_004e6c30(void* self, int unusedEdx, int a1, int a2);
extern "C" int __fastcall fn_004e6c90(void* self, int unusedEdx, int a1, int a2);
extern "C" void fn_00557330(void (*once)(), long* flag);
extern "C" void __fastcall fn_00563090(void* mutex);
extern "C" void __fastcall fn_005630e0(void* mutex);
extern "C" void fn_004d9750();

struct RefBase { virtual void destroy(int del) = 0; };
struct RefNode { RefBase* obj; RefNode* next; };
struct RefCount { void* vt; long count; RefNode* nodes; };

static void releaseRef(RefCount** slot)
{
    RefCount* rc = *slot;
    if (!rc) return;
    if (rc->count != 1) { *slot = 0; return; }
    if (InterlockedDecrement(&rc->count) == 0) {
        RefNode* n = rc->nodes;
        while (n) {
            RefNode* cur = n;
            cur->obj->destroy(0);
            n = n->next;
            operator delete(cur);
        }
        (*(void (**)(RefCount*, int))(*(void***)rc))(rc, 1);
    }
    *slot = 0;
}

struct TreeNode {
    TreeNode* left; TreeNode* parent; TreeNode* right;
};

struct Registry {
    char pad0[8];
    void** buckets;      // +8
    int bucketCount;     // +0xc
    char mutex[0x10];    // +0x10 (lock object)
};

extern Registry* g_registry;   // 0x972724
extern long g_registryOnce;    // 0x97273c

extern "C" void fn_004ec220()
{
    fn_00557330(fn_004d9750, &g_registryOnce);
    Registry* r = g_registry;
    fn_00563090((char*)r + 0x10);

    void** buckets = r->buckets;
    int count = r->bucketCount;
    for (int i = 0; i < count; ++i) {
        char* entry = (char*)buckets[i];
        if (!entry) continue;
        RefCount** slots = (RefCount**)(entry + 0x10);
        for (int k = 0; k < 4; ++k)
            releaseRef(&slots[k]);
    }

    TreeNode* head = *(TreeNode**)((char*)r + 0x34);
    for (TreeNode* n = head->left; n != head; n = n->right)
        releaseRef((RefCount**)((char*)n + 0x1c));

    head = *(TreeNode**)((char*)r + 0x54);
    for (TreeNode* n = head->left; n != head; n = n->right)
        releaseRef((RefCount**)((char*)n + 0x24));

    fn_005630e0((char*)r + 0x10);
}
