// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <string>

// INFERRED: no Ogre header is available, so a minimal import-only declaration of
// Ogre::DataStream is provided. The target is a bare "jmp [IAT]" thunk to the
// imported virtual member
// ?getAsString@DataStream@Ogre@@UAE?AV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ
namespace Ogre {
    class __declspec(dllimport) DataStream {
    public:
        virtual std::string getAsString();
    };
}

// INFERRED: thunk forwarding (this in ecx, hidden return pointer on the stack) to the
// imported member via a qualified, non-virtual call.
extern "C" std::string fn_0069fc90(Ogre::DataStream* self)
{
    return self->Ogre::DataStream::getAsString();
}
