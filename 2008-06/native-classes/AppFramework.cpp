// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/mfc-noinline-pcxstr /I{headers}/std-noinline-string /I{headers}/../native-donor-2007
// ThreadLogManager's donor inline constructor needs this original declaration.
namespace RBX { const char* get_thread_name(); }
#include "CRobloxApp.h"
#include "CMainFrame.h"

BOOL CRobloxApp::initializeFramework(bool fullscreen)
{
    if (m_pMainWnd) {
        if (!m_pMainWnd->IsWindowVisible())
            static_cast<CMainFrame*>(m_pMainWnd)->showFrame(m_nCmdShow);
        return m_pMainWnd->m_hWnd != NULL;
    }
    CMainFrame* frame = new CMainFrame;
    if (!frame) return FALSE;
    if (!frame->LoadFrame(0x80, WS_OVERLAPPEDWINDOW | FWS_ADDTOTITLE, NULL, NULL))
        return FALSE;
    if (fullscreen) frame->hideEditorChrome();
    else frame->showEditorChrome(false);
    frame->DragAcceptFiles();
    frame->showFrame(m_nCmdShow);
    m_pMainWnd = frame;
    if (!m_atomApp && !m_atomSystemTopic) EnableShellOpen();
    return TRUE;
}
