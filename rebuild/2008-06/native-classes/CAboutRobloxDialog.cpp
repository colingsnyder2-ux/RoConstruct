// >>> native-status (generated) -- do not edit >>>
// CAboutRobloxDialog | 2008-06 | inactive
// unmapped (no binary link) | by -
// <<< native-status | src f0b941d0 | roc native-status --write
#include "CAboutRobloxDialog.h"

IMPLEMENT_DYNCREATE(CAboutRobloxDialog, CRobloxDHtmlDialog)

BEGIN_MESSAGE_MAP(CAboutRobloxDialog, CRobloxDHtmlDialog)
END_MESSAGE_MAP()

BEGIN_DHTML_EVENT_MAP(CAboutRobloxDialog)
    DHTML_EVENT_ONCLICK("ButtonOK", OnClickedButtonOK)
END_DHTML_EVENT_MAP()

CAboutRobloxDialog::CAboutRobloxDialog(CWnd* parent)
    : CRobloxDHtmlDialog(117, 118, parent)
{
    SetHostFlags(m_dwHostFlags | 0x01844007);
}

CAboutRobloxDialog::~CAboutRobloxDialog()
{
}

BOOL CAboutRobloxDialog::OnInitDialog()
{
    CRobloxDHtmlDialog::OnInitDialog();
    return TRUE;
}

void CAboutRobloxDialog::OnDocumentComplete(LPDISPATCH browser, LPCTSTR location)
{
    CDHtmlDialog::OnDocumentComplete(browser, location);
    UpdateData(FALSE);
}

HRESULT CAboutRobloxDialog::OnClickedButtonOK(IHTMLElement*)
{
    OnOK();
    return S_OK;
}
