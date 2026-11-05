// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS /EHsc /MD
// roc-lib: atl-8.0 roc_espclaude_ec5687d5f132e66f.cpp

// Candidate translation unit (score above; library headers required).
#define _CPPUNWIND 1
#define _DLL
#define COM_STDMETHOD_CAN_THROW
#include <atlbase.h>
#include <atlcom.h>
template class ATL::CComEnum<IEnumConnections, &__uuidof(IEnumConnections), CONNECTDATA, ATL::_Copy<CONNECTDATA> >;
template class ATL::CComObject<ATL::CComEnum<IEnumConnections, &__uuidof(IEnumConnections), CONNECTDATA, ATL::_Copy<CONNECTDATA> > >;
template class ATL::CComEnum<IEnumConnectionPoints, &__uuidof(IEnumConnectionPoints), IConnectionPoint*, ATL::_CopyInterface<IConnectionPoint> >;
template class ATL::CComObject<ATL::CComEnum<IEnumConnectionPoints, &__uuidof(IEnumConnectionPoints), IConnectionPoint*, ATL::_CopyInterface<IConnectionPoint> > >;
