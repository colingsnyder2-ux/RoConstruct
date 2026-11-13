// native-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MD /I{headers}/../../../tools/libs/ogre-1.4.5/ogrenew/OgreMain/include
// Collector and helper symbols follow the original identity registry.
// >>> native-status (generated) -- do not edit >>>
// TextureCollect2008 | 2008-06 | draft (no current byte proof)
// no original address mapped to this file yet | by -
// <<< native-status | src e64d9714 | roc native-status --write
#undef OGRE_NONCLIENT_BUILD
#include <OgreTextureManager.h>
#include <OgreLogManager.h>
#include <OgreStringConverter.h>

namespace Ogre {
void releaseUnusedResources(ResourceManager&, const String&, const StringVector&);
}
namespace PlayerNativeMaterial {
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
}
