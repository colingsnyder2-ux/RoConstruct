// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <algorithm>

namespace Ogre {

// INFERRED: minimal layout of Ogre::Light (vtable slot 1 = getCastShadows, float at +0xC8)
class Light {
public:
    // INFERRED: slot 0 is the virtual destructor (placeholder so getCastShadows lands in slot 1)
    virtual ~Light();
    virtual bool getCastShadows() const;
    char pad[0xC4];
    float tempSquareDist;
};

class SceneManager {
public:
    struct lightsForShadowTextureLess {
        bool operator()(const Light* l1, const Light* l2) const
        {
            if (l1 == l2)
                return false;

            // sort shadow casters first
            if (l1->getCastShadows() != l2->getCastShadows())
                return l1->getCastShadows();

            // otherwise sort by distance (nearest first)
            // INFERRED: operand order written to match fld l2 / fcomp l1
            return l2->tempSquareDist > l1->tempSquareDist;
        }
    };
};

} // namespace Ogre

// Explicit instantiation of the vendor STL helper from <algorithm>
template void std::_Insertion_sort1<Ogre::Light**, Ogre::SceneManager::lightsForShadowTextureLess, Ogre::Light*>(
    Ogre::Light**, Ogre::Light**, Ogre::SceneManager::lightsForShadowTextureLess, Ogre::Light**);
