// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: no Ogre headers were shown, so minimal declarations stand in for them.
// The original is an import thunk: jmp [__imp_?getMetaData@SceneManagerFactory@Ogre@@UBEABUSceneManagerMetaData@2@XZ].
// INFERRED: the target ABI is reported as __cdecl, so the object pointer is taken as a
// normal stack argument and forwarded via a qualified (non-virtual) call through the
// dllimport, which compiles to mov ecx,[esp+4]; jmp [__imp_...].
namespace Ogre {
    struct SceneManagerMetaData;

    class __declspec(dllimport) SceneManagerFactory {
    public:
        virtual const SceneManagerMetaData& getMetaData() const;
    };
}

extern "C" const Ogre::SceneManagerMetaData& __cdecl fn_0069ff66(const Ogre::SceneManagerFactory* self)
{
    return self->Ogre::SceneManagerFactory::getMetaData();
}
