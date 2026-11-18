// native-flags: /O2 /Ob1 /GS- /EHsc /MD /D_AFXDLL /D_DLL /D_LIB /D_XTP_STATICLINK /I{headers}/../../../work/native-client/xtp-shadow /I{headers}/../../../tools/libs/xtp-11.2.2/Source /FICommon/XTPDLLExports.h /FIXTToolkitPro.h /I{headers}/../../../tools/libs/xtp-11.2.2/Source/Controls /I{headers}/../native-classes
// 007904c0: forwarding thunk generated from its proven jump target (thunk_lane.py, no model)
#include "XTPXTWndShadow.cpp"
// INFERRED: 007904c0 is a 5-byte jump to CList<class CXTShadowWnd *,class CXTShadowWnd *>::~CList<class CXTShadowWnd *,class CXTShadowWnd *>: the destructor of a derived class with nothing of its own to destroy; the class name is a placeholder.
struct __declspec(novtable) Thunk_007904c0 : CList<class CXTShadowWnd *,class CXTShadowWnd *> { ~Thunk_007904c0(); };
Thunk_007904c0::~Thunk_007904c0() {}
