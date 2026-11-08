#pragma once
// >>> native-status (generated) -- do not edit >>>
// CSecureHtmlView | 2008-06 | inactive
// unmapped (no indexed address) | unmapped (no binary link) | by -
// <<< native-status | src ed3f334b | roc native-status --write
#include <afxwin.h>
#include <afxext.h>
#include <afxhtml.h>

// Bodies: native-classes/CSecureHtmlView.cpp (7 exact). CRuntimeClass 0081b840 (size 0xf8,
// no CreateObject, base CHtmlView via GetThisClass import), vtable 0081b864, constructor 00465a60
// (CHtmlView::CHtmlView, vtable, byte +0xf4 = 0), destructor 00465a80 / deleting 00465b20.
// Own overrides from the vtable: slots 27, 69 and 118.
class CSecureHtmlView : public CHtmlView {
    DECLARE_DYNAMIC(CSecureHtmlView)
public:
    CSecureHtmlView();                                            // 00465a60
    virtual ~CSecureHtmlView();                                   // 00465a80
    virtual BOOL PreCreateWindow(CREATESTRUCT& cs);               // 00465ae0
    virtual BOOL OnAmbientProperty(COleControlSite* site, DISPID dispid, VARIANT* var); // 00465a90
    virtual void OnBeforeNavigate2(LPCTSTR url, DWORD flags, LPCTSTR targetFrameName,
                                   CByteArray& postedData, LPCTSTR headers, BOOL* cancel); // 00465d70

    bool flag_f4;                                                 // +0xf4, cleared by 00465a60, tested by 00465a90
};
