// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: atl-9.0-dll-rtm roc_unit_0d9fbeb40c0490eb.cpp

// Candidate translation unit (score above; library headers required).
#define NDEBUG 1
#define _ATL_APARTMENT_THREADED
#include <atlbase.h>
#include <atlcom.h>
template class ATL::CComEnumImpl<IEnumConnections, &IID_IEnumConnections, CONNECTDATA, ATL::_Copy<CONNECTDATA> >;
template class ATL::CComEnum<IEnumConnections, &IID_IEnumConnections, CONNECTDATA, ATL::_Copy<CONNECTDATA> >;
