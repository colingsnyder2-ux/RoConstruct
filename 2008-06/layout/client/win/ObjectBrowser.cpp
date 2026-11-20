#include "CObjectBrowser.h"
#include <algorithm>

IMPLEMENT_DYNCREATE(CObjectBrowser, CView)

BEGIN_MESSAGE_MAP(CObjectBrowser, CView)
    ON_WM_SIZE()
    ON_WM_CREATE()
END_MESSAGE_MAP()

CObjectBrowser::CObjectBrowser()
{
}

CObjectBrowser::~CObjectBrowser()
{
}

BOOL CObjectBrowser::PreCreateWindow(CREATESTRUCT& cs)
{
    return CView::PreCreateWindow(cs) != FALSE;
}

void CObjectBrowser::OnInitialUpdate()
{
    CView::OnInitialUpdate();
}

void CObjectBrowser::OnDraw(CDC* pDC)
{
}

void CObjectBrowser::OnSize(UINT nType, int cx, int cy)
{
    CView::OnSize(nType, cx, cy);
    if (nType != SIZE_MINIMIZED && classSplitter.m_hWnd) {
        CRect rect;
        classSplitter.GetClientRect(&rect);
        int delta = cy - rect.Height();
        classSplitter.MoveWindow(0, 0, cx, cy, TRUE);
        if (memberSplitter.m_hWnd) {
            int current, minimum;
            memberSplitter.GetRowInfo(0, current, minimum);
            int height = current + delta;
            height = (std::min)(cy - 150, height);
            height = (std::max)(50, height);
            memberSplitter.SetRowInfo(0, height, 0);
            memberSplitter.RecalcLayout();
        }
    }
}

int CObjectBrowser::OnCreate(LPCREATESTRUCT cs)
{
    if (CView::OnCreate(cs) == -1)
        return -1;
    if (!classSplitter.CreateStatic(this, 1, 2))
        return -1;
    classSplitter.SetSplitterStyle(XT_SPLIT_NOBORDER);
    CCreateContext context;
    context.m_pCurrentDoc = GetDocument();
    if (!classSplitter.CreateView(0, 0, _RUNTIME_CLASS(CClassTreeView), CSize(200, 600), &context))
        return -1;
    if (!memberSplitter.CreateStatic(&classSplitter, 2, 1, WS_CHILD | WS_VISIBLE | WS_BORDER, classSplitter.IdFromRowCol(0, 1)))
        return -1;
    if (!memberSplitter.CreateView(0, 0, _RUNTIME_CLASS(CMemberTreeView), CSize(300, 200), &context))
        return -1;
    if (!memberSplitter.CreateView(1, 0, _RUNTIME_CLASS(CDeclarationView), CSize(100, 190), &context))
        return -1;
    CClassTreeView* classView = static_cast<CClassTreeView*>(classSplitter.GetPane(0, 0));
    CMemberTreeView* memberView = static_cast<CMemberTreeView*>(memberSplitter.GetPane(0, 0));
    CDeclarationView* declarationView = static_cast<CDeclarationView*>(memberSplitter.GetPane(1, 0));
    classView->memberView = memberView;
    classView->declarationView = declarationView;
    memberView->declarationView = declarationView;
    return 0;
}

#include "CClassTreeView.h"
#include "reflection/object.h"
#include "reflection/enumconverter.h"
#include "reflection/Metadata.h"
#include "AuthoringSettings.h"
#include <boost/bind.hpp>
#include <boost/ref.hpp>

IMPLEMENT_DYNCREATE(CMemberTreeView, CXTTreeView)

BEGIN_MESSAGE_MAP(CMemberTreeView, CXTTreeView)
    ON_WM_CREATE()
    ON_NOTIFY_REFLECT(TVN_SELCHANGED, OnSelChanged)
END_MESSAGE_MAP()

CMemberTreeView::CMemberTreeView()
    : showInherited(true), current(NULL)
{
}

CMemberTreeView::~CMemberTreeView()
{
}

