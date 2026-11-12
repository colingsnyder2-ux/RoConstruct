#include "CRobloxTreeCtrl.h"
#include "CRobloxReportView.h"
#include "v8tree/Instance.h"
#include "v8tree/PropertyChanged.h"
#include "v8datamodel/DataModel.h"
#include "v8datamodel/Selection.h"
#include "reflection/Metadata.h"
#include <boost/bind.hpp>
#include <algorithm>
#include <vector>

namespace {
// Saves a value, assigns a new one and restores it on scope exit (00422b40, 00422bd0, 00422d10 keep the reference
// and the old byte on the stack under an EH state). Name provisional.
template<class T>
class ScopedAssign {
    T& value;
    T saved;
public:
    ScopedAssign(T& value, T assigned) : value(value), saved(value) { value = assigned; }
    ~ScopedAssign() { value = saved; }
};
}

// File-scope helpers with external linkage (names provisional; the original linkage is not observable).
// 00423050: sort order of an instance's class in the tree (node +0x84; compared before names in insertItem).
// Calls Metadata::Class 004225b0, which the committed reflection/Metadata.h does not declare (pending header).
int explorerOrder(RBX::Instance* instance);
int explorerOrder(RBX::Instance* instance)
{
    boost::shared_ptr<RBX::Metadata::Reflection> reflection = RBX::Metadata::Reflection::singleton();
    RBX::Reflection::Metadata::Class* metadata = reflection->lookup(instance->getDescriptor(), true);
    return metadata ? metadata->explorerOrder() : 0;
}

// 00424b60: metadata image index of a class (0 without metadata). Name provisional.
int classImage(const RBX::Reflection::ClassDescriptor* descriptor)
{
    boost::shared_ptr<RBX::Metadata::Reflection> reflection = RBX::Metadata::Reflection::singleton();
    RBX::Reflection::Metadata::Class* metadata = reflection->lookup(*descriptor, true);
    return metadata ? metadata->getImageIndex() : 0;
}

IMPLEMENT_DYNAMIC(CRobloxTreeCtrl, CXTTreeCtrl)

BEGIN_MESSAGE_MAP(CRobloxTreeCtrl, CXTTreeCtrl)
    ON_NOTIFY_REFLECT(TVN_GETDISPINFO, &CRobloxTreeCtrl::OnGetDispInfo)
    ON_NOTIFY_REFLECT(TVN_ITEMEXPANDING, &CRobloxTreeCtrl::OnItemExpanding)
    ON_NOTIFY_REFLECT(TVN_ITEMEXPANDED, &CRobloxTreeCtrl::OnItemExpanded)
    ON_NOTIFY_REFLECT(TVN_DELETEITEM, &CRobloxTreeCtrl::OnDeleteItem)
    ON_NOTIFY_REFLECT(TVN_BEGINLABELEDIT, &CRobloxTreeCtrl::OnBeginLabelEdit)
    ON_NOTIFY_REFLECT(TVN_ENDLABELEDIT, &CRobloxTreeCtrl::OnEndLabelEdit)
    ON_WM_DESTROY()
    ON_WM_CREATE()
    ON_WM_PAINT()
    ON_WM_LBUTTONDBLCLK()
    ON_WM_KEYDOWN()
END_MESSAGE_MAP()

CRobloxTreeCtrl::CRobloxTreeCtrl()
    : root(NULL),
      rebuilding(false)
{
}

BOOL CRobloxTreeCtrl::PreCreateWindow(CREATESTRUCT& cs)
{
    cs.style = (cs.style & ~TVS_DISABLEDRAGDROP) | TVS_HASBUTTONS | TVS_LINESATROOT | TVS_EDITLABELS | TVS_SHOWSELALWAYS;
    return CXTTreeCtrl::PreCreateWindow(cs);
}

void CRobloxTreeCtrl::rebuild()
{
    ScopedAssign<bool> guard(rebuilding, true);
    if (m_hWnd == NULL)
        return;
    DeleteAllItems();
    if (root) {
        delete root;
        root = NULL;
    }
}

void CRobloxTreeCtrl::OnDestroy()
{
    CXTTreeCtrl::OnDestroy();
    ScopedAssign<bool> guard(rebuilding, true);
    DeleteAllItems();
    if (root) {
        delete root;
        root = NULL;
    }
}

