// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: this is an import thunk (jmp through the IAT) to
// rgmain!Ogre::SceneManagerFactory::getMetaData() const. The real Ogre headers
// are not available, so the minimal declarations are written here.
namespace Ogre {
    struct SceneManagerMetaData;

    class SceneManagerFactory {
    public:
        __declspec(dllimport) virtual const SceneManagerMetaData& getMetaData() const;
    };
}

// INFERRED: `this` arrives in ecx (thiscall), so it is declared __fastcall with
// a dummy edx argument. The qualified call is non-virtual and becomes a tail jmp
// through the import.
extern "C" const Ogre::SceneManagerMetaData& __fastcall fn_0069ff66(Ogre::SceneManagerFactory* self, int unusedEdx)
{
    return self->Ogre::SceneManagerFactory::getMetaData();
}
