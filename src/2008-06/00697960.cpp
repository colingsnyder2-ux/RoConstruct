// from server: 100% by auto
// from server: 100% by tester
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MD
// roc-lib: ogre-1.4.5-dll roc_client_light_templates.cpp

// Candidate translation unit (score above; library headers required).
#undef OGRE_NONCLIENT_BUILD
#include <OgreSceneManager.h>
#include <algorithm>
struct HeaderAccess : Ogre::SceneManager {
 using Ogre::SceneManager::lightsForShadowTextureLess;
 using Ogre::SceneManager::LightInfo;
};
template void std::_Buffered_merge(Ogre::Light**, Ogre::Light**, Ogre::Light**, int, int, std::_Temp_iterator<Ogre::Light*>&, HeaderAccess::lightsForShadowTextureLess);
template class std::vector<HeaderAccess::LightInfo>;