void CRobloxTreeCtrl::OnGetDispInfo(NMHDR* notify, LRESULT* result)
{
    NMTVDISPINFO* info = reinterpret_cast<NMTVDISPINFO*>(notify);
    reinterpret_cast<CRobloxTreeCtrlNode*>(info->item.lParam)->onGetDispInfo(info);
    *result = 0;
}

void CRobloxTreeCtrl::OnItemExpanded(NMHDR* notify, LRESULT* result)
{
    NMTREEVIEW* view = reinterpret_cast<NMTREEVIEW*>(notify);
    reinterpret_cast<CRobloxTreeCtrlNode*>(view->itemNew.lParam)->onItemExpanded(view->action);
    *result = 0;
}

void CRobloxTreeCtrl::OnDeleteItem(NMHDR* notify, LRESULT* result)
{
    ScopedAssign<bool> guard(rebuilding, true);
    NMTREEVIEW* view = reinterpret_cast<NMTREEVIEW*>(notify);
    delete reinterpret_cast<CRobloxTreeCtrlNode*>(view->itemOld.lParam);
    *result = 0;
}

void CRobloxTreeCtrl::OnBeginLabelEdit(NMHDR*, LRESULT* result)
{
    GetEditControl()->LimitText(32);
    *result = 0;
}

CRobloxTreeCtrlNode::CRobloxTreeCtrlNode(CRobloxTreeCtrlNode* parent, boost::shared_ptr<RBX::Instance> instance,
                                         CRobloxTreeCtrl* tree)
    : instance(instance),
      textDirty(false),
      expanded(false),
      expanding(false),
      tree(tree),
      parent(parent),
      item(NULL),
      order(explorerOrder(instance.get())),
      descriptor(&instance->getDescriptor())
{
    {
        boost::recursive_mutex::scoped_lock lock(tree->mutex);
        tree->nodes[instance.get()] = this;
        if (parent)
            parent->children[instance.get()] = this;
    }
    RBX::DataModel::Lock lock(tree->getDataModel());
    instance->RBX::Notifier<RBX::Instance, RBX::PropertyChanged>::addListener(this);
}

CRobloxTreeCtrlNode::~CRobloxTreeCtrlNode()
{
    {
        boost::recursive_mutex::scoped_lock lock(tree->mutex);
        if (parent)
            parent->children.erase(instance.get());
        tree->onNodeDestroyed(this);
        tree->nodes.erase(instance.get());
    }
    RBX::DataModel::Lock lock(tree->getDataModel());
    instance->RBX::Notifier<RBX::Instance, RBX::PropertyChanged>::removeListener(this);
    instance->RBX::Notifier<RBX::Instance, RBX::ChildAdded>::removeListener(this);
    instance->RBX::Notifier<RBX::Instance, RBX::ChildRemoved>::removeListener(this);
}

void CRobloxTreeCtrlNode::onEvent(const RBX::Instance*, RBX::PropertyChanged event)
{
    bool nameChanged;
    {
        RBX::DataModel::Lock lock(tree->getDataModel());
        nameChanged = &event.getDescriptor() == &RBX::Instance::desc_Name;
    }
    if (nameChanged) {
        textDirty = true;
        tree->onNodeChanged(this);
    }
}

void CRobloxTreeCtrlNode::onEvent(const RBX::Instance*, RBX::ChildAdded event)
{
    if (expanded) {
        boost::recursive_mutex::scoped_lock lock(tree->mutex);
        addedChildren.insert(event.child);
    }
    tree->onNodeChanged(this);
}

void CRobloxTreeCtrlNode::initialize()
{
    item = insertItem();
    updateSelection();
    RBX::DataModel::Lock lock(tree->getDataModel());
    instance->RBX::Notifier<RBX::Instance, RBX::ChildAdded>::addListener(this);
    instance->RBX::Notifier<RBX::Instance, RBX::ChildRemoved>::addListener(this);
}

void CRobloxTreeCtrlNode::onItemExpanded(UINT)
{
    if (expanding) {
        expanded = false;
        return;
    }
    if (tree->GetItemState(item, TVIF_STATE) | TVIS_EXPANDED) {
        expanded = true;
        if (tree->GetItemState(item, TVIF_STATE) | TVIS_EXPANDPARTIAL)
            tree->SetItemState(item, TVIS_EXPANDED, TVIF_STATE);
    }
}

