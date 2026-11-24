// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: no Ogre header path is known to exist in the native-headers tree,
// so Ogre::MaterialPtr is declared minimally here. That is just enough for the
// imported member operator= to link under its mangled name
// ?4MaterialPtr@Ogre@@QAEAAV01@ABV01@@Z. The class is only used by reference,
// so its layout is not needed.
namespace Ogre {
    class MaterialPtr {
    public:
        __declspec(dllimport) MaterialPtr& operator=(const MaterialPtr& r);
    };
}

// INFERRED: the original adds 0x48 to the incoming object pointer and
// tail-jumps into Ogre::MaterialPtr::operator=. Because it is a tail jump, the
// function has no ret of its own, so the ABI is classified as __cdecl. The
// enclosing object type is unknown, so it is taken as an opaque byte pointer.
extern "C" Ogre::MaterialPtr& __cdecl fn_006850a0(char* self, const Ogre::MaterialPtr& other)
{
    // INFERRED: the member at offset 0x48 is an Ogre::MaterialPtr.
    Ogre::MaterialPtr* dst = reinterpret_cast<Ogre::MaterialPtr*>(self + 0x48);
    return *dst = other;
}
