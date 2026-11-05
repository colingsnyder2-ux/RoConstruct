#pragma once
#include "CRobloxDHtmlDialog.h"

class CAboutRobloxDialog : public CRobloxDHtmlDialog {
    DECLARE_DYNCREATE(CAboutRobloxDialog)
    DECLARE_MESSAGE_MAP()
    DECLARE_DHTML_EVENT_MAP()
public:
    CAboutRobloxDialog(CWnd* = NULL);
    virtual ~CAboutRobloxDialog();
    virtual BOOL OnInitDialog();
    virtual void OnDocumentComplete(LPDISPATCH, LPCTSTR);
    virtual void DoDataExchange(CDataExchange*);
    HRESULT OnClickedButtonOK(IHTMLElement*);
};