int CRobloxTreeCtrl::OnCreate(LPCREATESTRUCT cs)
{
    if (CXTTreeCtrl::OnCreate(cs) == -1)
        return -1;
    SetImageList(&images, TVSIL_NORMAL);
    EnableMultiSelect(TRUE);
    rebuild();
    return 0;
}

void CRobloxTreeCtrl::OnPaint()
{
    COLORREF face = XTPColorManager()->GetColor(COLOR_3DFACE);
    COLORREF highlight = XTPColorManager()->GetColor(COLOR_HIGHLIGHT);
    XTPColorManager()->SetColor(COLOR_3DFACE, RGB((GetRValue(highlight) + GetRValue(face)) / 2,
                                                  (GetGValue(face) + GetGValue(highlight)) / 2,
                                                  (GetBValue(highlight) + GetBValue(face)) / 2));
    CXTTreeCtrl::OnPaint();
    XTPColorManager()->SetColor(COLOR_3DFACE, face);
}

void CRobloxTreeCtrl::OnKeyDown(UINT key, UINT repeat, UINT flags)
{
    if (key == VK_F2)
        EditLabel(GetSelectedItem());
    CXTTreeCtrl::OnKeyDown(key, repeat, flags);
}

void CRobloxTreeCtrl::OnItemExpanding(NMHDR* notify, LRESULT* result)
{
    NMTREEVIEW* view = reinterpret_cast<NMTREEVIEW*>(notify);
    CRobloxTreeCtrlNode* node = reinterpret_cast<CRobloxTreeCtrlNode*>(view->itemNew.lParam);
    if (view->action & TVE_EXPAND) {
        if (!node->expanding) {
            node->populate();
            node->addChildren();
        }
    }
    *result = 0;
}

void CRobloxTreeCtrl::OnEndLabelEdit(NMHDR* notify, LRESULT* result)
{
    NMTVDISPINFO* info = reinterpret_cast<NMTVDISPINFO*>(notify);
    if (info->item.pszText) {
        CRobloxTreeCtrlNode* node = reinterpret_cast<CRobloxTreeCtrlNode*>(info->item.lParam);
        RBX::DataModel::Lock lock(getDataModel());
        node->instance->setName(info->item.pszText);
        *result = 1;
    } else {
        *result = 0;
    }
}

void CRobloxTreeCtrlNode::onEvent(const RBX::Instance*, RBX::ChildRemoved event)
{
    {
        boost::recursive_mutex::scoped_lock lock(tree->mutex);
        tree->nodes.erase(event.child.get());
        std::map<const RBX::Instance*, CRobloxTreeCtrlNode*>::iterator it = children.find(event.child.get());
        if (it != children.end())
            removedChildren.insert(it->second);
        addedChildren.erase(event.child);
    }
    tree->onNodeChanged(this);
}

void CRobloxTreeCtrlNode::onGetDispInfo(NMTVDISPINFO* info)
{
    try {
        if (info->item.mask & TVIF_TEXT) {
            RBX::DataModel::Lock lock(tree->getDataModel());
            strncpy(info->item.pszText, instance->getName().c_str(), info->item.cchTextMax);
        }
        if (info->item.mask & TVIF_CHILDREN)
            info->item.cChildren = hasChildren() ? 1 : 0;
    } catch (...) {
        strncpy(info->item.pszText, "", info->item.cchTextMax);
    }
}

void CRobloxTreeCtrlNode::updateSelection()
{
    if (!item)
        return;
    if (tree->getSelection() && tree->getSelection()->isSelected(instance.get())) {
        for (CRobloxTreeCtrlNode* node = parent; node; node = node->parent) {
            ScopedAssign<bool> guard(node->expanding, true);
            node->tree->Expand(node->item, TVE_EXPAND | TVE_EXPANDPARTIAL);
        }
        tree->SelectItems(item, item, FALSE);
        tree->EnsureVisible(item);
    } else {
        tree->SetItemState(item, 0, TVIS_SELECTED);
    }
}

void CRobloxTreeCtrlNode::queueChild(const boost::shared_ptr<RBX::Instance>& child)
{
    {
        boost::recursive_mutex::scoped_lock lock(tree->mutex);
        addedChildren.insert(child);
    }
    tree->onNodeChanged(this);
}

// 00422650: repaint the item's rectangle when its text was marked dirty.
void CRobloxTreeCtrlNode::refreshText()
{
    if (textDirty)
    {
        if (item != NULL && item != TVI_FIRST)
        {
            CRect rect;
            if (tree->GetItemRect(item, &rect, FALSE))
                ::InvalidateRect(tree->m_hWnd, &rect, TRUE);
        }
        textDirty = false;
    }
}

