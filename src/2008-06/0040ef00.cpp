// from server: 100% by auto
// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: mfc-9.0-shared roc_espeon_comenuminitnative_65941067da5b003c.cpp

// Candidate translation unit (score above; library headers required).
#define _CPPUNWIND 1
#include <afxwin.h>
#include <atlbase.h>
#include <atlcom.h>
typedef ATL::CComEnum<IEnumConnections,&IID_IEnumConnections,CONNECTDATA,ATL::_Copy<CONNECTDATA> > Enum;
typedef ATL::CComEnumImpl<IEnumConnections,&IID_IEnumConnections,CONNECTDATA,ATL::_Copy<CONNECTDATA> > EnumBase;
HRESULT(EnumBase::*forceInit)(CONNECTDATA*,CONNECTDATA*,IUnknown*,ATL::CComEnumFlags)=&EnumBase::Init;
