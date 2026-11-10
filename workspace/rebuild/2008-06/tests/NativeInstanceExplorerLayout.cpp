#include <stddef.h>
#include "CInstanceExplorer.h"
#include "CSettingsExplorer.h"
// Sizes from CRuntimeClass 0080f638/0081bdac (0x3cc) and the CreateObject allocations 004219f0/00466b90 (operator
// new(0x3cc)); record sizes from operator new(0x5c) in 00420fb0 and operator new(0x80) in 00420db0. Offsets from
// constructor 00421940 / destructor 00421bc0 (listeners, +0x3c0/+0x3c4, byte +0x3c8), constructor 00420db0 /
// destructor 00420ee0 (+0x54/+0x58), inline CNameItem constructor in 00420db0 (+0x7c) and the RTTI base class
// descriptors of vtable 0080f8c4 (MarshaledListener<Instance,DescendantAdded> mdisp 0x378, <...Removing> 0x39c).
typedef RBX::MarshaledListener<RBX::Instance, RBX::DescendantAdded> DescendantAddedListener;
typedef RBX::MarshaledListener<RBX::Instance, RBX::DescendantRemoving> DescendantRemovingListener;
typedef char InstanceExplorerSize[sizeof(CInstanceExplorer) == 0x3cc ? 1 : -1];
typedef char SettingsExplorerSize[sizeof(CSettingsExplorer) == 0x3cc ? 1 : -1];
typedef char ReportViewSize[sizeof(CXTPReportView) == 0x378 ? 1 : -1];
typedef char ListenerSize[sizeof(DescendantAddedListener) == 0x24 && sizeof(DescendantRemovingListener) == 0x24 ? 1 : -1];
typedef char EventSize[sizeof(RBX::DescendantAdded) == 0x10 && sizeof(RBX::DescendantRemoving) == 0x10 ? 1 : -1];
typedef char InstanceExplorerRoot[offsetof(CInstanceExplorer, root) == 0x3c0 ? 1 : -1];
typedef char InstanceExplorerPopulating[offsetof(CInstanceExplorer, populating) == 0x3c8 ? 1 : -1];
typedef char InstanceRecordSize[sizeof(CInstanceRecord) == 0x5c ? 1 : -1];
typedef char ReportRecordSize[sizeof(CXTPReportRecord) == 0x54 ? 1 : -1];
typedef char InstanceRecordInstance[offsetof(CInstanceRecord, instance) == 0x54 ? 1 : -1];
typedef char NameItemSize[sizeof(CInstanceRecord::CNameItem) == 0x80 ? 1 : -1];
typedef char NameItemInstance[offsetof(CInstanceRecord::CNameItem, instance) == 0x7c ? 1 : -1];
static CInstanceExplorer* const probe = reinterpret_cast<CInstanceExplorer*>(0x1000);
int descendantAddedOffset() { return (int)(size_t)static_cast<DescendantAddedListener*>(probe) - 0x1000; }
int descendantRemovingOffset() { return (int)(size_t)static_cast<DescendantRemovingListener*>(probe) - 0x1000; }
// Instance notifier bases used by setRoot 00421a50 (root + 0x64 / root + 0x84).
static RBX::Instance* const instance = reinterpret_cast<RBX::Instance*>(0x1000);
int descendantAddedNotifier() { return (int)(size_t)static_cast<RBX::Notifier<RBX::Instance, RBX::DescendantAdded>*>(instance) - 0x1000; }
int descendantRemovingNotifier() { return (int)(size_t)static_cast<RBX::Notifier<RBX::Instance, RBX::DescendantRemoving>*>(instance) - 0x1000; }
