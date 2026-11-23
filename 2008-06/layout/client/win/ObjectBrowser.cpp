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

#include "CDeclarationView.h"
#include "reflection/function.h"
#include "reflection/property.h"
#include "reflection/signal.h"
#include "reflection/enumconverter.h"
#include "reflection/Metadata.h"
#include <G3D/format.h>
#include <boost/bind.hpp>
#include <boost/ref.hpp>
#include <string>

IMPLEMENT_DYNCREATE(CDeclarationView, CHtmlView)

BEGIN_MESSAGE_MAP(CDeclarationView, CHtmlView)
END_MESSAGE_MAP()

CDeclarationView::CDeclarationView()
{
}

CDeclarationView::~CDeclarationView()
{
}

void CDeclarationView::OnInitialUpdate()
{
    CHtmlView::OnInitialUpdate();
    LoadFromResource(0xd2);
}

void CDeclarationView::setContent(const RBX::Reflection::Metadata::Item* item, const char* declarationText,
                                  const char* ownerName)
{
    if (declaration)
        declaration->put_innerHTML(CComBSTR(declarationText ? declarationText : ""));
    if (ownerDiv) {
        CComPtr<IHTMLStyle> style;
        ownerDiv->get_style(&style);
        style->put_display(ownerName ? CComBSTR("block") : CComBSTR("none"));
        owner->put_innerHTML(CComBSTR(ownerName));
    }
    if (summaryDiv) {
        CString summaryText(item ? item->unknown_134.c_str() : "");
        CComPtr<IHTMLStyle> style;
        summaryDiv->get_style(&style);
        style->put_display(!summaryText.IsEmpty() ? CComBSTR("block") : CComBSTR("none"));
        if (!summaryText.IsEmpty())
            summary->put_innerHTML(CComBSTR(summaryText));
    }
    if (deprecatedElement) {
        CComPtr<IHTMLStyle> style;
        deprecatedElement->get_style(&style);
        style->put_display(item && item->unknown_131 ? CComBSTR("block") : CComBSTR("none"));
    }
    if (preliminaryElement) {
        CComPtr<IHTMLStyle> style;
        preliminaryElement->get_style(&style);
        style->put_display(item && item->unknown_132 ? CComBSTR("block") : CComBSTR("none"));
    }
}

void CDeclarationView::OnDocumentComplete(LPCTSTR url)
{
    document = GetHtmlDocument();
    if (document) {
        CComPtr<IHTMLElementCollection> all;
        document->get_all(&all);
        CComPtr<IDispatch> element;
        all->item(CComVariant("Declaration"), CComVariant(), &element);
        declaration = element;
        element.Release();
        all->item(CComVariant("OwnerDiv"), CComVariant(), &element);
        ownerDiv = element;
        element.Release();
        all->item(CComVariant("Owner"), CComVariant(), &element);
        owner = element;
        element.Release();
        all->item(CComVariant("DeprecatedElement"), CComVariant(), &element);
        deprecatedElement = element;
        element.Release();
        all->item(CComVariant("PreliminaryElement"), CComVariant(), &element);
        preliminaryElement = element;
        element.Release();
        all->item(CComVariant("SummaryDiv"), CComVariant(), &element);
        summaryDiv = element;
        element.Release();
        all->item(CComVariant("Summary"), CComVariant(), &element);
        summary = element;
    } else {
        declaration.Release();
        ownerDiv.Release();
        owner.Release();
        summaryDiv.Release();
        summary.Release();
        deprecatedElement.Release();
        preliminaryElement.Release();
    }
    setContent(NULL, NULL, NULL);
}

// convert<std::string>() 0056f0b0 on a copy. INFERRED: reflection/type.h only declares get<T>; this is the same
namespace RBX { namespace Reflection {
template<class T> T Value::get() const
{
    if (isType<T>())
        return boost::any_cast<const T&>(value);
    Value copy(*this);
    return copy.convert<T>();
}
} }

static void appendArgument(int& count, std::string& text, const RBX::Reflection::SignatureDescriptor::Item& argument)
{
    if (count > 0)
        text += ", ";
    text += argument.type->name.c_str();
    text += " ";
    text += argument.name->c_str();
    if (argument.defaultValue.type() == *argument.type) {
        text += " = ";
        text += argument.defaultValue.get<std::string>();
    }
    ++count;
}

namespace {
// INFERRED: the original reads SignalDescriptor::signature inline (00435ad5..00435b10: [esi + 0x2c] / [esi + 0x18]),
struct SignalSignature : RBX::Reflection::SignalDescriptor {
    static const RBX::Reflection::SignatureDescriptor& of(const RBX::Reflection::SignalDescriptor* signal)
    {
        return static_cast<const SignalSignature*>(signal)->signature;
    }
};
}

void CDeclarationView::showDescriptor(const RBX::Reflection::Descriptor* descriptor)
{
    using namespace RBX::Reflection;
    if (!descriptor) {
        setContent(NULL, NULL, NULL);
        return;
    }
    std::string text;
    const ClassDescriptor* ownerClass = NULL;
    RBX::Reflection::Metadata::Item* item = NULL;
    if (const FunctionDescriptor* function = dynamic_cast<const FunctionDescriptor*>(descriptor)) {
        text = function->getSignature().resultType->name.toString();
        text += " ";
        text += function->name.toString();
        text += "(";
        int count = 0;
        std::for_each(function->getSignature().arguments.begin(), function->getSignature().arguments.end(),
                      boost::bind(&appendArgument, boost::ref(count), boost::ref(text), _1));
        text += ")";
        ownerClass = &function->owner;
        item = RBX::Metadata::Reflection::singleton()->lookup(*function);
    } else if (const PropertyDescriptor* property = dynamic_cast<const PropertyDescriptor*>(descriptor)) {
        text = property->type.name.toString();
        text += " ";
        text += property->name.toString();
        ownerClass = &property->owner;
        item = RBX::Metadata::Reflection::singleton()->lookup(*property);
    } else if (const SignalDescriptor* signal = dynamic_cast<const SignalDescriptor*>(descriptor)) {
        text = "event ";
        text += signal->name.toString();
        text += "(";
        int count = 0;
        std::for_each(SignalSignature::of(signal).arguments.begin(), SignalSignature::of(signal).arguments.end(),
                      boost::bind(&appendArgument, boost::ref(count), boost::ref(text), _1));
        text += ")";
        ownerClass = &signal->owner;
        item = RBX::Metadata::Reflection::singleton()->lookup(*signal);
    } else if (const EnumDescriptor::Item* enumItem = dynamic_cast<const EnumDescriptor::Item*>(descriptor)) {
        text = G3D::format("%d: %s", enumItem->value, enumItem->name.c_str());
    } else if (const ClassDescriptor* classDescriptor = dynamic_cast<const ClassDescriptor*>(descriptor)) {
        text = classDescriptor->name.toString();
        item = RBX::Metadata::Reflection::singleton()->lookup(*classDescriptor, false);
    } else {
        text = descriptor->name.toString();
    }
    setContent(item, text.c_str(), ownerClass ? ownerClass->name.c_str() : NULL);
}

template class ATL::CComPtrBase<IHTMLStyle>;
