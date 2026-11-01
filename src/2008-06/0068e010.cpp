// from server: 100% by tester
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MD
// roc-lib: ogre-1.4.9-dll roc_client_map_bounds.cpp

// Candidate translation unit (score above; library headers required).
#undef OGRE_NONCLIENT_BUILD
#include <OgreSceneManager.h>
template class std::map<const Ogre::Camera*, Ogre::VisibleObjectsBoundsInfo>;
