#pragma once
// >>> native-status (generated) -- do not edit >>>
// CDeclarationView | 2008-06 | inactive
// unmapped (no indexed address) | unmapped (no binary link) | by -
// <<< native-status | src cc5f53a2 | roc native-status --write
#include <afxwin.h>
#include <afxext.h>
#include <afxhtml.h>
#include <atlbase.h>
#include <mshtml.h>

namespace RBX {
namespace Reflection {
class Descriptor;
namespace Metadata {
class Item;
}
}
}

// Inactive layout recovery: the third pane of the object browser.
// CRuntimeClass 008124e8 (name "CDeclarationView", size 0x114, schema 0xffff, CreateObject 00434640 allocating
// 0x114, base getter 00433370 -> CHtmlView::GetThisClass import); RTTI vtable 00812bc4 (CDeclarationView :
// CHtmlView, single inheritance, offset 0). CHtmlView (mfc90) is 0xf4, so the class adds 0x20 bytes.
// Constructor 00434500: CHtmlView::CHtmlView, vtable, then eight dwords +0xf4..+0x110 = 0 (no EH frame: the
// members' constructors are throw()). Destructor 00434570: Release() through vtable slot 2 of each non-null
// pointer from +0x110 down to +0xf4, then CHtmlView::~CHtmlView (reverse declaration order of eight ATL smart
// pointers). OnDocumentComplete 004346b0 QIs GetHtmlDocument() into +0xf4 with IID 0081056c and each element
// from document->get_all()->item(name) into +0xf8..+0x110 with IID 00812b54; 00434020 calls IHTMLElement
// put_innerHTML (vtable +0xe4) and get_style (+0x40) -> IHTMLStyle put_display (+0x20c) through them.
// Element names (from the item() string arguments) give the member names.
// Message map 00812558: base CHtmlView::GetThisMessageMap import, no entries.
class CDeclarationView : public CHtmlView {
    DECLARE_DYNCREATE(CDeclarationView)
    DECLARE_MESSAGE_MAP()
public:
    CDeclarationView();                                       // 00434500
    virtual ~CDeclarationView();                              // 00434570 (deleting 00434620)
    virtual void OnInitialUpdate();                           // 00434550 (vtable slot 91)
    virtual void OnDocumentComplete(LPCTSTR url);             // 004346b0 (vtable slot 127)

    void showDescriptor(const RBX::Reflection::Descriptor* descriptor);  // 00435860; name provisional
    void setContent(const RBX::Reflection::Metadata::Item* item, const char* declarationText,
                    const char* ownerName);                   // 00434020; name provisional

    CComQIPtr<IHTMLDocument2> document;                       // +0xf4
    CComQIPtr<IHTMLElement> declaration;                      // +0xf8, element "Declaration"
    CComQIPtr<IHTMLElement> ownerDiv;                         // +0xfc, element "OwnerDiv"
    CComQIPtr<IHTMLElement> owner;                            // +0x100, element "Owner"
    CComQIPtr<IHTMLElement> summaryDiv;                       // +0x104, element "SummaryDiv"
    CComQIPtr<IHTMLElement> summary;                          // +0x108, element "Summary"
    CComQIPtr<IHTMLElement> deprecatedElement;                // +0x10c, element "DeprecatedElement"
    CComQIPtr<IHTMLElement> preliminaryElement;               // +0x110, element "PreliminaryElement"
};
