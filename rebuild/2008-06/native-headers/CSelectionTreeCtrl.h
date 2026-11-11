#pragma once
// >>> native-status (generated) -- do not edit >>>
// CSelectionTreeCtrl | 2008-06 | selection unverified
// unmapped (no binary link) | by -
// <<< native-status | src 252391fd | roc native-status --write
#include "CRobloxTreeCtrl.h"
#include "ActiveDocView.h"
#include "v8datamodel/SelectionChanged.h"
#include <memory>

// Inactive layout recovery. CRuntimeClass 0080fb3c (DYNAMIC, no CreateObject, size 0x130, base getter 00422630 ->
// CRobloxTreeCtrl). RTTI of vtables 0080fed4 (offset 0), 0080fe4c (CXTTreeBase, 0x54), 00810040 (ActiveDocView, 0xd0)
// and 0080fe40 (Listener<Selection, SelectionChanged>, 0xd4): CSelectionTreeCtrl : CRobloxTreeCtrl, ActiveDocView,
// Listener<Selection, SelectionChanged>. sizeof(CRobloxTreeCtrl) is 0xd0, so the own members start at +0xd8.
// Constructor 00425c90: CRobloxTreeCtrl 00425b00, ActiveDocView 00405d50 (+0xd0), vptrs 0080fed4/0080fe4c/00810040/
// 0080fe40, CMenu vptr 0080fbdc + m_hMenu = 0 (+0xd8), bytes +0xe0/+0xe1/+0xe2 = 0, set constructor at +0xe4 (folded
// _Tree 00446110, 0x20 bytes), set constructor at +0x104 (folded 0064b2a0, 0x20 bytes), +0x124/+0x128/+0x12c = 0,
// then menu.LoadMenu(103) (AfxFindResourceHandle + LoadMenuA + CMenu::Attach).
// Destructor 004270c0: body setDataModel(empty) (00426bf0), then in reverse order delete +0x12c through slot 1 (auto_ptr),
// release +0x128, ~_Tree 0064b230 (+0x104), ~_Tree 004247c0 (+0xe4), ~CMenu (vptr + DestroyMenu, +0xd8),
// ~ActiveDocView 00405d80 (+0xd0), ~CRobloxTreeCtrl 00424510. 0x12c + 4 = 0x130 = the CRuntimeClass size.
// Own names are provisional.
class CSelectionTreeCtrl : public CRobloxTreeCtrl,
                           public ActiveDocView,
                           public RBX::Listener<RBX::Selection, RBX::SelectionChanged> {
    DECLARE_DYNAMIC(CSelectionTreeCtrl)
    DECLARE_MESSAGE_MAP()
public:
    CSelectionTreeCtrl();                                            // 00425c90
    virtual ~CSelectionTreeCtrl();                                   // 004270c0 (scalar deleting 004272d0)

    virtual BOOL OnCmdMsg(UINT id, int code, void* extra, AFX_CMDHANDLERINFO* info);  // slot 5, 00422960

    virtual RBX::Selection* getSelection();                          // slot 84, 00426bd0
    virtual boost::shared_ptr<RBX::DataModel> getDataModel();        // slot 85, 00425da0
    virtual void onInstanceChanged(const RBX::Instance* instance);   // slot 86, 00424600
    virtual void onNodeChanged(CRobloxTreeCtrlNode* node);           // slot 87, 004246d0
    virtual void onNodeDestroyed(CRobloxTreeCtrlNode* node);         // slot 88, 00424750
    virtual void rebuild();                                          // slot 89, 00426680

    // ActiveDocView slot 0 (00810040), this at +0xd0.
    virtual void update(boost::shared_ptr<RBX::DataModel> current, boost::shared_ptr<RBX::DataModel> previous);  // 004271e0

protected:
    // Listener slot 0 (0080fe40), this at +0xd4.
    virtual void onEvent(const RBX::Selection* source, RBX::SelectionChanged event);  // 00425810

    // CXTTreeBase overrides (vtable 0080fe4c slots 20..25), this at +0x54.
    virtual void SelectAllIgnore(BOOL select, HTREEITEM ignore);                          // 00423510
    virtual BOOL OnButtonDown(BOOL left, UINT flags, CPoint point);                       // 004228d0
    virtual void DoPreSelection(HTREEITEM item, BOOL left, UINT flags);                   // 004228f0
    virtual void DoAction(HTREEITEM item, BOOL left, UINT flags, CPoint point);           // 00422900
    virtual void DoBanding(UINT flags, CPoint point);                                     // 00422930
    virtual void UpdateSelectionForRect(LPCRECT rect, UINT flags, CTypedPtrList<CPtrList, HTREEITEM>& list);  // 00422950

public:
    void setDataModel(boost::shared_ptr<RBX::DataModel> value);      // 00426bf0
    // 00426780: node of an instance, creating the missing ancestors' nodes through addChild 00426100.
    CRobloxTreeCtrlNode* findNode(const boost::shared_ptr<RBX::Instance>& instance);
    void processSelectionQueue();                                    // 00426900: findNode for up to 10 queued instances
    void select(TVITEM* item, bool selected);                        // 004230f0
    void showContextMenu(CPoint point);                              // 00422720
    // 00423c40: the item itself when its node's instance accepts the current selection (Instance 00423700 with the
    // Selection range 00413d40/00413d10), else NULL. Name provisional; body pending Selection/Instance declarations.
    HTREEITEM dropTarget(HTREEITEM item);

    // Message map 008101b0 (base CRobloxTreeCtrl 004272f0).
    void OnContextMenu(CWnd* wnd, CPoint point);                     // WM_CONTEXTMENU    004228b0
    void OnSelChanged(NMHDR* notify, LRESULT* result);               // TVN_SELCHANGED    00423240
    void OnSelChanging(NMHDR* notify, LRESULT* result);              // TVN_SELCHANGING   004226e0
    void OnRButtonDown(UINT flags, CPoint point);                    // WM_RBUTTONDOWN    00422e50
    void OnBeginDrag(NMHDR* notify, LRESULT* result);                // TVN_BEGINDRAG     004233d0
    void OnLButtonUp(UINT flags, CPoint point);                      // WM_LBUTTONUP      00426ef0
    void OnMouseMove(UINT flags, CPoint point);                      // WM_MOUSEMOVE      00423d50
    int OnCreate(LPCREATESTRUCT cs);                                 // WM_CREATE         004234d0
    void OnTimer(UINT_PTR id);                                       // WM_TIMER          00426a80

    CMenu menu;                                                      // +0xd8 (LoadMenu(103); 00422720 reads m_hMenu)
    bool selecting;                                                  // +0xe0 (TVN_SELCHANGING result; set in 00426a80)
    bool updating;                                                   // +0xe1 (OnSelChanged ignores; set in 00426a80)
    bool changingSelection;                                          // +0xe2 (set around Selection add/remove in
                                                                     //   004230f0; onEvent ignores events while set)
    std::set<boost::shared_ptr<RBX::Instance> > selectionQueue;      // +0xe4 (onEvent inserts selected instances
                                                                     //   without a node, erases deselected ones)
    std::set<CRobloxTreeCtrlNode*> dirtyNodes;                       // +0x104 (insert 005e8c40, erase 005e9f60)
    boost::shared_ptr<RBX::DataModel> dataModel;                     // +0x124
    std::auto_ptr<CImageList> dragImage;                             // +0x12c (TVN_BEGINDRAG CreateDragImage)
};

// Root node of a CSelectionTreeCtrl. RTTI of vtable 00810060: RootNode : CRobloxTreeCtrlNode. Constructor 004265e0
// (ret 8): CRobloxTreeCtrlNode(NULL, instance, tree), expanded = true, vptrs 00810060/00810054/00810048. Allocated
// with operator new(0x8c) by 00426680: no members of its own. The deleting destructor folds with
// CRobloxTreeCtrlNode's (00426660).
class RootNode : public CRobloxTreeCtrlNode {
public:
    RootNode(const boost::shared_ptr<RBX::Instance>& instance, CRobloxTreeCtrl* tree);  // 004265e0
    virtual void updateSelection();                      // slot 2, folded empty 0047d410
    virtual void onGetDispInfo(NMTVDISPINFO* info);      // slot 5, folded empty 0070bdf0
    virtual HTREEITEM insertItem();                      // slot 6, 00426640: TVI_ROOT
};
