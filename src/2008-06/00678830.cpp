// from server: 100% by king_originala
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MD
// roc-lib: ogre-1.4.9-dll roc_ogre_map_string_value84_300b0b85e3ca9437.cpp

// Candidate translation unit (score above; library headers required).
// The target's MSVC _Tree node stores _Isnil at +0x7d.  Verified siblings
// establish +0x29 plus the mapped-value size, so the opaque value is 0x54.
struct OgreMapValue84 {
    int words[21];
};

#include <map>
#include <string>

template class std::map<std::string, OgreMapValue84>;
