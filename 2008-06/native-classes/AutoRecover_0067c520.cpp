// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: no Ogre header path is known to resolve, so MeshPtr is declared locally.
// Layout is vtable + pRep + pUseCount = 12 bytes, which matches "ret 12" for a by-value argument.
// The imports are rgmain's operator= and virtual ~MeshPtr.
namespace Ogre {
class __declspec(dllimport) MeshPtr {
public:
    virtual ~MeshPtr();
    MeshPtr& operator=(const MeshPtr& r);
private:
    void* pRep;
    unsigned* pUseCount;
};
}

// INFERRED: __thiscall setter taking MeshPtr by value, which stores it at this+0xcc.
// The callee destroys the by-value argument, which explains the SEH frame and the ~MeshPtr call.
struct fn_0067c520_Obj {
    char pad[0xcc];
    Ogre::MeshPtr mesh;
};

extern "C" void __fastcall fn_0067c520(fn_0067c520_Obj* self, int unusedEdx, Ogre::MeshPtr m)
{
    self->mesh = m;
}
