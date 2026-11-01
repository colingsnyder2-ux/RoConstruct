// from server: 100% by king_originala
// from server: 100% by king_originala
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: atl-9.0-dll-rtm roc_atl_typeinfo_getti_88c46520c3afb67d.cpp

// Candidate translation unit (score above; library headers required).
#define _CPPUNWIND
#include <atlbase.h>
#include <atlcom.h>

typedef HRESULT (ATL::CComTypeInfoHolder::*RocGetTIFunction)(LCID);
RocGetTIFunction volatile roc_get_type_info =
    static_cast<RocGetTIFunction>(&ATL::CComTypeInfoHolder::GetTI);
