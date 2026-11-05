// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: openrbx-client-dll roc_espeon_historymap642f4a99e23b64db.cpp

// Candidate translation unit (score above; library headers required).
#include <map>
struct Payload {void f();};
struct S:std::map<int,Payload>{void f();};
void S::f(){for(iterator it=begin();it!=end();++it)it->second.f();}
