// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/mfc-noinline-pcxstr
#include "CSaveToRobloxDialog.h"
#include <exdispid.h>

BEGIN_MESSAGE_MAP(CSaveToRobloxDialog, CRobloxDHtmlDialog)
END_MESSAGE_MAP()
BEGIN_EVENTSINK_MAP(CSaveToRobloxDialog, CRobloxDHtmlDialog)
    ON_EVENT(CSaveToRobloxDialog, 102, DISPID_WINDOWCLOSING, WindowClosing, VTS_BOOL VTS_PBOOL)
END_EVENTSINK_MAP()
BEGIN_DHTML_EVENT_MAP(CSaveToRobloxDialog)
END_DHTML_EVENT_MAP()

CSaveToRobloxDialog::CSaveToRobloxDialog(IDispatch* dispatch, const char* location, CWnd* parent)
    : CRobloxDHtmlDialog(0x71, location, parent)
{
    SetExternalDispatch(dispatch);
}
CSaveToRobloxDialog::~CSaveToRobloxDialog() {}

void CSaveToRobloxDialog::WindowClosing(BOOL, VARIANT_BOOL* cancel)
{
    *cancel = -1;
    CString result;
    DDX_DHtml_ElementText("DialogResult", DISPID_A_VALUE, result, TRUE);
    if (result.Compare("") != 0 && atoi(result) == 1)
        OnOK();
    else
        OnCancel();
}

// Original 004060d0 returns the application-owned base URL CString.
CString applicationBaseUrl();

CPublishAsPlaceDialog::CPublishAsPlaceDialog(IDispatch* dispatch, CWnd* parent)
    : CSaveToRobloxDialog(dispatch, applicationBaseUrl() + "/IDE/Upload.aspx", parent) {}

CSaveModelToRobloxDialog::CSaveModelToRobloxDialog(IDispatch* dispatch, CWnd* parent)
    : CSaveToRobloxDialog(dispatch, applicationBaseUrl() + "/UI/Save.aspx?type=Model", parent) {}
