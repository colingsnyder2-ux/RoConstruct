#include <stddef.h>
#include "CRobloxReportView.h"
// Size from CRuntimeClass 00818348 and the subclass allocations (CRobloxReportDocView CreateObject 00458d80:
// operator new(0x3d4), no added members); offsets from constructor 00457a40, destructor 00458b70 and the RTTI
// base class descriptors (MarshaledListener<Instance,ChildAdded> mdisp 0x378, <Instance,ChildRemoved> mdisp 0x39c).
typedef RBX::MarshaledListener<RBX::Instance, RBX::ChildAdded> ChildAddedListener;
typedef RBX::MarshaledListener<RBX::Instance, RBX::ChildRemoved> ChildRemovedListener;
typedef char RobloxReportViewSize[sizeof(CRobloxReportView) == 0x3d4 ? 1 : -1];
typedef char ReportViewSize[sizeof(CXTPReportView) == 0x378 ? 1 : -1];
typedef char ChildAddedListenerSize[sizeof(ChildAddedListener) == 0x24 ? 1 : -1];
typedef char ChildRemovedListenerSize[sizeof(ChildRemovedListener) == 0x24 ? 1 : -1];
typedef char ChildAddedSize[sizeof(RBX::ChildAdded) == 8 ? 1 : -1];
typedef char RobloxReportViewTimer[offsetof(CRobloxReportView, timer) == 0x3c0 ? 1 : -1];
typedef char RobloxReportViewDataModel[offsetof(CRobloxReportView, dataModel) == 0x3c4 ? 1 : -1];
typedef char RobloxReportViewStats[offsetof(CRobloxReportView, stats) == 0x3cc ? 1 : -1];
static CRobloxReportView* const probe = reinterpret_cast<CRobloxReportView*>(0x1000);
int childAddedOffset() { return (int)(size_t)static_cast<ChildAddedListener*>(probe) - 0x1000; }
int childRemovedOffset() { return (int)(size_t)static_cast<ChildRemovedListener*>(probe) - 0x1000; }
