// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: 0x0069ffae is a linker import thunk (jmp [__imp_...]) into rgmain.dll.
// The real body lives in rgmain.dll. This forwarder is a tail call through a
// dllimport member with the same thiscall signature, so /O2 emits a bare
// "jmp dword ptr [__imp_...]". The import symbol name is a codegen analog only.
namespace Ogre {
class MovableObjectFactory;

class __declspec(dllimport) MovableObjectImport {
public:
    void _notifyCreator(MovableObjectFactory* fact);
};

class MovableObject {
public:
    virtual void _notifyCreator(MovableObjectFactory* fact);
};

void MovableObject::_notifyCreator(MovableObjectFactory* fact)
{
    reinterpret_cast<MovableObjectImport*>(this)->_notifyCreator(fact);
}
}
