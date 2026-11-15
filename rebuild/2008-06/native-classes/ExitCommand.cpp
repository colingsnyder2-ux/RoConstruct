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
