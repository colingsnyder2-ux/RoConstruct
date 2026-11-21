// native-flags: /O2 /Ob1 /GS- /EHsc /MD /D_AFXDLL /D_DLL /D_LIB /D_XTP_STATICLINK /I{headers}/../../../work/native-client/xtp-shadow /I{headers}/../../../tools/libs/xtp-11.2.2/Source /FICommon/XTPDLLExports.h /FIXTToolkitPro.h /I{headers}/../../../tools/libs/xtp-11.2.2/Source/TabManager /I{headers}/../native-classes
// 0072d5e0: forwarding thunk generated from its proven jump target (thunk_lane.py, no model)
#include "XTPTabPaintManagerColors.cpp"
// INFERRED: 0072d5e0 is a 5-byte jump to CXTPTabPaintManager::CColorSetOffice2003::RefreshMetrics; the forwarder name and owner are placeholders.
struct Thunk_0072d5e0 : CXTPTabPaintManager::CColorSetOffice2003 { void sub_0072d5e0(); };
void Thunk_0072d5e0::sub_0072d5e0() { CXTPTabPaintManager::CColorSetOffice2003::RefreshMetrics(); }
