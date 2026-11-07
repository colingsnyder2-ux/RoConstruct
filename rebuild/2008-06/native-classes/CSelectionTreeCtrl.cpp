// >>> native-status (generated) -- do not edit >>>
// CSelectionTreeCtrl | 2008-06 | inactive
// unmapped (no binary link) | by -
// <<< native-status | src 1938dc3f | roc native-status --write
#include "CSelectionTreeCtrl.h"
#include "CRobloxDoc.h"
#include "v8tree/Instance.h"
#include "v8datamodel/DataModel.h"
#include "v8datamodel/Selection.h"
#include "util/Object.h"
#include <algorithm>
#include <boost/bind.hpp>
#include "v8datamodel/Workspace.h"

extern CRobloxDoc* activeRobloxDoc;   // 0096c238 (ActiveDocumentData.cpp)

typedef RBX::Notifier<RBX::Selection, RBX::SelectionChanged> SelectionNotifier;

namespace RBX {
// 0058c5c0 (CameraHistory.cpp): commits a ChangeHistoryService waypoint; not declared in a shared header.
void recordCameraHistory(const char* name, const Instance* context);
}

namespace {
// Saves a value, assigns a new one and restores it on scope exit (004230f0, 00426a80 keep the reference and the old
// byte on the stack under an EH state). Same helper as CRobloxTreeCtrl.cpp; name provisional.
template<class T>
class ScopedAssign {
    T& value;
    T saved;
public:
    ScopedAssign(T& value, T assigned) : value(value), saved(value) { value = assigned; }
    ~ScopedAssign() { value = saved; }
};
}

// RTTI .?AVCEnabledCmdUI@@, vtable 0080fbfc: Enable 00422700, SetCheck/SetRadio/SetText empty (folded 0070bdf0).
// 00422720 constructs it on the stack (CCmdUI::CCmdUI, vptr, +0x28 = FALSE) and reads +0x28 after the update route.
class CEnabledCmdUI : public CCmdUI {
public:
    CEnabledCmdUI() : enabled(FALSE) {}
    virtual void Enable(BOOL on = TRUE) { enabled = on; m_bEnableChanged = TRUE; }
    virtual void SetCheck(int) {}
    virtual void SetRadio(BOOL) {}
    virtual void SetText(LPCTSTR) {}
    BOOL enabled;   // +0x28
};

IMPLEMENT_DYNAMIC(CSelectionTreeCtrl, CRobloxTreeCtrl)

BEGIN_MESSAGE_MAP(CSelectionTreeCtrl, CRobloxTreeCtrl)
    ON_WM_CONTEXTMENU()
    ON_NOTIFY_REFLECT(TVN_SELCHANGED, &CSelectionTreeCtrl::OnSelChanged)
    ON_NOTIFY_REFLECT(TVN_SELCHANGING, &CSelectionTreeCtrl::OnSelChanging)
    ON_WM_RBUTTONDOWN()
    ON_NOTIFY_REFLECT(TVN_BEGINDRAG, &CSelectionTreeCtrl::OnBeginDrag)
    ON_WM_LBUTTONUP()
    ON_WM_MOUSEMOVE()
    ON_WM_CREATE()
    ON_WM_TIMER()
END_MESSAGE_MAP()

CSelectionTreeCtrl::CSelectionTreeCtrl()
    : selecting(false),
      updating(false),
      changingSelection(false)
{
    menu.LoadMenu(103);
}

CSelectionTreeCtrl::~CSelectionTreeCtrl()
{
    setDataModel(boost::shared_ptr<RBX::DataModel>());
}

BOOL CSelectionTreeCtrl::OnCmdMsg(UINT id, int code, void* extra, AFX_CMDHANDLERINFO* info)
{
    if (CRobloxTreeCtrl::OnCmdMsg(id, code, extra, info))
        return TRUE;
    if (activeRobloxDoc == NULL)
        return FALSE;
    return activeRobloxDoc->OnCmdMsg(id, code, extra, info);
}

RBX::Selection* CSelectionTreeCtrl::getSelection()
{
    return dataModel ? dataModel->create<RBX::Selection>() : NULL;
}

boost::shared_ptr<RBX::DataModel> CSelectionTreeCtrl::getDataModel()
{
    return dataModel;
}

void CSelectionTreeCtrl::onInstanceChanged(const RBX::Instance* instance)
{
    boost::recursive_mutex::scoped_lock lock(mutex);
    std::map<const RBX::Instance*, CRobloxTreeCtrlNode*>::iterator it = nodes.find(instance);
    if (it != nodes.end())
        dirtyNodes.insert(it->second);
}

