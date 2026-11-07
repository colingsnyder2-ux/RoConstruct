#pragma once
// >>> native-status (generated) -- do not edit >>>
// CRobloxTreeCtrl | 2008-06 | inactive
// unmapped (no binary link) | by -
// <<< native-status | src a3e8e8f9 | roc native-status --write
#include <XTToolkitPro.h>
#include <boost/shared_ptr.hpp>
#include <boost/thread/recursive_mutex.hpp>
#include <map>
#include <set>
#include "CClassImages.h"
#include "util/Events.h"

namespace RBX {
class Instance;
class DataModel;
class Selection;
struct ChildAdded;
struct ChildRemoved;
class PropertyChanged;
namespace Reflection { class ClassDescriptor; }
}

class CRobloxTreeCtrlNode;

// Inactive layout recovery. CRuntimeClass 0080fb20 (DYNAMIC, no CreateObject, size 0xd0, base getter 00422620 ->
// CXTTreeCtrl 006dbaf0). RTTI of vtables 0080fcd4 (offset 0) and 0080fc4c (offset 0x54): CRobloxTreeCtrl :
// CXTTreeCtrl : CXTTreeCtrlBase : CTreeCtrl, CXTTreeBase at mdisp 0x54 (DECLATE_TREE_BASE). sizeof(CXTTreeCtrl) is
// 0x94 (compile), so the own members start at +0x94.
// Constructor 00425b00: CXTTreeCtrl 006dbda0, vptrs 0080fcd4/0080fc4c, +0x94 = 0, map constructor at +0x98 (folded
// _Tree(const less&, const allocator&) 00446110: 0x20 bytes, _Myhead +0x18, _Mysize +0x1c), byte +0xb8 = 0,
// CClassImages 00413230 at +0xbc (8 bytes), recursive_mutex at +0xc4 (00563070: m_mutex, m_critical_section = 1,
// m_count = 0; 0xc bytes, ends at 0xd0 = the CRuntimeClass size).
// Destructor 00424510 (reverse order): ~recursive_mutex 00594cb0 (+0xc4), ~CClassImages 00412f30 (+0xbc),
// ~_Tree 00553d80 (+0x98; 8-byte pair with trivial destructors), ~CXTTreeCtrl 006dbac0. No member destructor for
// +0x94 (raw pointer) or +0xb8.
// +0x94 is the root node: 00422b40 deletes it through slot 1 (scalar deleting destructor 00426660 of
// CRobloxTreeCtrlNode) and CSelectionTreeCtrl 00426680 stores operator new(0x8c) + node constructor in it.
// +0x98 maps the instance to its node: the node constructor 00425de0 stores this through operator[] with the raw
// instance pointer as key; the node destructor 00424900 erases it; both under the +0xc4 mutex.
// +0xb8 is saved, set and restored around 00422b40's rebuild (scoped by an EH state).
// Own virtual slots 84..89 (0x150..0x164): five pure (_purecall 006a16be; CSelectionTreeCtrl overrides 00426bd0,
// 00425da0, 00424600, 004246d0, 00424750) and 00422b40. Names below are provisional.
class CRobloxTreeCtrl : public CXTTreeCtrl {
    DECLARE_DYNAMIC(CRobloxTreeCtrl)
    DECLARE_MESSAGE_MAP()
public:
    CRobloxTreeCtrl();                                         // 00425b00
    // ~CRobloxTreeCtrl 00424510 is implicit: the target stores no vptrs before the member destructors.

    virtual BOOL PreCreateWindow(CREATESTRUCT& cs);            // 00422e10 (slot 27)

