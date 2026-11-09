// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_espeon_mapcachedendcd0a419f31517ef1.cpp

// Candidate translation unit (score above; library headers required).
#include <map>
struct Key{unsigned words[4];bool operator<(const Key&)const;};
struct S:std::map<Key,int>{bool f();};
bool S::f(){iterator e=end();for(iterator i=begin();i!=e;++i){if(i->second!=0)return false;}return true;}
