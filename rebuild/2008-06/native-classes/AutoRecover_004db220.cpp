// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: registry layout from offsets; globals named by address.
struct TreeNode { TreeNode* left; TreeNode* parent; TreeNode* right; };

extern "C" void __cdecl fn_00557330(void (__cdecl *init)(), long* flag); // boost::call_once
extern "C" void __cdecl fn_004d9870();                                   // once initializer
extern "C" void __fastcall fn_00563090(void* mutex, int unusedEdx);      // GuidRegistryMutex::lock
extern "C" void __fastcall fn_005630e0(void* mutex, int unusedEdx);      // GuidRegistryMutex::unlock
extern "C" int __fastcall fn_004d8f10(void* self, int unusedEdx);
extern "C" void* __cdecl fn_00508580(unsigned size, unsigned align);     // G3D::System::alignedMalloc
extern "C" void __cdecl fn_00508a30(void* p, unsigned char v, unsigned n); // G3D::System::memset
extern "C" void __fastcall fn_004d83e0(void* tree, int unusedEdx, TreeNode* root); // _Tree::_Erase (decal map)
extern "C" void __fastcall fn_004d8470(void* tree, int unusedEdx, TreeNode* root); // _Tree::_Erase (texture map)

extern char* g_registry_00972730;
extern long g_onceFlag_00972748;

namespace {
struct MutexGuard {
    void* m;
    explicit MutexGuard(void* mm) : m(mm) { fn_00563090(m, 0); }
    ~MutexGuard() { fn_005630e0(m, 0); }
};

inline void clearTree(char* tree, void (__fastcall *erase)(void*, int, TreeNode*))
{
    TreeNode* head = *(TreeNode**)(tree + 0x18);
    erase(tree, 0, head->parent);
    head = *(TreeNode**)(tree + 0x18);
    head->parent = head;
    head = *(TreeNode**)(tree + 0x18);
    *(int*)(tree + 0x1c) = 0;
    head->left = head;
    head = *(TreeNode**)(tree + 0x18);
    head->right = head;
}
}

extern "C" void fn_004db220()
{
    fn_00557330(fn_004d9870, &g_onceFlag_00972748);
    char* reg = g_registry_00972730;
    MutexGuard lock(reg + 0x10);

    fn_004d8f10(reg, 0);
    *(int*)(reg + 0xc) = 0x14;
    *(int*)(reg + 4) = 0;
    void* buf = fn_00508580(0x50, 0x10);
    *(void**)(reg + 8) = buf;
    fn_00508a30(buf, 0, *(int*)(reg + 0xc) * 4);

    clearTree(reg + 0x1c, fn_004d83e0);
    clearTree(reg + 0x3c, fn_004d8470);
}
