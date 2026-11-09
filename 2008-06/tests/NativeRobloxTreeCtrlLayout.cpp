#include <stddef.h>
#include "CRobloxTreeCtrl.h"
#include "CRobloxReportView.h"
// Sizes: CRuntimeClass 0080fb20 (0xd0); node operator new(0x8c) in CSelectionTreeCtrl 00426680 (the derived node
// adds no members). Offsets: constructor 00425b00 / destructor 00424510 (+0x94, +0x98, +0xb8, +0xbc, +0xc4), RTTI of
// vtable 0080fc4c (CXTTreeBase mdisp 0x54), node constructor 00425de0 / destructor 00424900, node RTTI 0080fc28
// (listener bases at +4/+8).
typedef char TreeCtrlSize[sizeof(CRobloxTreeCtrl) == 0xd0 ? 1 : -1];
typedef char XTTreeCtrlSize[sizeof(CXTTreeCtrl) == 0x94 ? 1 : -1];
typedef char TreeRoot[offsetof(CRobloxTreeCtrl, root) == 0x94 ? 1 : -1];
typedef char TreeNodes[offsetof(CRobloxTreeCtrl, nodes) == 0x98 ? 1 : -1];
typedef char TreeRebuilding[offsetof(CRobloxTreeCtrl, rebuilding) == 0xb8 ? 1 : -1];
typedef char TreeImages[offsetof(CRobloxTreeCtrl, images) == 0xbc ? 1 : -1];
typedef char TreeMutex[offsetof(CRobloxTreeCtrl, mutex) == 0xc4 ? 1 : -1];
typedef char MapSize[sizeof(std::map<const RBX::Instance*, CRobloxTreeCtrlNode*>) == 0x20 ? 1 : -1];
typedef char MutexSize[sizeof(boost::recursive_mutex) == 0xc ? 1 : -1];
typedef char NodeSize[sizeof(CRobloxTreeCtrlNode) == 0x8c ? 1 : -1];
typedef char NodeInstance[offsetof(CRobloxTreeCtrlNode, instance) == 0x0c ? 1 : -1];
typedef char NodeChildren[offsetof(CRobloxTreeCtrlNode, children) == 0x14 ? 1 : -1];
typedef char NodeRemoved[offsetof(CRobloxTreeCtrlNode, removedChildren) == 0x34 ? 1 : -1];
typedef char NodeExpanding[offsetof(CRobloxTreeCtrlNode, expanding) == 0x55 ? 1 : -1];
typedef char NodeTree[offsetof(CRobloxTreeCtrlNode, tree) == 0x58 ? 1 : -1];
typedef char NodeParent[offsetof(CRobloxTreeCtrlNode, parent) == 0x5c ? 1 : -1];
typedef char NodeAdded[offsetof(CRobloxTreeCtrlNode, addedChildren) == 0x60 ? 1 : -1];
typedef char NodeItem[offsetof(CRobloxTreeCtrlNode, item) == 0x80 ? 1 : -1];
typedef char NodeOrder[offsetof(CRobloxTreeCtrlNode, order) == 0x84 ? 1 : -1];
typedef char NodeDescriptor[offsetof(CRobloxTreeCtrlNode, descriptor) == 0x88 ? 1 : -1];
static CRobloxTreeCtrl* const tree = reinterpret_cast<CRobloxTreeCtrl*>(0x1000);
int treeBaseOffset() { return (int)(size_t)static_cast<CXTTreeBase*>(tree) - 0x1000; }
static CRobloxTreeCtrlNode* const node = reinterpret_cast<CRobloxTreeCtrlNode*>(0x1000);
int childAddedOffset() { return (int)(size_t)static_cast<RBX::Listener<RBX::Instance, RBX::ChildAdded>*>(node) - 0x1000; }
int childRemovedOffset() { return (int)(size_t)static_cast<RBX::Listener<RBX::Instance, RBX::ChildRemoved>*>(node) - 0x1000; }
// The flag bits at +0x54: the constructor clears bits 0-1 (and byte 0xfc), 00424dd0 sets bit 0, 00424ae0 sets bit 1.
void setTextDirty(CRobloxTreeCtrlNode* n) { n->textDirty = true; }
void setExpanded(CRobloxTreeCtrlNode* n) { n->expanded = true; }
// Instance word +0x1c read by the node constructor is DescribedBase::descriptor.
const void* instanceDescriptor(RBX::Instance* i) { return &i->getDescriptor(); }
