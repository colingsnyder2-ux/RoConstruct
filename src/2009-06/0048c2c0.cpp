// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
#include <vector>
namespace Ogre { struct FileInfo { char d[0x50]; }; }
template bool std::vector<Ogre::FileInfo>::_Buy(size_type);
