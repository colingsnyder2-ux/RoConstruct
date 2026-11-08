#pragma once
// >>> native-status (generated) -- do not edit >>>
// CAboutRobloxDialog | 2008-06 | inactive
// unmapped (no indexed address) | unmapped (no binary link) | by -
// <<< native-status | src 0c5f5179 | roc native-status --write
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