void CSelectionTreeCtrl::onNodeChanged(CRobloxTreeCtrlNode* node)
{
    boost::recursive_mutex::scoped_lock lock(mutex);
    dirtyNodes.insert(node);
}

void CSelectionTreeCtrl::onNodeDestroyed(CRobloxTreeCtrlNode* node)
{
    boost::recursive_mutex::scoped_lock lock(mutex);
    dirtyNodes.erase(node);
}

RootNode::RootNode(const boost::shared_ptr<RBX::Instance>& instance, CRobloxTreeCtrl* tree)
    : CRobloxTreeCtrlNode(NULL, instance, tree)
{
    expanded = true;
}

void RootNode::updateSelection()
{
}

void RootNode::onGetDispInfo(NMTVDISPINFO*)
{
}

HTREEITEM RootNode::insertItem()
{
    return TVI_ROOT;
}

void CSelectionTreeCtrl::rebuild()
{
    CRobloxTreeCtrl::rebuild();
    if (dataModel && m_hWnd) {
        root = new RootNode(dataModel, this);
        root->initialize();
        root->populate();
        Expand(root->item, TVE_EXPAND);
    }
}

void CSelectionTreeCtrl::update(boost::shared_ptr<RBX::DataModel> current, boost::shared_ptr<RBX::DataModel>)
{
    setDataModel(current);
    rebuild();
}

void CSelectionTreeCtrl::setDataModel(boost::shared_ptr<RBX::DataModel> value)
{
    if (dataModel) {
        RBX::DataModel::Lock lock(dataModel);
        SelectionNotifier::disconnect(dataModel->find<RBX::Selection>(), this);
    }
    dataModel = value;
    if (dataModel) {
        RBX::DataModel::Lock lock(dataModel);
        SelectionNotifier::connect(dataModel->create<RBX::Selection>(), this);
    }
}

void CSelectionTreeCtrl::onEvent(const RBX::Selection*, RBX::SelectionChanged event)
{
    if (changingSelection)
        return;
    if (event.addedItem) {
        boost::recursive_mutex::scoped_lock lock(mutex);
        std::map<const RBX::Instance*, CRobloxTreeCtrlNode*>::iterator it = nodes.find(event.addedItem.get());
        if (it != nodes.end())
            onNodeChanged(it->second);
        else
            selectionQueue.insert(RBX::shared_from(event.addedItem.get()));
    }
    if (event.removedItem) {
        boost::recursive_mutex::scoped_lock lock(mutex);
        selectionQueue.erase(event.removedItem);
        std::map<const RBX::Instance*, CRobloxTreeCtrlNode*>::iterator it = nodes.find(event.removedItem.get());
        if (it != nodes.end())
            onNodeChanged(it->second);
    }
}

BOOL CSelectionTreeCtrl::OnButtonDown(BOOL left, UINT flags, CPoint point)
{
    return CXTTreeBase::OnButtonDown(left, flags, point);
}

void CSelectionTreeCtrl::DoPreSelection(HTREEITEM item, BOOL left, UINT flags)
{
    CXTTreeBase::DoPreSelection(item, left, flags);
}

void CSelectionTreeCtrl::DoAction(HTREEITEM item, BOOL left, UINT flags, CPoint point)
{
    CXTTreeBase::DoAction(item, left, flags, point);
}

void CSelectionTreeCtrl::DoBanding(UINT flags, CPoint point)
{
    CXTTreeBase::DoBanding(flags, point);
}

void CSelectionTreeCtrl::UpdateSelectionForRect(LPCRECT rect, UINT flags, CTypedPtrList<CPtrList, HTREEITEM>& list)
{
    CXTTreeBase::UpdateSelectionForRect(rect, flags, list);
}

void CSelectionTreeCtrl::OnContextMenu(CWnd*, CPoint point)
{
    showContextMenu(point);
}

void CSelectionTreeCtrl::OnSelChanging(NMHDR*, LRESULT* result)
{
    *result = selecting ? TRUE : FALSE;
}

void CSelectionTreeCtrl::OnRButtonDown(UINT flags, CPoint point)
{
    CXTTreeCtrl::OnRButtonDown(flags, point);
    ClientToScreen(&point);
    showContextMenu(point);
}

int CSelectionTreeCtrl::OnCreate(LPCREATESTRUCT cs)
{
    if (CRobloxTreeCtrl::OnCreate(cs) == -1)
        return -1;
    refresh();
    SetTimer(0, 200, NULL);
    return 0;
}

