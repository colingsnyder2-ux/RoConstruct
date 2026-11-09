// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MD
// roc-lib: ogre-1.4.5-dll roc_texture_collect_1f43ed84bc91727c.cpp

// Candidate translation unit (score above; library headers required).
#undef OGRE_NONCLIENT_BUILD
#include <OgreTextureManager.h>
#include <OgreLogManager.h>
#include <OgreStringConverter.h>

namespace Ogre {
void releaseUnusedResources(ResourceManager&, const String&, const StringVector&);
}
namespace RBX { namespace RenderNew {
void collectUnusedTextures() {
    static int count = 0;
    if (++count % 32 == 0) {
        int before = Ogre::TextureManager::getSingleton().getMemoryUsage();
        Ogre::StringVector keep;
        keep.push_back("*\\content\\*");
        Ogre::releaseUnusedResources(Ogre::TextureManager::getSingleton(), "Texture", keep);
        int after = Ogre::TextureManager::getSingleton().getMemoryUsage();
        Ogre::LogManager::getSingleton().logMessage("Tex usage: "
            + Ogre::StringConverter::toString(before) + " => " + Ogre::StringConverter::toString(after));
    }
}
} }
