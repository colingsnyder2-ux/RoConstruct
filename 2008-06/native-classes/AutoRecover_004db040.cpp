// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: no headers were provided, so every type below is declared locally to match the disassembly offsets.

namespace RBX {
class GuidRegistryMutex {
public:
    void lock();
    void unlock();
private:
    char pad[12];
};
}

namespace G3D {
class System {
public:
    static void* alignedMalloc(unsigned int bytes, unsigned int alignment);
    static void memset(void* dst, unsigned char value, unsigned int n);
};
}

namespace boost {
void call_once(void (*f)(), long& flag);
}

struct TreeNode {
    TreeNode* left;
    TreeNode* parent;
    TreeNode* right;
};

// INFERRED: std::map-like tree layout; the head pointer is at +0x18 and the size at +0x1c.
struct TreeMap {
    char pad[0x18];
    TreeNode* head;
    unsigned int size;
};

// INFERRED: the singleton object whose address is stored at 0x972728.
struct GuidRegistryLike {
    int pad0;
    int f4;
    void* buffer;
    int capacity;
    RBX::GuidRegistryMutex mutex;
    TreeMap mapA;   // +0x1c
    TreeMap mapB;   // +0x3c
};

extern "C" void fn_004d97b0();
extern "C" int __fastcall fn_004d8e30(void* self, int unusedEdx);
// _Tree::_Erase(node), __thiscall
extern "C" void __fastcall fn_004d83e0(void* self, int unusedEdx, TreeNode* node);
extern "C" void __fastcall fn_004d8470(void* self, int unusedEdx, TreeNode* node);

// INFERRED: globals at fixed addresses, named by address.
extern "C" long g_00972740;
extern "C" GuidRegistryLike* g_00972728;

namespace {
struct ScopedMutexLock {
    RBX::GuidRegistryMutex* m;
    explicit ScopedMutexLock(RBX::GuidRegistryMutex* mm) : m(mm) { m->lock(); }
    ~ScopedMutexLock() { m->unlock(); }
};
}

extern "C" void fn_004db040()
{
    boost::call_once(fn_004d97b0, g_00972740);
    GuidRegistryLike* reg = g_00972728;

    ScopedMutexLock guard(&reg->mutex);

    fn_004d8e30(reg, 0);
    reg->capacity = 0x14;
    reg->f4 = 0;
    reg->buffer = G3D::System::alignedMalloc(0x50, 0x10);
    G3D::System::memset(reg->buffer, 0, reg->capacity * 4);

    TreeMap* a = &reg->mapA;
    fn_004d83e0(a, 0, a->head->parent);
    a->head->parent = a->head;
    a->size = 0;
    a->head->left = a->head;
    a->head->right = a->head;

    TreeMap* b = &reg->mapB;
    fn_004d8470(b, 0, b->head->parent);
    b->head->parent = b->head;
    b->size = 0;
    b->head->left = b->head;
    b->head->right = b->head;
}