void CSelectionTreeCtrl::OnSelChanged(NMHDR* notify, LRESULT* result)
{
    *result = 0;
    if (!updating && !rebuilding && dataModel) {
        NMTREEVIEW* view = reinterpret_cast<NMTREEVIEW*>(notify);
        if (view->itemNew.hItem)
            select(&view->itemNew, true);
        if (view->itemOld.hItem && view->action)
            select(&view->itemOld, false);
    }
}

void CSelectionTreeCtrl::select(TVITEM* item, bool selected)
{
    if (item->hItem && item->lParam) {
        boost::shared_ptr<RBX::Instance> instance = reinterpret_cast<CRobloxTreeCtrlNode*>(item->lParam)->instance;
        if (instance) {
            RBX::DataModel::Lock lock(getDataModel());
            RBX::Selection* selection = getSelection();
            ScopedAssign<bool> guard(changingSelection, true);
            if (selected)
                selection->addToSelection(instance.get());
            else
                selection->removeFromSelection(instance.get());
        }
    }
}

void CSelectionTreeCtrl::showContextMenu(CPoint point)
{
    CMenu* popup = menu.GetSubMenu(0);
    if (!popup)
        return;
    for (UINT i = 0; i < popup->GetMenuItemCount(); ++i) {
        CEnabledCmdUI state;
        state.m_nID = popup->GetMenuItemID(i);
        if (state.m_nID == 0)
            continue;
        if (state.m_nID == (UINT)-1) {
            state.m_pSubMenu = popup->GetSubMenu(i);
            continue;
        }
        AfxGetMainWnd()->OnCmdMsg(state.m_nID, CN_UPDATE_COMMAND_UI, &state, NULL);
        popup->EnableMenuItem(i, MF_BYPOSITION | (state.enabled ? MF_ENABLED : MF_DISABLED));
    }
    if (point.x == -1 && point.y == -1) {
        CRect rect;
        GetClientRect(&rect);
        point = rect.CenterPoint();
        ClientToScreen(&point);
        CXTPCommandBars::TrackPopupMenu(popup, TPM_CENTERALIGN | TPM_VCENTERALIGN, point.x, point.y, GetParentFrame());
    } else {
        CXTPCommandBars::TrackPopupMenu(popup, 0, point.x, point.y, GetParentFrame());
    }
}

void CSelectionTreeCtrl::OnBeginDrag(NMHDR* notify, LRESULT* result)
{
    NMTREEVIEW* view = reinterpret_cast<NMTREEVIEW*>(notify);
    dragImage.reset(CreateDragImage(view->itemNew.hItem));
    if (dragImage.get()) {
        CRect rect;
        GetItemRect(view->itemNew.hItem, &rect, TRUE);
        UINT indent = GetIndent();
        CPoint point = view->ptDrag;
        dragImage->BeginDrag(0, point - rect.TopLeft() + CPoint(indent, 0));
        ClientToScreen(&point);
        CImageList::DragEnter(NULL, point);
        SetCapture();
    }
    *result = 0;
}

void CSelectionTreeCtrl::OnMouseMove(UINT flags, CPoint point)
{
    if (dragImage.get()) {
        CPoint screen = point;
        ClientToScreen(&screen);
        CImageList::DragMove(screen);
        UINT hit;
        HTREEITEM target = HitTest(point, &hit);
        if (target)
            target = (hit & TVHT_ONITEM) ? dropTarget(target) : NULL;
        CImageList::DragShowNolock(FALSE);
        SelectDropTarget(target);
        CImageList::DragShowNolock(TRUE);
    }
    CXTTreeCtrl::OnMouseMove(flags, point);
}

CRobloxTreeCtrlNode* CSelectionTreeCtrl::findNode(const boost::shared_ptr<RBX::Instance>& instance)
{
    if (!instance)
        return NULL;
    {
        boost::recursive_mutex::scoped_lock lock(mutex);
        std::map<const RBX::Instance*, CRobloxTreeCtrlNode*>::iterator it = nodes.find(instance.get());
        if (it != nodes.end())
            return it->second;
    }
    CRobloxTreeCtrlNode* parent = findNode(RBX::shared_from(instance->getParent()));
    if (!parent)
        return NULL;
    return parent->addChild(instance);
}

