#include "CDeclarationView.h"
#include "reflection/function.h"
#include "reflection/property.h"
#include "reflection/signal.h"
#include "reflection/enumconverter.h"
#include "reflection/Metadata.h"
#include <G3D/format.h>
#include <boost/bind.hpp>
#include <boost/ref.hpp>
#include <algorithm>
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

// Original 00435550: appends "type name" (and " = default" when the default value has the argument's type)
// for one argument, comma-separated.
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

void CDeclarationView::showDescriptor(const RBX::Reflection::Descriptor* descriptor)
{
    using namespace RBX::Reflection;
    if (!descriptor) {
        setContent(NULL, NULL, NULL);
        return;
    }
    std::string text;
    const ClassDescriptor* ownerClass = NULL;
    Metadata::Item* item = NULL;
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
        std::for_each(signal->getSignature().arguments.begin(), signal->getSignature().arguments.end(),
                      boost::bind(&appendArgument, boost::ref(count), boost::ref(text), _1));
        text += ")";
        ownerClass = &signal->owner;
        item = RBX::Metadata::Reflection::singleton()->lookup(*signal);
    } else if (const EnumDescriptor::Item* enumItem = dynamic_cast<const EnumDescriptor::Item*>(descriptor)) {
        text = G3D::format("%d: %s", enumItem->value, enumItem->name.c_str());  // donor reads +0xc (value) here
    } else if (const ClassDescriptor* classDescriptor = dynamic_cast<const ClassDescriptor*>(descriptor)) {
        text = classDescriptor->name.toString();
        item = RBX::Metadata::Reflection::singleton()->lookup(*classDescriptor, false);
    } else {
        text = descriptor->name.toString();
    }
    setContent(item, text.c_str(), ownerClass ? ownerClass->name.c_str() : NULL);
}
