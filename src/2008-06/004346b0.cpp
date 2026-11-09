// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs-atl90-dll roc_declaration_view_cppunwind_preluded3730c597d42f7c6.cpp

// Candidate translation unit (score above; library headers required).
// Match the /EHsc compiler prelude while library preprocessing runs without flags.
#define _CPPUNWIND 1
#define _AFXDLL
#include <afxwin.h>
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
    void setDeclaration(const char*, const char*, const char*); // native00434020 ret12
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
#undef document
#undef declaration
#undef ownerDiv
#undef owner
#undef summaryDiv
#undef summary
#undef deprecated
#undef preliminary
