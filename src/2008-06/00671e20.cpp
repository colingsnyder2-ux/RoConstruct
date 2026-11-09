// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_espeon_poolrecyclenativee58139127c71a0e9.cpp

// Candidate translation unit (score above; library headers required).
#include <vector>
struct Object;
struct Pool{char prefix[0x48];std::vector<Object*> cache,active;void recycle();};
void Pool::recycle(){for(int i=0;i<(int)active.size();++i)cache.push_back(active[i]);active.erase(active.begin(),active.end());}