    // slot 84: CSelectionTreeCtrl 00426bd0 returns the data model's Selection service (004153b0 on +0x124, null
    // without a data model); the node calls Selection::isSelected 00424eb0 on it.
    virtual RBX::Selection* getSelection() = 0;
    // slot 85: CSelectionTreeCtrl 00425da0 copies its shared_ptr at +0x124/+0x128 (hidden return pointer); the node
    // constructor/destructor build DataModel::Lock 00411b40 from it.
    virtual boost::shared_ptr<RBX::DataModel> getDataModel() = 0;
    // slot 86: CSelectionTreeCtrl 00424600 looks the instance up in +0x98 (map find 00451600) under the mutex.
    virtual void onInstanceChanged(const RBX::Instance* instance) = 0;
    // slot 87: CSelectionTreeCtrl 004246d0 inserts the node in its pending set under the mutex.
    virtual void onNodeChanged(CRobloxTreeCtrlNode* node) = 0;
    // slot 88: CSelectionTreeCtrl 00424750 erases the node from its pending set; called by ~CRobloxTreeCtrlNode.
    virtual void onNodeDestroyed(CRobloxTreeCtrlNode* node) = 0;
    // slot 89: 00422b40, deletes every item and the root node.
    virtual void rebuild();

    // Message map 00810084 (base CXTTreeCtrl 006dbde0); reflected notifications are AfxSigNotify_v (61).
    void OnGetDispInfo(NMHDR* notify, LRESULT* result);       // TVN_GETDISPINFO    004226c0
    void OnItemExpanding(NMHDR* notify, LRESULT* result);     // TVN_ITEMEXPANDING  00426d60
    void OnItemExpanded(NMHDR* notify, LRESULT* result);      // TVN_ITEMEXPANDED   004226a0
    void OnDeleteItem(NMHDR* notify, LRESULT* result);        // TVN_DELETEITEM     00422bd0
    void OnBeginLabelEdit(NMHDR* notify, LRESULT* result);    // TVN_BEGINLABELEDIT 00422e90
    void OnEndLabelEdit(NMHDR* notify, LRESULT* result);      // TVN_ENDLABELEDIT   004232a0
    void OnDestroy();                                         // WM_DESTROY         00422d10
    int OnCreate(LPCREATESTRUCT cs);                          // WM_CREATE          00422da0
    void OnPaint();                                           // WM_PAINT           00422ed0
    // 004237d0: Default(); unless MK_CONTROL/MK_SHIFT, HitTest + TVHT_ONITEM, node = GetItemData, 004236d0(sret,
    // &node->instance); if non-null, DataModel::Lock and AfxGetApp()->[44ae00](copy). Body pending a CRobloxApp
    // declaration of 0044ae00 and the identity of 004236d0 (pool: rbxgs script/LuaInstanceBridge.cpp).
    void OnLButtonDblClk(UINT flags, CPoint point);           // WM_LBUTTONDBLCLK   004237d0
    void OnKeyDown(UINT key, UINT repeat, UINT flags);        // WM_KEYDOWN         00422f70

    CRobloxTreeCtrlNode* root;                                       // +0x94
    std::map<const RBX::Instance*, CRobloxTreeCtrlNode*> nodes;      // +0x98
    bool rebuilding;                                                 // +0xb8
    CClassImages images;                                             // +0xbc
    boost::recursive_mutex mutex;                                    // +0xc4
};

