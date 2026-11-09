// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_espeon_streamingmaplayout817b520414e06d0e.cpp

// Candidate translation unit (score above; library headers required).
#include <map>
// Node value begins at +0xc, mapped object at +0x10, color at +0x48.
// The binary therefore has a 4-byte key and a 56-byte destructible mapped value.
struct Value { unsigned char storage[56]; ~Value(); };
typedef std::map<unsigned int,Value> Map;
Map::iterator eraseOne(Map* map, Map::const_iterator pos) { return map->erase(pos); }
