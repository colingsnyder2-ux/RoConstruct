// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: atl-9.0-dll-rtm roc_campaign_enum_e48885f48ab9e114.cpp

// Candidate translation unit (score above; library headers required).
#define NDEBUG 1
#define _ATL_APARTMENT_THREADED
#include <atlbase.h>
#include <atlcom.h>
template class ATL::CComEnumImpl<IEnumUnknown, &IID_IEnumUnknown, IUnknown*, ATL::_CopyInterface<IUnknown> >;
template class ATL::CComEnum<IEnumUnknown, &IID_IEnumUnknown, IUnknown*, ATL::_CopyInterface<IUnknown>, ATL::CComSingleThreadModel>;
