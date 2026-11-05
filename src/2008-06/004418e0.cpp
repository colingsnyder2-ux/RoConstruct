// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_espeon_streamingmap241650aaae8e2a91d8.cpp

// Candidate translation unit (score above; library headers required).
#include <map>
// Observed mapped destructor at +0x10 and color at +0x28 imply value size24.
struct Value { unsigned char storage[24]; ~Value(); };
typedef std::map<unsigned int,Value> Map;
Map::iterator eraseOne(Map* map, Map::const_iterator pos) { return map->erase(pos); }
