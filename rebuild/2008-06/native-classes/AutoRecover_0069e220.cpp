// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: no class headers were available, so this uses raw offsets on an opaque object.
// INFERRED: the callee names and signatures below follow the fn_<addr> convention.
// INFERRED: the SEH unwind table is left to /EHsc and not reproduced by hand.
#include <new>

struct RbxSceneManager;

extern "C" void __fastcall fn_00698890(RbxSceneManager* self, int unusedEdx); // clearScene
extern "C" void __fastcall fn_006987c0(RbxSceneManager* self, int unusedEdx); // destroyAllCameras
extern "C" void __fastcall fn_0046b070(void* self, int unusedEdx);            // inner map dtor
extern "C" void __fastcall fn_0068d1a0(void* iter, int unusedEdx);            // const_iterator::_Inc
extern "C" void __fastcall fn_00693970(void* tree, int unusedEdx, void* node); // _Tree::_Erase

// INFERRED: imported destructors (std::string dtor and Ogre::SceneManager dtor).
extern "C" __declspec(dllimport) void __fastcall fn_imp_string_dtor(void* self, int unusedEdx);
extern "C" __declspec(dllimport) void __fastcall fn_imp_SceneManager_dtor(void* self, int unusedEdx);
// INFERRED: imported vtable symbol of Ogre::QueuedRenderableVisitor (address is stored).
extern "C" __declspec(dllimport) char rgmain_vtbl_QueuedRenderableVisitor[];

// INFERRED: unknown vtables of local classes (RbxSceneManager, shared-ptr holder, visitor base).
extern "C" char g_0084ed34[];
extern "C" char g_0084ec3c[];
extern "C" char g_0084e9a4[];

typedef void (__fastcall *VFn1)(void* self, int unusedEdx, int arg);
typedef void (__fastcall *VFn0)(void* self, int unusedEdx);

extern "C" void __fastcall fn_0069e220(RbxSceneManager* self, int unusedEdx)
{
    char* base = reinterpret_cast<char*>(self);
    *reinterpret_cast<void**>(base) = g_0084ed34;

    fn_00698890(self, 0);
    fn_006987c0(self, 0);

    // Destroy the map values stored in each node of the tree at +0x4268.
    char* tree = base + 0x4268;
    void* it = **reinterpret_cast<void***>(base + 0x4280);
    for (;;)
    {
        void* head = *reinterpret_cast<void**>(tree + 0x18);
        if (it == head)
            break;
        void* val = *reinterpret_cast<void**>(reinterpret_cast<char*>(it) + 0x28);
        if (val)
        {
            fn_0046b070(val, 0);
            ::operator delete(val);
        }
        fn_0068d1a0(&it, 0);
    }

    // Tree clear
    void** head = *reinterpret_cast<void***>(tree + 0x18);
    fn_00693970(tree, 0, head[1]);
    head = *reinterpret_cast<void***>(tree + 0x18);
    head[1] = head;
    head = *reinterpret_cast<void***>(tree + 0x18);
    *reinterpret_cast<int*>(tree + 0x1c) = 0;
    head[0] = head;
    head = *reinterpret_cast<void***>(tree + 0x18);
    head[2] = head;

    // Owned object with virtual deleting destructor in slot 0.
    void* obj = *reinterpret_cast<void**>(base + 0x8be8);
    if (obj)
    {
        void** vt = *reinterpret_cast<void***>(obj);
        reinterpret_cast<VFn1>(vt[0])(obj, 0, 1);
    }

    // Embedded QueuedRenderableVisitor.
    *reinterpret_cast<void**>(base + 0x8bf0) = g_0084e9a4;
    *reinterpret_cast<void**>(base + 0x8bf0) = rgmain_vtbl_QueuedRenderableVisitor;

    // Ref-counted shared pointer member.
    void* sp = base + 0x8bd8;
    int* rc = *reinterpret_cast<int**>(base + 0x8be0);
    *reinterpret_cast<void**>(sp) = g_0084ec3c;
    if (rc)
    {
        --*rc;
        if (*rc == 0)
        {
            void** vt = *reinterpret_cast<void***>(sp);
            reinterpret_cast<VFn0>(vt[1])(sp, 0);
        }
    }

    fn_imp_string_dtor(base + 0x8bbc, 0);
    fn_imp_SceneManager_dtor(self, 0);
}
