#include <afxwin.h>
#include "util/RunStateOwner.h"
#include "util/IMetric.h"

// Base-only layout probe; does not model the remaining window members.
class NativeWindowBases : public CWnd, public RBX::IRunView, public RBX::IMetric {};
NativeWindowBases* nativeWindowBases;
