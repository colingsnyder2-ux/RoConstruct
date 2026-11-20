// native-flags: /O2 /GS- /EHsc /MD /D_AFXDLL /D_ATL_APARTMENT_THREADED /I{headers}/mfc-noinline-pcxstr /I{headers}/std-noinline-string /I{headers}/../../../tools/libs/mfc-9.0-rtm/atlmfc/include
// IObjectSafetyRobloxImpl<CApp, 1> (2008-06 VCApp unit). Retired in batch 29: both slots are byte-exact in
// CAppObjectSafety.cpp (GetInterfaceSafetyOptions 00407690, SetInterfaceSafetyOptions 00407720, proved again in
// batch 29). The bodies formerly here did not compile under VC9 (nullptr, C2065) and called an invented
// FinalConstruct where the target calls checkSite (00407500, the CApp instance of 00403b60), so they are removed
// rather than duplicated. Recovery_00407690_IObjectSafetyRobloxImplRecovery_00407690.cpp is a second stale copy of
// the same two specializations (retirement proposal).
#include <afx.h>
#include "CApp2008.h"
