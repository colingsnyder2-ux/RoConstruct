// from server: 100% by tester
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-9.0-rtm roc-lane-d-probe/enum.cpp

// Candidate translation unit (score above; library headers required).
#include <atlbase.h>
#include <atlcom.h>
template class ATL::CComEnum<IEnumConnectionPoints, &__uuidof(IEnumConnectionPoints), IConnectionPoint*, ATL::_CopyInterface<IConnectionPoint> >;
template class ATL::CComObject<ATL::CComEnum<IEnumConnectionPoints, &__uuidof(IEnumConnectionPoints), IConnectionPoint*, ATL::_CopyInterface<IConnectionPoint> > >;
