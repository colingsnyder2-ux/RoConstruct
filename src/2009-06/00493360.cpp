// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <vector>
namespace Ogre { struct RbxMaterialEntry { char d[0x50]; }; }
template std::vector<Ogre::RbxMaterialEntry>::iterator std::vector<Ogre::RbxMaterialEntry>::insert(std::vector<Ogre::RbxMaterialEntry>::const_iterator, const Ogre::RbxMaterialEntry&);
