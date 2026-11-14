// >>> native-status (generated) -- do not edit >>>
// CMemberTreeView | 2008-06 | 6 byte-exact, inactive (not link-selected)
// 6/8 mapped addresses byte-exact | 2 unproved | no mapped strings | by king_originala (+3) (mixed 4)
// <<< native-status | src f17710cf | roc native-status --write
// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /D_XTP_STATICLINK /D_XTPLIB_NOAUTOLINK /I{headers}/std-noinline-string
// The original calls basic_string::c_str through msvcp90 (addEnumItem 00433eae, addSignal 004354b3, addProperty,
// addFunction): same out-of-line std::string overlay as the CRobloxApp / CMainFrame units.
#include "CClassTreeView.h"
#include "reflection/object.h"
#include "reflection/enumconverter.h"
#include "reflection/Metadata.h"
#include "AuthoringSettings.h"
#include <boost/bind.hpp>
#include <boost/ref.hpp>
#include <algorithm>

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

// Same body as CClassTreeView.cpp's 00433ab0 (the original binds both views' OnCreate to one body).
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

// 004352a0. Parked (header): the original tests the bIsPublic bit inline (test byte ptr [ebp + 0x10], 1 at
// 004353a5); reflection/property.h declares PropertyDescriptor::isPublic out of line, so this body calls it.
// Everything else matches once std::string::c_str is imported (std-noinline-string flags above).
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
    if (!descriptor->isPublic())
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

// Original 00435510: appends one argument name to a function's label, comma-separated.
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

// Template members emitted by this unit (bodies byte-identical to the 2008-06 client).
template class boost::_bi::value<CMemberTreeView *>;
