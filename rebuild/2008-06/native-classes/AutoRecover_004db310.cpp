// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: no headers were provided for this function, so every type below is a local
// reconstruction from the offsets in the disassembly.

namespace boost {
    void call_once(void (*func)(), long& flag);
}

namespace G3D {
    class System {
    public:
        static void* alignedMalloc(unsigned int bytes, unsigned int alignment);
        static void memset(void* dst, unsigned char value, unsigned int n);
    };
}

namespace RBX {
    // INFERRED: 12-byte mutex object located at registry + 0x10
    class GuidRegistryMutex {
        int pad[3];
    public:
        void lock();
        void unlock();
    };
}

struct TreeNode {
    TreeNode* left;
    TreeNode* parent;
    TreeNode* right;
};

// INFERRED: std::map-like tree: 0x18 bytes of unknown fields, then head and size
struct TreeMap {
    int pad[6];
    TreeNode* head;
    int size;
};

struct GuidRegistry {
    int unk0;
    int f4;
    void* f8;
    int fC;
    RBX::GuidRegistryMutex mutex; // 0x10
    TreeMap map1;                 // 0x1c
    TreeMap map2;                 // 0x3c
};

extern "C" int __fastcall fn_004d8f80(void* self, int unusedEdx);
extern "C" void __fastcall fn_004d83e0(TreeMap* self, int unusedEdx, TreeNode* where);
extern "C" void __fastcall fn_004d8470(TreeMap* self, int unusedEdx, TreeNode* where);
extern "C" void fn_004d98d0();

// INFERRED: call_once flag at 0x97274c and singleton pointer at 0x972734
extern "C" long g_registryOnceFlag;
extern GuidRegistry* g_registry;

namespace {
struct ScopedGuidLock {
    RBX::GuidRegistryMutex* m;
    explicit ScopedGuidLock(RBX::GuidRegistryMutex* mm) : m(mm) { m->lock(); }
    ~ScopedGuidLock() { m->unlock(); }
};
}

extern "C" void fn_004db310()
{
    boost::call_once(fn_004d98d0, g_registryOnceFlag);

    GuidRegistry* r = g_registry;
    ScopedGuidLock lock(&r->mutex);

    fn_004d8f80(r, 0);

    r->fC = 0x14;
    r->f4 = 0;
    r->f8 = G3D::System::alignedMalloc(0x50, 0x10);
    G3D::System::memset(r->f8, 0, r->fC * 4);

    // clear map1
    fn_004d83e0(&r->map1, 0, r->map1.head->parent);
    r->map1.head->parent = r->map1.head;
    r->map1.size = 0;
    r->map1.head->left = r->map1.head;
    r->map1.head->right = r->map1.head;

    // clear map2
    fn_004d8470(&r->map2, 0, r->map2.head->parent);
    r->map2.head->parent = r->map2.head;
    r->map2.size = 0;
    r->map2.head->left = r->map2.head;
    r->map2.head->right = r->map2.head;
}