void CSelectionTreeCtrl::processSelectionQueue()
{
    for (int i = 0; i < 10; ++i) {
        boost::shared_ptr<RBX::Instance> instance;
        {
            boost::recursive_mutex::scoped_lock lock(mutex);
            std::set<boost::shared_ptr<RBX::Instance> >::iterator it = selectionQueue.begin();
            if (it == selectionQueue.end())
                return;
            instance = *it;
            selectionQueue.erase(it);
        }
        findNode(instance);
    }
}

// Needs CRobloxTreeCtrlNode::refreshText 00422650 and CRobloxTreeCtrlNode::removeChildren 00425520 (pending
// declarations in CRobloxTreeCtrl.h).
void CSelectionTreeCtrl::OnTimer(UINT_PTR id)
{
    CRobloxTreeCtrlNode* node = NULL;
    {
        boost::recursive_mutex::scoped_lock lock(mutex);
        if (dirtyNodes.size() > 0)
            node = *dirtyNodes.begin();
    }
    if (node) {
        ScopedAssign<bool> guard(updating, true);
        node->refreshText();
        node->updateSelection();
        {
            ScopedAssign<bool> selectGuard(selecting, true);
            node->removeChildren();
        }
        node->addChildren();
        boost::recursive_mutex::scoped_lock lock(mutex);
        if (node->addedChildren.empty())
            onNodeDestroyed(node);
    }
    processSelectionQueue();
    CXTTreeCtrl::OnTimer(id);
}

void CSelectionTreeCtrl::SelectAllIgnore(BOOL select, HTREEITEM ignore)
{
    if (!select) {
        CRobloxTreeCtrlNode* node = reinterpret_cast<CRobloxTreeCtrlNode*>(GetItemData(ignore));
        boost::shared_ptr<RBX::Instance> instance;
        if (node)
            instance = node->instance;
        {
            RBX::DataModel::Lock lock(getDataModel());
            RBX::Selection* selection = getSelection();
            ScopedAssign<bool> guard(changingSelection, true);
            selection->setSelection(instance.get());
        }
        {
            ScopedAssign<bool> guard(updating, true);
            CXTTreeBase::SelectAllIgnore(FALSE, ignore);
        }
    } else {
        CXTTreeBase::SelectAllIgnore(select, ignore);
    }
}

// 00426db0: drop handler applied to every selected instance (name provisional; external linkage is not observable).
// Needs Instance::isDescendentOf 00422ae0 (pending declaration in v8tree/Instance.h).
void dropInstance(RBX::Instance* parent, boost::shared_ptr<RBX::Instance> child)
{
    if (child->getParent() == parent)
        return;
    RBX::Workspace* workspace = RBX::Workspace::findWorkspace(parent);
    if (workspace && !child->isDescendentOf(workspace)) {
        std::vector<boost::shared_ptr<RBX::Instance> > instances;
        instances.push_back(child);
        workspace->insertInstances(instances, workspace, RBX::INSERT_TO_TREE, RBX::SUPPRESS_PROMPTS);
    }
    child->setParent(parent);
}

// Needs Selection::begin/end (00413d10/00413d40) and Instance 00423700 (pending declarations).
HTREEITEM CSelectionTreeCtrl::dropTarget(HTREEITEM item)
{
    if (!item)
        return NULL;
    CRobloxTreeCtrlNode* node = reinterpret_cast<CRobloxTreeCtrlNode*>(GetItemData(item));
    if (node) {
        boost::shared_ptr<RBX::Instance> instance = node->instance;
        if (instance && instance->canAcceptChildren(getSelection()->begin(), getSelection()->end()))
            return item;
    }
    return NULL;
}

void CSelectionTreeCtrl::OnLButtonUp(UINT flags, CPoint point)
{
    CRobloxTreeCtrl::OnLButtonUp(flags, point);
    if (dragImage.get()) {
        CImageList::DragLeave(this);
        CImageList::EndDrag();
        ReleaseCapture();
        dragImage.reset();
        HTREEITEM drop = GetDropHilightItem();
        if (drop) {
            CRobloxTreeCtrlNode* node = reinterpret_cast<CRobloxTreeCtrlNode*>(GetItemData(drop));
            if (node) {
                boost::shared_ptr<RBX::Instance> target = node->instance;
                RBX::DataModel::Lock lock(dataModel);
                if (target)
                    std::for_each(getSelection()->begin(), getSelection()->end(), boost::bind(&dropInstance, target.get(), _1));
                RBX::recordCameraHistory("Drop", dataModel.get());
                dataModel->setDirty(true);
            }
        }
        SelectDropTarget(NULL);
    }
}
