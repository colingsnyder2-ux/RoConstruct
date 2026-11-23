// =============================================================================
// RobloxDoc.cpp
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/win/RobloxDoc.cpp
//
// Recovered from the shipped binary and tidied for this layout. Where this file
// is a compiled unit, its object is checked identical to the live recovery source
// (same compiler and flags). Not a source-only client, a server match or a runtime gate.
// Names or fields marked "// INFERRED:" are not in the binary and rest on stated evidence.
// Hex numbers in comments are addresses in the 2008-06 binary; more notes are in
// rebuild/2008-06/layout/evidence.json.
// =============================================================================

#include "CUploadPlaceDialog.h"

CString applicationBaseUrl();

CUploadPlaceDialog::CUploadPlaceDialog(IDispatch* dispatch, CWnd* parent)
    : CSaveToRobloxDialog(dispatch, applicationBaseUrl() + "/Game/Upload.aspx", parent) {}

#include <afxwin.h>
#include "CRobloxDoc.h"
#include "CMainFrame.h"
#include "StandardVerbs.h"
#include "NativeExitCommand.h"

void ExitCommand::doIt(RBX::IDataState*) {
    CMainFrame* frame = static_cast<CMainFrame*>(AfxGetApp()->m_pMainWnd);
    if (frame->state104) {
        ::PostMessage(frame->m_hWnd, WM_CLOSE, 0, 0);
        return;
    }
    POSITION position = doc->GetFirstViewPosition();
    if (position) {
        CView* view = doc->GetNextView(position);
        ::PostMessage(view->m_hWnd, WM_COMMAND, ID_FILE_CLOSE, 0);
    }
}
