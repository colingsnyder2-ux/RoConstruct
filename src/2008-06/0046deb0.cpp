// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: openrbx-client-dll roc_espeon_twostringcopy_13987a455c12d7dc.cpp

// Candidate translation unit (score above; library headers required).
#include <string>
struct S { unsigned int first,second; std::string third,fourth; S(const S&); };
S::S(const S& source):first(source.first),second(source.second),third(source.third),fourth(source.fourth) {}
