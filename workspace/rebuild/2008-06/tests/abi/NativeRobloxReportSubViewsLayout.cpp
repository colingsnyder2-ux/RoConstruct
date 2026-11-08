#include <stddef.h>
#include "CRobloxReportSubViews.h"
// Sizes from CRuntimeClass 00818364 (0x3d4) and 00818380 (0x3d8) and the CreateObject allocations 00458d80/00458df0;
// the ActiveDocView subobject offset from the RTTI base class descriptor (mdisp 0x3d4) and constructor 00458c80.
typedef char RobloxReportDocViewSize[sizeof(CRobloxReportDocView) == 0x3d4 ? 1 : -1];
typedef char RobloxReportPaneViewSize[sizeof(CRobloxReportPaneView) == 0x3d8 ? 1 : -1];
typedef char ActiveDocViewSize[sizeof(ActiveDocView) == 4 ? 1 : -1];
static CRobloxReportPaneView* const probe = reinterpret_cast<CRobloxReportPaneView*>(0x1000);
int activeDocViewOffset() { return (int)(size_t)static_cast<ActiveDocView*>(probe) - 0x1000; }
