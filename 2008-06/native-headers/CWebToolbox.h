#pragma once
#include <afxwin.h>
#include <afxext.h>
#include <afxhtml.h>

struct IWorkspace;

// RTTI (vtables 0081b864 and 0081c4f4) gives CWebToolbox : CSecureHtmlView : CHtmlView, all
// single inheritance. Constructors 00465a60 and 0046a850 prove the new members; operator new
// in 0046a850 gives sizeof(CWebToolbox) == 0x100. Only members the code writes or reads are named.
class CSecureHtmlView : public CHtmlView {
    DECLARE_DYNCREATE(CSecureHtmlView)
public:
    bool flag_f4;                 // 00465a60 clears it at +0xf4
    CSecureHtmlView();            // 00465a60
    virtual ~CSecureHtmlView();   // 00465a80
};

class CWebToolbox : public CSecureHtmlView {
    DECLARE_DYNCREATE(CWebToolbox)
public:
    CWnd* owner;                  // +0xf8: 004596a0 stores &CRobloxView::window; the overrides focus it
    IWorkspace* site;             // +0xfc: counted workspace set by CRobloxView, cleared by the constructor
    CWebToolbox();                // 0046a850
    virtual ~CWebToolbox();       // 0046a7e0
    void showPage(int);           // 0046a590, builds the page address and navigates; defined in its own unit
};
