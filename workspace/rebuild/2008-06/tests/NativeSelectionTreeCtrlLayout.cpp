#include <stddef.h>
#include "CSelectionTreeCtrl.h"
// Sizes: CRuntimeClass 0080fb3c (0x130); RootNode operator new(0x8c) in 00426680. Offsets: constructor 00425c90 /
// destructor 004270c0 (+0xd8 CMenu, +0xe0..+0xe2 bytes, +0xe4 and +0x104 sets, +0x124 shared_ptr, +0x12c auto_ptr),
// RTTI base offsets of vtables 0080fe4c (CXTTreeBase 0x54), 00810040 (ActiveDocView 0xd0), 0080fe40 (Listener 0xd4).
typedef char SelectionTreeSize[sizeof(CSelectionTreeCtrl) == 0x130 ? 1 : -1];
typedef char RobloxTreeSize[sizeof(CRobloxTreeCtrl) == 0xd0 ? 1 : -1];
typedef char MenuSize[sizeof(CMenu) == 8 ? 1 : -1];
typedef char TreeMenu[offsetof(CSelectionTreeCtrl, menu) == 0xd8 ? 1 : -1];
typedef char TreeSelecting[offsetof(CSelectionTreeCtrl, selecting) == 0xe0 ? 1 : -1];
typedef char TreeUpdating[offsetof(CSelectionTreeCtrl, updating) == 0xe1 ? 1 : -1];
typedef char TreeChanging[offsetof(CSelectionTreeCtrl, changingSelection) == 0xe2 ? 1 : -1];
typedef char TreeQueue[offsetof(CSelectionTreeCtrl, selectionQueue) == 0xe4 ? 1 : -1];
typedef char TreeDirty[offsetof(CSelectionTreeCtrl, dirtyNodes) == 0x104 ? 1 : -1];
typedef char TreeDataModel[offsetof(CSelectionTreeCtrl, dataModel) == 0x124 ? 1 : -1];
typedef char TreeDragImage[offsetof(CSelectionTreeCtrl, dragImage) == 0x12c ? 1 : -1];
typedef char SetSize[sizeof(std::set<boost::shared_ptr<RBX::Instance> >) == 0x20 ? 1 : -1];
typedef char NodeSetSize[sizeof(std::set<CRobloxTreeCtrlNode*>) == 0x20 ? 1 : -1];
typedef char RootNodeSize[sizeof(RootNode) == 0x8c ? 1 : -1];
typedef char CmdUISize[sizeof(CCmdUI) == 0x28 ? 1 : -1];
static CSelectionTreeCtrl* const tree = reinterpret_cast<CSelectionTreeCtrl*>(0x1000);
int treeBaseOffset() { return (int)(size_t)static_cast<CXTTreeBase*>(tree) - 0x1000; }
int activeDocViewOffset() { return (int)(size_t)static_cast<ActiveDocView*>(tree) - 0x1000; }
int selectionListenerOffset()
{
    return (int)(size_t)static_cast<RBX::Listener<RBX::Selection, RBX::SelectionChanged>*>(tree) - 0x1000;
}