void CMemberTreeView::OnInitialUpdate()
{
    CXTTreeView::OnInitialUpdate();
}

static BOOL createImageList(CImageList& list, UINT id)
{
    if (!list.Create(16, 16, ILC_COLOR24 | ILC_MASK, 0, 1))
        return FALSE;
    CBitmap bitmap;
    bitmap.Attach(::LoadBitmap(AfxFindResourceHandle(MAKEINTRESOURCE(id), RT_BITMAP), MAKEINTRESOURCE(id)));
    list.Add(&bitmap, CXTPImageManager::GetBitmapMaskColor(bitmap, CPoint(0, 0)));
    return TRUE;
}

int CMemberTreeView::OnCreate(LPCREATESTRUCT cs)
{
    if (CXTTreeView::OnCreate(cs) == -1)
        return -1;
    if (!createImageList(images, 0xc4))
        return -1;
    GetTreeCtrl().SetImageList(&images, TVSIL_NORMAL);
    return 0;
}

void CMemberTreeView::OnSelChanged(NMHDR* nm, LRESULT* result)
{
    if (declarationView)
        declarationView->showDescriptor(
            reinterpret_cast<const RBX::Reflection::Descriptor*>(reinterpret_cast<NMTREEVIEW*>(nm)->itemNew.lParam));
    *result = 0;
}

void CMemberTreeView::addEnumItem(const RBX::Reflection::Descriptor* item)
{
    HTREEITEM handle = GetTreeCtrl().InsertItem(TVIF_TEXT | TVIF_IMAGE | TVIF_SELECTEDIMAGE, item->name.c_str(), 10, 10, 0, 0, 0, TVI_ROOT, TVI_LAST);
    GetTreeCtrl().SetItem(handle, TVIF_PARAM, NULL, 0, 0, 0, 0, (LPARAM)item);
}

void CMemberTreeView::showEnum(const RBX::Reflection::EnumDescriptor* descriptor)
{
    GetTreeCtrl().DeleteAllItems();
    current = descriptor;
    boost::recursive_mutex::scoped_lock lock(RBX::Reflection::sync());
    std::for_each(descriptor->begin(), descriptor->end(), boost::bind(&CMemberTreeView::addEnumItem, this, _1));
    TVSORTCB sort;
    sort.hParent = TVI_ROOT;
    sort.lpfnCompare = CClassTreeView::compareItems;
    GetTreeCtrl().SortChildrenCB(&sort);
}

void CMemberTreeView::addProperty(const RBX::Reflection::PropertyDescriptor* descriptor)
{
    if (!showInherited && &descriptor->owner != current)
        return;
    RBX::Reflection::Metadata::Member* metadata = RBX::Metadata::Reflection::singleton()->lookup(*descriptor);
    if (metadata) {
        AuthoringSettings& settings = AuthoringSettings::singleton();
        if (metadata->unknown_131 && !settings.showDepricatedObjects)
            return;
        if (metadata->unknown_132 && !settings.showPreliminaryObjects)
            return;
        if (!metadata->unknown_130)
            return;
    }
    // INFERRED: inline bIsPublic test (bit 0 of the byte at descriptor + 0x10, 0043536d); see the comment above.
    if (!(reinterpret_cast<const unsigned char*>(descriptor)[0x10] & 1))
        return;
    HTREEITEM item = GetTreeCtrl().InsertItem(TVIF_TEXT | TVIF_IMAGE | TVIF_SELECTEDIMAGE, descriptor->name.c_str(), 6, 6, 0, 0, 0, TVI_ROOT, TVI_LAST);
    GetTreeCtrl().SetItem(item, TVIF_PARAM, NULL, 0, 0, 0, 0, (LPARAM)descriptor);
    setItemStyle(item, metadata);
}

