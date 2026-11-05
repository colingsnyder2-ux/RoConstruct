// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: openrbx-client-dll roc_espeon_setforeach_363f60ac40a12412.cpp

// Candidate translation unit (score above; library headers required).
#include <set>
#include <algorithm>
struct Function { void (__cdecl *callback)(void*); void* state; Function(); void operator()(const unsigned& value) const {callback(const_cast<unsigned*>(&value));} };
typedef std::set<unsigned>::iterator Iterator;
Function __cdecl apply(Iterator first,Iterator last,Function function) {return std::for_each(first,last,function);}
