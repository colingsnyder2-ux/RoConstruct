// native-flags: /O2 /Ob1 /GS /EHsc /MD /D_AFXDLL /D_DLL /D_LIB /D_XTP_STATICLINK /I{headers}/../../../work/native-client/xtp-shadow /I{headers}/../../../tools/libs/xtp-11.2.2/Source /FICommon/XTPDLLExports.h /FIXTToolkitPro.h /I{headers}/../../../tools/libs/xtp-11.2.2/Source/ReportControl /I{headers}/../native-classes
// 006da420: forwarding thunk generated from its proven jump target (thunk_lane.py, no model)
#include "XTPReportRows.cpp"
// INFERRED: 006da420 is a 5-byte jump to CArray<class CXTPReportRow *,class CXTPReportRow *>::~CArray<class CXTPReportRow *,class CXTPReportRow *>: the destructor of a derived class with nothing of its own to destroy; the class name is a placeholder.
struct __declspec(novtable) Thunk_006da420 : CArray<class CXTPReportRow *,class CXTPReportRow *> { ~Thunk_006da420(); };
Thunk_006da420::~Thunk_006da420() {}
