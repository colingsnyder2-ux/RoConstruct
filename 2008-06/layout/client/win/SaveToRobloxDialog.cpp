// =============================================================================
// SaveToRobloxDialog.cpp
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/win/SaveToRobloxDialog.cpp
//
// Recovered from the shipped binary and tidied for this layout. Where this file
// is a compiled unit, its object is checked identical to the live recovery source
// (same compiler and flags). Not a source-only client, a server match or a runtime gate.
// Names or fields marked "// INFERRED:" are not in the binary and rest on stated evidence.
// Hex numbers in comments are addresses in the 2008-06 binary; more notes are in
// rebuild/2008-06/layout/evidence.json.
// =============================================================================

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

CString applicationBaseUrl();

CPublishAsPlaceDialog::CPublishAsPlaceDialog(IDispatch* dispatch, CWnd* parent)
    : CSaveToRobloxDialog(dispatch, applicationBaseUrl() + "/IDE/Upload.aspx", parent) {}

CSaveModelToRobloxDialog::CSaveModelToRobloxDialog(IDispatch* dispatch, CWnd* parent)
    : CSaveToRobloxDialog(dispatch, applicationBaseUrl() + "/UI/Save.aspx?type=Model", parent) {}
