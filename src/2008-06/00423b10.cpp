// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: openrbx-client-dll roc_espeon_selectionfunctor_21f4fad2a2f355f8.cpp

// Candidate translation unit (score above; library headers required).
#include <set>
#include <algorithm>
typedef void (__thiscall *Callback)(void*,void*);
struct Functor {Functor();Callback callback;void* object;void operator()(const unsigned& value)const{callback(object,const_cast<unsigned*>(&value));}};
typedef std::set<unsigned> Set;
Functor f(Set::iterator a,Set::iterator b,Functor fn){return std::for_each(a,b,fn);}
