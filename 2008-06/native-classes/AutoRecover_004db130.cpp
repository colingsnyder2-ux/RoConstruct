// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: layout from the disassembly offsets. Registry = singleton holding a hash bucket array
// (+4 count, +8 buckets, +0xc capacity), a mutex at +0x10 and two std::map-style trees at +0x1c / +0x3c.
struct TreeNode {
    TreeNode* left;
    TreeNode* parent;
    TreeNode* right;
};

struct Tree {
    int pad[6];
    TreeNode* head;
    int size;
};

struct Registry {
    int unused0;
    int count;
    void* buckets;
    int capacity;
    char mutex[12];
    Tree decals;
    Tree textures;
};

extern "C" {
void fn_004d9810();
void fn_00557330(void (*fn)(), long* flag);
void __fastcall fn_00563090(void* mutex, int unusedEdx);
void __fastcall fn_005630e0(void* mutex, int unusedEdx);
int __fastcall fn_004d8ea0(void* self, int unusedEdx);
void* fn_00508580(unsigned size, unsigned align);
void fn_00508a30(void* p, unsigned char value, unsigned count);
void __fastcall fn_004d83e0(Tree* self, int unusedEdx, TreeNode* root);
void __fastcall fn_004d8470(Tree* self, int unusedEdx, TreeNode* root);
extern Registry* g_registry_0097272c;
extern long g_registryOnce_00972744;
}

namespace {
struct Lock {
    void* m;
    explicit Lock(void* mutex) : m(mutex) { fn_00563090(m, 0); }
    ~Lock() { fn_005630e0(m, 0); }
};

void resetTree(Tree* t) {
    TreeNode* head = t->head;
    head->parent = head;
    t->size = 0;
    head->left = head;
    t->head->right = t->head;
}
}

extern "C" void fn_004db130()
{
    fn_00557330(fn_004d9810, &g_registryOnce_00972744);
    Registry* r = g_registry_0097272c;
    Lock lock(r->mutex);

    fn_004d8ea0(r, 0);
    r->capacity = 0x14;
    r->count = 0;
    r->buckets = fn_00508580(0x50, 0x10);
    fn_00508a30(r->buckets, 0, r->capacity * 4);

    fn_004d83e0(&r->decals, 0, r->decals.head->parent);
    resetTree(&r->decals);

    fn_004d8470(&r->textures, 0, r->textures.head->parent);
    resetTree(&r->textures);
}
