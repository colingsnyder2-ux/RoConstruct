// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /GS-
#include "CRobloxDHtmlDialog.h"
#include "util/Http.h"
#include <exdispid.h>
IMPLEMENT_DYNAMIC(CRobloxDHtmlDialog, CDHtmlDialog)

BEGIN_EVENTSINK_MAP(CRobloxDHtmlDialog, CDHtmlDialog)
    ON_EVENT(CRobloxDHtmlDialog, 102, DISPID_BEFORENAVIGATE2, BeforeNavigate2,
        VTS_DISPATCH VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PBOOL)
    ON_EVENT(CRobloxDHtmlDialog, 102, DISPID_WINDOWCLOSING, WindowClosing, VTS_BOOL VTS_PBOOL)
END_EVENTSINK_MAP()

// Original 0041dcb0; name inferred from its call to Http::trustCheck.
__declspec(noinline) HRESULT __cdecl checkDialogUrl(const char* url)
{
    return RBX::Http::trustCheck(url) ? S_OK : E_FAIL;
}

CRobloxDHtmlDialog::CRobloxDHtmlDialog(UINT dialog, UINT html, CWnd* parent)
    : CDHtmlDialog(dialog, html, parent)
{
    m_bUseHtmlTitle = TRUE;
    SetHostFlags(m_dwHostFlags | 0x01844013);
}

CRobloxDHtmlDialog::CRobloxDHtmlDialog(UINT dialog, const char* location, CWnd* parent)
    : CDHtmlDialog(dialog, 0x72, parent), url(location)
{
    m_bUseHtmlTitle = TRUE;
    SetHostFlags(m_dwHostFlags | 0x01844013);
}

int CRobloxDHtmlDialog::OnInitDialog(void)
{
    CDHtmlDialog::OnInitDialog();
    if (url.length() != 0)
    {
        const char* (std::string::*pc)() const = &std::string::c_str;
        Navigate((url.*pc)(), 0, 0, 0, 0, 0);
        return 0;
    }
    return 1;
}

BOOL CRobloxDHtmlDialog::IsExternalDispatchSafe()
{
    return TRUE;
}

void CRobloxDHtmlDialog::BeforeNavigate2(LPDISPATCH browser, VARIANT* location,
    VARIANT*, VARIANT*, VARIANT*, VARIANT*, BOOL* cancel)
{
    CString address(location->bstrVal);
    if (checkDialogUrl(address))
        *cancel = TRUE;
    else
        OnBeforeNavigate(browser, address);
}

void CRobloxDHtmlDialog::WindowClosing(BOOL, BOOL* cancel)
{
    *cancel = -1;
    CString result;
    DDX_DHtml_ElementText("DialogResult", DISPID_A_VALUE, result, TRUE);
    if (result.Compare("") != 0 && atoi(result) == 1)
        OnOK();
    else
        OnCancel();
}