void CRobloxTreeCtrlNode::populate()
{
    std::vector<boost::shared_ptr<RBX::Instance> > list;
    {
        RBX::DataModel::Lock lock(tree->getDataModel());
        if (instance->children)
            list = *instance->children;
    }
    std::for_each(list.begin(), list.end(), boost::bind(&CRobloxTreeCtrlNode::queueChild, this, _1));
}

// Draft, not exact (00426450): the target copies *it into the loop-local child without the shared_count::operator=
// compare/release that this source emits, and keeps child 8 bytes lower in the frame. Parked after three variants
// (direct begin()/end(), held iterator, held begin/end).
#ifdef NATIVE_TREE_DRAFT
void CRobloxTreeCtrlNode::addChildren()
{
    for (int i = 0; i < 10; ++i) {
        boost::shared_ptr<RBX::Instance> child;
        {
            boost::recursive_mutex::scoped_lock lock(tree->mutex);
            std::set<boost::shared_ptr<RBX::Instance> >::iterator it = addedChildren.begin();
            if (it == addedChildren.end())
                return;
            child = *it;
            addedChildren.erase(it);
        }
        addChild(child);
    }
}
#endif

HTREEITEM CRobloxTreeCtrlNode::insertItem()
{
    TVINSERTSTRUCT insert;
    insert.item.mask = TVIF_TEXT | TVIF_IMAGE | TVIF_PARAM | TVIF_SELECTEDIMAGE | TVIF_CHILDREN;
    insert.item.pszText = LPSTR_TEXTCALLBACK;
    insert.item.cChildren = I_CHILDRENCALLBACK;
    insert.item.iImage = insert.item.iSelectedImage = classImage(descriptor);
    insert.item.lParam = reinterpret_cast<LPARAM>(this);
    insert.hParent = parent ? parent->item : TVI_ROOT;
    HTREEITEM after = TVI_FIRST;
    for (HTREEITEM child = tree->GetChildItem(insert.hParent); child; child = tree->GetNextItem(child, TVGN_NEXT)) {
        CRobloxTreeCtrlNode* sibling = reinterpret_cast<CRobloxTreeCtrlNode*>(tree->GetItemData(child));
        if (order > sibling->order) {
            after = child;
            continue;
        }
        if (order != sibling->order)
            break;
        RBX::DataModel::Lock lock(tree->getDataModel());
        if (!(instance->getName() >= sibling->instance->getName()))
            break;
        after = child;
    }
    insert.hInsertAfter = after;
    return tree->InsertItem(&insert);
}

CRobloxTreeCtrlNode* CRobloxTreeCtrlNode::addChild(const boost::shared_ptr<RBX::Instance>& child)
{
    boost::shared_ptr<RBX::Metadata::Reflection> reflection = RBX::Metadata::Reflection::singleton();
    RBX::Reflection::Metadata::Class* metadata = reflection->lookup(child->getDescriptor(), true);
    if (!metadata || metadata->explorerOrder() < 0)
        return NULL;
    {
        boost::recursive_mutex::scoped_lock lock(tree->mutex);
        std::map<const RBX::Instance*, CRobloxTreeCtrlNode*>::iterator it = children.find(child.get());
        if (it != children.end())
            return it->second;
    }
    CRobloxTreeCtrlNode* node = new CRobloxTreeCtrlNode(this, child, tree);
    node->initialize();
    return node;
}

bool CRobloxTreeCtrlNode::hasChildren()
{
    RBX::DataModel::Lock lock(tree->getDataModel());
    boost::shared_ptr<const std::vector<boost::shared_ptr<RBX::Instance> > > list = instance->children.read();
    if (!list)
        return false;
    std::vector<boost::shared_ptr<RBX::Instance> >::const_iterator end = list->end();
    for (std::vector<boost::shared_ptr<RBX::Instance> >::const_iterator it = list->begin(); it != end; ++it) {
        boost::shared_ptr<RBX::Metadata::Reflection> reflection = RBX::Metadata::Reflection::singleton();
        RBX::Reflection::Metadata::Class* metadata = reflection->lookup((*it)->getDescriptor(), true);
        if (metadata && metadata->explorerOrder() >= 0)
            return true;
    }
    return false;
}