// Node class. RTTI of vtable 0080fc28 (offset 0): CRobloxTreeCtrlNode : Listener<Instance, PropertyChanged> (+0),
// Listener<Instance, ChildAdded> (+4, vtable 0080fc1c), Listener<Instance, ChildRemoved> (+8, vtable 0080fc10).
// Constructor 00425de0 (ret 0x10: parent, shared_ptr<Instance> by value, tree) and destructor 00424900 (scalar
// deleting 00426660, adjustor thunks 00424b50/00426650). The CSelectionTreeCtrl node (vtables 00810060/54/48,
// constructor 004265e0) is allocated with operator new(0x8c) and stores no members of its own: size 0x8c.
// Own virtual slots 2..6 in declaration order; names provisional.
class CRobloxTreeCtrlNode : public RBX::Listener<RBX::Instance, RBX::PropertyChanged>,
                            public RBX::Listener<RBX::Instance, RBX::ChildAdded>,
                            public RBX::Listener<RBX::Instance, RBX::ChildRemoved> {
public:
    CRobloxTreeCtrlNode(CRobloxTreeCtrlNode* parent, boost::shared_ptr<RBX::Instance> instance,
                        CRobloxTreeCtrl* tree);                                    // 00425de0
    virtual ~CRobloxTreeCtrlNode();                                                // 00424900

protected:
    virtual void onEvent(const RBX::Instance* source, RBX::PropertyChanged event);  // 00424dd0
    virtual void onEvent(const RBX::Instance* source, RBX::ChildAdded event);       // 00425450
    virtual void onEvent(const RBX::Instance* source, RBX::ChildRemoved event);     // 004256c0

public:
    virtual void updateSelection();                      // slot 2, 00424f80
    virtual void initialize();                           // slot 3, 00426010: item = insertItem(); updateSelection();
                                                         //   ChildAdded/ChildRemoved listeners under DataModel::Lock
    virtual void onItemExpanded(UINT action);            // slot 4, 00424ae0 (TVN_ITEMEXPANDED 004226a0)
    virtual void onGetDispInfo(NMTVDISPINFO* info);      // slot 5, 00425320 (TVN_GETDISPINFO 004226c0)
    virtual HTREEITEM insertItem();                      // slot 6, 00424c00

    // Non-virtual, called by TVN_ITEMEXPANDING 00426d60 in this order (and 004262c0 by CSelectionTreeCtrl 00426680).
    // Names provisional.
    void populate();                                     // 004262c0: queueChild for a copy of the instance's children
    void addChildren();                                  // 00426450: moves up to 10 queued children to addChild
                                                         //   (draft in the .cpp, not exact)
    CRobloxTreeCtrlNode* addChild(const boost::shared_ptr<RBX::Instance>& child);  // 00426100 (pending Metadata.h)
    void queueChild(const boost::shared_ptr<RBX::Instance>& child);  // 00424580 (bound by populate)
    bool hasChildren();                                  // 00425050 (TVIF_CHILDREN in 00425320)
    void refreshText();
    void removeChildren();

    boost::shared_ptr<RBX::Instance> instance;                       // +0x0c
    std::map<const RBX::Instance*, CRobloxTreeCtrlNode*> children;   // +0x14 (find 00451600, erase 00405ce0)
    std::set<CRobloxTreeCtrlNode*> removedChildren;                  // +0x34 (ChildRemoved inserts the child node)
    bool textDirty : 1;     // +0x54 bit 0: set when PropertyChanged names Instance::desc_Name (00424dd0)
    bool expanded : 1;      // +0x54 bit 1: set/cleared by 00424ae0; ChildAdded queues only when set
    bool expanding;         // +0x55: saved/set/restored around TVM_EXPAND in 00424f80; 00424ae0 tests it
    CRobloxTreeCtrl* tree;                                           // +0x58
    CRobloxTreeCtrlNode* parent;                                     // +0x5c
    std::set<boost::shared_ptr<RBX::Instance> > addedChildren;       // +0x60 (insert 00424030, erase 00424830)
    HTREEITEM item;                                                  // +0x80
    int order;                                                       // +0x84 = 00423050(instance): sibling sort key
    const RBX::Reflection::ClassDescriptor* descriptor;              // +0x88 = &instance->getDescriptor() (word +0x1c)
};

// CSelectionTreeCtrl (declaration not recovered here). CRuntimeClass 0080fb3c (size 0x130, base getter 00422630 ->
// CRobloxTreeCtrl), vtables 0080fed4/0080fe4c/0080fe40/00810040, message map 008101b0. It overrides all six
// CRobloxTreeCtrl slots (84..89: 00426bd0, 00425da0, 00424600, 004246d0, 00424750, 00426680), slot 5 (00422960) and
// six CXTTreeBase slots, keeps a set of nodes at +0x104 (insert 005e8c40, erase 005e9f60) and the data model
// shared_ptr at +0x124/+0x128; 0xd0..0x104 and +0x12c are not yet attributed. Its node subclass (vtables
// 00810060/54/48, constructor 004265e0: CRobloxTreeCtrlNode(NULL, instance, tree), +0x54 |= 2) adds no members.