void CMemberTreeView::addSignal(const RBX::Reflection::SignalDescriptor* descriptor)
{
    if (!showInherited && &descriptor->owner != current)
        return;
    RBX::Reflection::Metadata::Member* metadata = RBX::Metadata::Reflection::singleton()->lookup(*descriptor);
    if (metadata) {
        AuthoringSettings& settings = AuthoringSettings::singleton();
        if (metadata->unknown_131 && !settings.showDepricatedObjects)
            return;
        if (metadata->unknown_132 && !settings.showPreliminaryObjects)
            return;
        if (!metadata->unknown_130)
            return;
    }
    HTREEITEM item = GetTreeCtrl().InsertItem(TVIF_TEXT | TVIF_IMAGE | TVIF_SELECTEDIMAGE, descriptor->name.c_str(), 8, 8, 0, 0, 0, TVI_ROOT, TVI_LAST);
    GetTreeCtrl().SetItem(item, TVIF_PARAM, NULL, 0, 0, 0, 0, (LPARAM)descriptor);
    setItemStyle(item, metadata);
}

static void appendArgument(int& count, std::string& text, const RBX::Reflection::SignatureDescriptor::Item& argument)
{
    if (count > 0)
        text += ", ";
    text += argument.name->c_str();
    ++count;
}

void CMemberTreeView::addFunction(const RBX::Reflection::FunctionDescriptor* descriptor)
{
    if (!showInherited && &descriptor->owner != current)
        return;
    RBX::Reflection::Metadata::Member* metadata = RBX::Metadata::Reflection::singleton()->lookup(*descriptor);
    if (metadata) {
        AuthoringSettings& settings = AuthoringSettings::singleton();
        if (metadata->unknown_131 && !settings.showDepricatedObjects)
            return;
        if (metadata->unknown_132 && !settings.showPreliminaryObjects)
            return;
        if (!metadata->unknown_130)
            return;
    }
    std::string text(descriptor->name.toString());
    text += "(";
    int count = 0;
    std::for_each(descriptor->getSignature().arguments.begin(), descriptor->getSignature().arguments.end(), boost::bind(&appendArgument, boost::ref(count), boost::ref(text), _1));
    text += ")";
    int image = (descriptor->security != RBX::Reflection::FunctionDescriptor::NeedTrustedCaller) + 4;
    LPCTSTR label = text.c_str();
    HTREEITEM item = GetTreeCtrl().InsertItem(TVIF_TEXT | TVIF_IMAGE | TVIF_SELECTEDIMAGE, label, image, image, 0, 0, 0, TVI_ROOT, TVI_LAST);
    GetTreeCtrl().SetItem(item, TVIF_PARAM, NULL, 0, 0, 0, 0, (LPARAM)descriptor);
    setItemStyle(item, metadata);
}

void CMemberTreeView::showClass(const RBX::Reflection::ClassDescriptor* descriptor)
{
    using namespace RBX::Reflection;
    GetTreeCtrl().DeleteAllItems();
    current = descriptor;
    boost::recursive_mutex::scoped_lock lock(sync());
    std::for_each(descriptor->MemberDescriptorContainer<PropertyDescriptor>::descriptors_begin(),
                  descriptor->MemberDescriptorContainer<PropertyDescriptor>::descriptors_end(),
                  boost::bind(&CMemberTreeView::addProperty, this, _1));
    std::for_each(descriptor->MemberDescriptorContainer<FunctionDescriptor>::descriptors_begin(),
                  descriptor->MemberDescriptorContainer<FunctionDescriptor>::descriptors_end(),
                  boost::bind(&CMemberTreeView::addFunction, this, _1));
    std::for_each(descriptor->MemberDescriptorContainer<SignalDescriptor>::descriptors_begin(),
                  descriptor->MemberDescriptorContainer<SignalDescriptor>::descriptors_end(),
                  boost::bind(&CMemberTreeView::addSignal, this, _1));
    TVSORTCB sort;
    sort.hParent = TVI_ROOT;
    sort.lpfnCompare = CClassTreeView::compareItems;
    GetTreeCtrl().SortChildrenCB(&sort);
}

template class boost::_bi::value<CMemberTreeView *>;
