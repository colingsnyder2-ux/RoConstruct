// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs-atl90-dll roc_declaration_view_native_string_boundaries706ef8adc45a4d91.cpp

// Candidate translation unit (score above; library headers required).
#pragma include_alias("atlsimpstr.h", "roc_dom_native_cstring_call_boundaries_headera7016f3a175a8c2b.cpp")
#pragma include_alias(<atlsimpstr.h>, <roc_dom_native_cstring_call_boundaries_headera7016f3a175a8c2b.cpp>)
#pragma include_alias("xstring", "roc_dom_native_stdstring_cstr_boundary_header3da8e64d105bf835.cpp")
#pragma include_alias(<xstring>, <roc_dom_native_stdstring_cstr_boundary_header3da8e64d105bf835.cpp>)
// Match the /EHsc compiler prelude while library preprocessing runs without flags.
#define _CPPUNWIND 1
#define _AFXDLL
#include <afxwin.h>
#include <string>
#include <afxext.h>
#include <afxhtml.h>
#include <atlbase.h>
#include <atlcom.h>
using namespace ATL;
// Native MFC receiver; GetHtmlDocument uses this at offset zero.
// All member views are pointer types and offsets proven by QI/Release stores.
class CDeclarationView {
public:
    void OnDocumentComplete(LPCTSTR);
    void setDeclaration(const void*, const char*, const char*); // native00434020: opaque node pointer, two text pointers, ret12
};
#define document (*reinterpret_cast<CComQIPtr<IHTMLDocument2>*>(reinterpret_cast<char*>(this)+0xf4))
#define declaration (*reinterpret_cast<CComQIPtr<IHTMLElement>*>(reinterpret_cast<char*>(this)+0xf8))
#define ownerDiv (*reinterpret_cast<CComQIPtr<IHTMLElement>*>(reinterpret_cast<char*>(this)+0xfc))
#define owner (*reinterpret_cast<CComQIPtr<IHTMLElement>*>(reinterpret_cast<char*>(this)+0x100))
#define summaryDiv (*reinterpret_cast<CComQIPtr<IHTMLElement>*>(reinterpret_cast<char*>(this)+0x104))
#define summary (*reinterpret_cast<CComQIPtr<IHTMLElement>*>(reinterpret_cast<char*>(this)+0x108))
#define deprecated (*reinterpret_cast<CComQIPtr<IHTMLElement>*>(reinterpret_cast<char*>(this)+0x10c))
#define preliminary (*reinterpret_cast<CComQIPtr<IHTMLElement>*>(reinterpret_cast<char*>(this)+0x110))
void CDeclarationView::OnDocumentComplete(LPCTSTR)
{
    document = reinterpret_cast<CHtmlView*>(this)->GetHtmlDocument();
    if (document)
    {
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
        deprecated = element;
        element.Release();
        all->item(CComVariant("PreliminaryElement"), CComVariant(), &element);
        preliminary = element;
        element.Release();
        all->item(CComVariant("SummaryDiv"), CComVariant(), &element);
        summaryDiv = element;
        element.Release();
        all->item(CComVariant("Summary"), CComVariant(), &element);
        summary = element;
    }
    else
    {
        declaration.Release();
        ownerDiv.Release();
        owner.Release();
        summaryDiv.Release();
        summary.Release();
        deprecated.Release();
        preliminary.Release();
    }
    setDeclaration(NULL, NULL, NULL);
}
// Native node data is opaque. std::string+134 and bool+131/132 are proven reads.
void CDeclarationView::setDeclaration(const void* node, const char* text, const char* ownerText)
{
    if (declaration)
        declaration->put_innerHTML(CComBSTR(text ? text : ""));
    if (ownerDiv)
    {
        CComPtr<IHTMLStyle> style;
        ownerDiv->get_style(&style);
        style->put_display(ownerText ? CComBSTR("block") : CComBSTR("none"));
        owner->put_innerHTML(CComBSTR(ownerText));
    }
    if (summaryDiv)
    {
        CString text(node ? reinterpret_cast<const std::string*>(static_cast<const char*>(node)+0x134)->c_str() : "");
        CComPtr<IHTMLStyle> style;
        summaryDiv->get_style(&style);
        style->put_display(!text.IsEmpty() ? CComBSTR("block") : CComBSTR("none"));
        if (!text.IsEmpty())
            summary->put_innerHTML(CComBSTR(static_cast<LPCSTR>(text)));
    }
    if (deprecated)
    {
        CComPtr<IHTMLStyle> style;
        deprecated->get_style(&style);
        style->put_display(node && *reinterpret_cast<const bool*>(static_cast<const char*>(node)+0x131) ? CComBSTR("block") : CComBSTR("none"));
    }
    if (preliminary)
    {
        CComPtr<IHTMLStyle> style;
        preliminary->get_style(&style);
        style->put_display(node && *reinterpret_cast<const bool*>(static_cast<const char*>(node)+0x132) ? CComBSTR("block") : CComBSTR("none"));
    }
}
#undef document
#undef declaration
#undef ownerDiv
#undef owner
#undef summaryDiv
#undef summary
#undef deprecated
#undef preliminary
