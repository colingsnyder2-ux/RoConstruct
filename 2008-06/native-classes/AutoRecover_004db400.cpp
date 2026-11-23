// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: layouts below come from the disassembly only; the real owner class is unknown.

namespace RBX {
struct GuidRegistryMutex {
    void lock();
    void unlock();
};
}

namespace G3D {
struct System {
    static void* alignedMalloc(unsigned int bytes, unsigned int alignment);
    static void memset(void* dst, unsigned char value, unsigned int n);
};
}

namespace boost {
void call_once(void (*func)(), long& flag);
}

extern "C" int __fastcall fn_004d8ff0(void* self, int unusedEdx);
extern "C" void __fastcall fn_004d83e0(void* tree, int unusedEdx, void* root);
extern "C" void __fastcall fn_004d8470(void* tree, int unusedEdx, void* root);

// INFERRED: call_once initializer at 0x4d9930, once flag at 0x972750, instance pointer at 0x972738.
extern "C" void fn_004d9930();
extern long g_registryOnceFlag_00972750;

struct TreeNode {
    TreeNode* left;
    TreeNode* parent;
    TreeNode* right;
};

struct Registry {
    char pad0[4];
    int field4;
    void* buckets;
    unsigned int bucketCount;
    RBX::GuidRegistryMutex mutex;      // 0x10
    char pad11[0x1c - 0x11];
    char treeA[0x18];                  // 0x1c
    TreeNode* headA;                   // 0x34
    int sizeA;                         // 0x38
    char treeB[0x18];                  // 0x3c
    TreeNode* headB;                   // 0x54
    int sizeB;                         // 0x58
};

extern Registry* g_registry_00972738;

struct ScopedLock {
    RBX::GuidRegistryMutex* m;
    bool locked;
    explicit ScopedLock(RBX::GuidRegistryMutex* mm) : m(mm), locked(false) {
        m->lock();
        locked = true;
    }
    ~ScopedLock() {
        if (locked)
            m->unlock();
    }
};

extern "C" void fn_004db400()
{
    boost::call_once(fn_004d9930, g_registryOnceFlag_00972750);
    Registry* r = g_registry_00972738;
    ScopedLock lock(&r->mutex);

    fn_004d8ff0(r, 0);

    r->bucketCount = 0x14;
    r->field4 = 0;
    r->buckets = G3D::System::alignedMalloc(0x50, 0x10);
    G3D::System::memset(r->buckets, 0, r->bucketCount * 4);

    fn_004d83e0(r->treeA, 0, r->headA->parent);
    r->headA->parent = r->headA;
    r->sizeA = 0;
    r->headA->left = r->headA;
    r->headA->right = r->headA;

    fn_004d8470(r->treeB, 0, r->headB->parent);
    r->headB->parent = r->headB;
    r->sizeB = 0;
    r->headB->left = r->headB;
    r->headB->right = r->headB;
}
