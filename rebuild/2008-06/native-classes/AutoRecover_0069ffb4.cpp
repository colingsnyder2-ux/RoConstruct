// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: The target at 0x0069ffb4 is only an import thunk (jmp dword ptr [__imp_...]).
// The original symbol is the import library's stub for the rgmain export. A plain
// source file cannot define that stub directly, so I tail-call a dllimport member
// of a helper type. This should compile to the same "jmp dword ptr [imp]" with
// ecx (this) passed through unchanged. I have not compiled it to check the bytes.
namespace Ogre {

class MovableObjectFactory;

// INFERRED: helper standing in for the real import target; the layout is unknown.
struct MovableObjectImport {
    __declspec(dllimport) MovableObjectFactory* _getCreatorImp(void) const;
};

class MovableObject {
public:
    virtual ~MovableObject() {}
    virtual MovableObjectFactory* _getCreator(void) const;
};

MovableObjectFactory* MovableObject::_getCreator(void) const
{
    return reinterpret_cast<const MovableObjectImport*>(this)->_getCreatorImp();
}

} // namespace Ogre
