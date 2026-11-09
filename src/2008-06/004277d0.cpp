// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: openrbx-client-dll roc_espeon_taskbindstring_7bc19aad55898a1a.cpp

// Candidate translation unit (score above; library headers required).
#include <string>
#include <boost/function.hpp>
#include <boost/bind.hpp>
extern std::string __cdecl makeFunctor();extern void __cdecl callback(std::string);extern const char taskName[];struct Base{Base(const boost::function<void()>&,const char*);~Base();};struct S:Base{S();};S::S():Base(boost::bind(callback,makeFunctor()),taskName){}
