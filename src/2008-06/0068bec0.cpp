// from server: 100% by tester
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MD
// roc-lib: ogre-1.4.5-dll roc_client_scene_update.cpp

// Candidate translation unit (score above; library headers required).
#undef OGRE_NONCLIENT_BUILD
#include <OgreSceneManager.h>
#include <OgreSceneNode.h>
struct HeaderRecovery : Ogre::SceneManager { void recoverUpdate(Ogre::Camera* cam); };
void HeaderRecovery::recoverUpdate(Ogre::Camera* cam) {
 Ogre::Node::processQueuedUpdates();
 mSceneRoot->_update(true, false);
}
