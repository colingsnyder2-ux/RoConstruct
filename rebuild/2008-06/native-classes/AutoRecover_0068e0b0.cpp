// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: local opaque Ogre::TexturePtr (12 bytes, imported operator=) stands in for the real header.
namespace Ogre {
class __declspec(dllimport) TexturePtr {
public:
    TexturePtr& operator=(const TexturePtr& r);
private:
    void* a;
    void* b;
    void* c;
};
}

extern "C" Ogre::TexturePtr* fn_0068e0b0(Ogre::TexturePtr* first, Ogre::TexturePtr* last, Ogre::TexturePtr* dest)
{
    Ogre::TexturePtr* end = dest + (last - first);
    for (; first != last; ++first, ++dest)
        *dest = *first;
    return end;
}
