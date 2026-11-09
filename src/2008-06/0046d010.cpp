// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: openrbx-client-dll roc_espeon_colormap_80ba8168b6a8eb58.cpp

// Candidate translation unit (score above; library headers required).
#include <map>
struct ColorMap {char padding[60];std::map<int,int> map;int lookup(int key);};
int ColorMap::lookup(int key){std::map<int,int>::iterator it=map.find(key);if(it!=map.end())return it->second;return 0;}
