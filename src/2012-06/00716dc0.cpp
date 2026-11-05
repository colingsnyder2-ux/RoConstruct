// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: atl-9.0-dll-rtm roc_boost_atl_f4b0910a5d2d7185.cpp

// Candidate translation unit (score above; library headers required).
#define NDEBUG 1
#define _MBCS 1
#include <atlbase.h>
#include <atlstr.h>
#include <atlutil.h>
template class ATL::CSimpleStringT<char,false>;
template class ATL::CSimpleStringT<char,true>;
class UrlProbe : public ATL::CUrl { public: BOOL set(const char*); };
BOOL UrlProbe::set(const char* text) { return SetSchemeName(text); }
