// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: openrbx-client-dll roc_espeon_foreachobjectcallback69c4346ded1fa021.cpp

// Candidate translation unit (score above; library headers required).
#include <set>
#include <algorithm>
typedef void (__thiscall *Callback)(void*,void*);
struct Functor {Functor();Callback callback;void* object;void operator()(void* value)const{callback(value,object);}};
typedef std::set<void*> Set;
Functor f(Set::iterator a,Set::iterator b,Functor fn){return std::for_each(a,b,fn);}
