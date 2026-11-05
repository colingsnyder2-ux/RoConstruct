// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: openrbx-client-dll roc_espeon_nativefiltered852806193dc7b34a.cpp

// Candidate translation unit (score above; library headers required).
#include <vector>
#include <algorithm>
struct Change{void* added;void* unused;void* removed;};
struct Selection{char pad[12];std::vector<void*> values;void update(Change*);};
void Selection::update(Change* c){void* v=c->added;if(v)values.push_back(v);v=c->removed;if(v){std::vector<void*>::iterator it=std::find(values.begin(),values.end(),v);if(it!=values.end())values.erase(it);}}
