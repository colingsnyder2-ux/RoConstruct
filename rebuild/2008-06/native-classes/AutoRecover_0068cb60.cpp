// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
namespace Ogre {
class __declspec(dllimport) DefaultAxisAlignedBoxSceneQuery {
public:
    // INFERRED: imported from rgmain.dll (call [0x804848]); virtual dtor
    virtual ~DefaultAxisAlignedBoxSceneQuery();
};
}

void __cdecl operator delete(void*);

// Hand-written equivalent of the compiler's vector deleting destructor:
// qualified (non-virtual) dtor call through the import, then optional delete.
extern "C" Ogre::DefaultAxisAlignedBoxSceneQuery* __fastcall fn_0068cb60(
    Ogre::DefaultAxisAlignedBoxSceneQuery* self, int unusedEdx, unsigned int flags)
{
    self->Ogre::DefaultAxisAlignedBoxSceneQuery::~DefaultAxisAlignedBoxSceneQuery();
    if (flags & 1)
        operator delete(self);
    return self;
}
