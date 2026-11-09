// from server: 100% by tester
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MD
// roc-lib: ogre-1.4.5-dll roc_client_texture_copy.cpp

// Candidate translation unit (score above; library headers required).
#undef OGRE_NONCLIENT_BUILD
#include <OgreTexture.h>
#include <algorithm>
template Ogre::TexturePtr* std::_Copy_opt(Ogre::TexturePtr*, Ogre::TexturePtr*, Ogre::TexturePtr*, std::random_access_iterator_tag, std::_Nonscalar_ptr_iterator_tag, std::_Range_checked_iterator_tag);
