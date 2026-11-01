#pragma once
#include <afxwin.h>
#include <afxdisp.h>
#include <afxdhtml.h>
#include <string>

class CRobloxDHtmlDialog : public CDHtmlDialog {
    DECLARE_DYNAMIC(CRobloxDHtmlDialog)
    DECLARE_EVENTSINK_MAP()
public:
    std::string url;
    CRobloxDHtmlDialog(UINT, UINT, CWnd* = NULL);
    CRobloxDHtmlDialog(UINT, const char*, CWnd* = NULL);
    virtual BOOL OnInitDialog();
    virtual BOOL IsExternalDispatchSafe();
    void BeforeNavigate2(LPDISPATCH, VARIANT*, VARIANT*, VARIANT*, VARIANT*, VARIANT*, BOOL*);
    void WindowClosing(BOOL, BOOL*);
};
