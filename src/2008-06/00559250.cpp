// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: openrbx-client-dll roc_espeon_reconstructvector_fbc3142ffebf0181.cpp

// Candidate translation unit (score above; library headers required).
#include <boost/shared_ptr.hpp>
#include <vector>
typedef boost::shared_ptr<void> Pair;
typedef std::vector<Pair> Vector;
extern void __cdecl prepare(void*);
struct Temporary {void* value; void __thiscall build(void*,Vector*);};
Pair __cdecl reconstruct(void* input) {
 prepare(input);
 Vector values;
 Temporary temporary;
 temporary.build(input,&values);
 if(values.size()==0)return Pair();
 return *values.begin();
}
