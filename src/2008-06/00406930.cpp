// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: atl-9.0 roc_espeon_bstransiasign6671a088facdff20.cpp

// Candidate translation unit (score above; library headers required).
#include <atlbase.h>
struct Bstr:ATL::CComBSTR {Bstr& assign(const char*);};
Bstr& Bstr::assign(const char* text){ATL::CComBSTR::operator=(text);return *this;}
