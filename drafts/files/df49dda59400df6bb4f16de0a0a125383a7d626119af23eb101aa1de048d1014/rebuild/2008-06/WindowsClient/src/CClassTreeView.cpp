#include "CClassTreeView.h"
#include "reflection/object.h"
#include "reflection/enumconverter.h"
#include "reflection/Metadata.h"
#include "AuthoringSettings.h"
#include <boost/bind.hpp>
#include <algorithm>

void CReflectionTreeView::setItemStyle(HTREEITEM item, const RBX::Reflection::Metadata::Item* metadata)
{
    if (!metadata)
        return;
    if (metadata->unknown_131) {
        CXTLogFont font;
        if (GetFont()->GetObject(sizeof(LOGFONT), &font)) {
            font.lfStrikeOut = TRUE;
            SetItemFont(item, font);
        }
    }
    if (metadata->unknown_132) {
        CXTLogFont font;
        if (GetFont()->GetObject(sizeof(LOGFONT), &font)) {
            font.lfItalic = TRUE;
            SetItemFont(item, font);
        }
    }
}

IMPLEMENT_DYNCREATE(CClassTreeView, CXTTreeView)

BEGIN_MESSAGE_MAP(CClassTreeView, CXTTreeView)
    ON_WM_CREATE()
    ON_NOTIFY_REFLECT(TVN_SELCHANGED, OnSelChanged)
END_MESSAGE_MAP()

CClassTreeView::CClassTreeView()
    : memberView(NULL)
{
}

CClassTreeView::~CClassTreeView()
{
}

// Original 00433ab0: 16x16 ILC_COLOR24|ILC_MASK list from a bitmap resource, masked by the
// XTP-derived mask colour.
static BOOL createImageList(CImageList& list, UINT id)
{
    if (!list.Create(16, 16, ILC_COLOR24 | ILC_MASK, 0, 1))
        return FALSE;
    CBitmap bitmap;
    bitmap.Attach(::LoadBitmap(AfxFindResourceHandle(MAKEINTRESOURCE(id), RT_BITMAP), MAKEINTRESOURCE(id)));
    list.Add(&bitmap, CXTPImageManager::GetBitmapMaskColor(bitmap, CPoint(0, 0)));
    return TRUE;
}

int CClassTreeView::OnCreate(LPCREATESTRUCT cs)
{
    if (CXTTreeView::OnCreate(cs) == -1)
        return -1;
    if (!createImageList(images, 0xc4))
        return -1;
    GetTreeCtrl().SetImageList(&images, TVSIL_NORMAL);
    return 0;
}

void CClassTreeView::OnSelChanged(NMHDR* nm, LRESULT* result)
{
    const RBX::Reflection::Descriptor* descriptor =
        reinterpret_cast<const RBX::Reflection::Descriptor*>(reinterpret_cast<NMTREEVIEW*>(nm)->itemNew.lParam);
    if (memberView) {
        if (const RBX::Reflection::ClassDescriptor* c = dynamic_cast<const RBX::Reflection::ClassDescriptor*>(descriptor))
            memberView->showClass(c);
        else if (const RBX::Reflection::EnumDescriptor* e = dynamic_cast<const RBX::Reflection::EnumDescriptor*>(descriptor))
            memberView->showEnum(e);
    }
    if (declarationView)
        declarationView->showDescriptor(descriptor);
    *result = 0;
}

void CClassTreeView::OnInitialUpdate()
{
    CXTTreeView::OnInitialUpdate();
    boost::recursive_mutex::scoped_lock lock(RBX::Reflection::sync());
    addClass(&RBX::Reflection::ClassDescriptor::rootDescriptor());
    std::for_each(RBX::Reflection::EnumDescriptor::enumsBegin(), RBX::Reflection::EnumDescriptor::enumsEnd(),
                  boost::bind(&CClassTreeView::addEnum, this, _1));
    TVSORTCB sort;
    sort.hParent = TVI_ROOT;
    sort.lpfnCompare = compareItems;
    GetTreeCtrl().SortChildrenCB(&sort);
}

void CClassTreeView::addEnum(const RBX::Reflection::EnumDescriptor* descriptor)
{
    CString text;
    text.Format("%s", descriptor->name.c_str());
    LPCTSTR label = text;
    HTREEITEM item = GetTreeCtrl().InsertItem(TVIF_TEXT | TVIF_IMAGE | TVIF_SELECTEDIMAGE, label, 9, 9, 0, 0, 0, TVI_ROOT, TVI_LAST);
    GetTreeCtrl().SetItem(item, TVIF_PARAM, NULL, 0, 0, 0, 0, (LPARAM)descriptor);
}

// Original 00433500: sort rank of a browser item by its dynamic descriptor type.
static int rank(const RBX::Reflection::Descriptor* descriptor)
{
    if (dynamic_cast<const RBX::Reflection::EnumDescriptor::Item*>(descriptor))
        return 5;
    if (dynamic_cast<const RBX::Reflection::EnumDescriptor*>(descriptor))
        return 4;
    if (dynamic_cast<const RBX::Reflection::SignalDescriptor*>(descriptor))
        return 3;
    if (dynamic_cast<const RBX::Reflection::PropertyDescriptor*>(descriptor))
        return 2;
    if (dynamic_cast<const RBX::Reflection::FunctionDescriptor*>(descriptor))
        return 1;
    if (dynamic_cast<const RBX::Reflection::ClassDescriptor*>(descriptor))
        return 0;
    return 100;
}

int CALLBACK CClassTreeView::compareItems(LPARAM item1, LPARAM item2, LPARAM)
{
    const RBX::Reflection::Descriptor* first = reinterpret_cast<const RBX::Reflection::Descriptor*>(item1);
    const RBX::Reflection::Descriptor* second = reinterpret_cast<const RBX::Reflection::Descriptor*>(item2);
    int firstRank = rank(first);
    int secondRank = rank(second);
    if (firstRank != secondRank)
        return firstRank - secondRank;
    return strcmp(first->name.c_str(), second->name.c_str());
}

void CClassTreeView::addClass(const RBX::Reflection::ClassDescriptor* descriptor)
{
    RBX::Reflection::Metadata::Class* metadata = RBX::Metadata::Reflection::singleton()->lookup(*descriptor, false);
    bool show = true;
    if (metadata) {
        AuthoringSettings& settings = AuthoringSettings::singleton();
        show = (!metadata->unknown_131 || settings.showDepricatedObjects)
            && (!metadata->unknown_132 || settings.showPreliminaryObjects) && metadata->unknown_130;
    }
    if (show) {
        HTREEITEM item = GetTreeCtrl().InsertItem(TVIF_TEXT | TVIF_IMAGE | TVIF_SELECTEDIMAGE, descriptor->name.c_str(), 3, 3, 0, 0, 0, TVI_ROOT, TVI_LAST);
        GetTreeCtrl().SetItem(item, TVIF_PARAM, NULL, 0, 0, 0, 0, (LPARAM)descriptor);
        setItemStyle(item, metadata);
    }
    std::for_each(descriptor->derivedClasses_begin(), descriptor->derivedClasses_end(),
                  boost::bind(&CClassTreeView::addClass, this, _1));
}
