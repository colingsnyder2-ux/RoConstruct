#include <afxwin.h>
#include <afxpriv.h>
#include <shlobj.h>
#include <stdexcept>
#include "CRobloxDoc.h"

void AFXAPI AfxGetModuleShortFileName(HINSTANCE, CString&);
static __declspec(noinline) void launch(const char* first, const char* second)
{
    CString folder;
    if (SHGetFolderPathA(NULL, CSIDL_COMMON_DOCUMENTS, NULL, 0, folder.GetBuffer(MAX_PATH)) != S_OK)
        throw std::runtime_error("Unable to get common document folder");
    folder.ReleaseBuffer();
    CString executable;
    CWinApp* app = afxCurrentWinApp;
    AfxGetModuleShortFileName(app->m_hInstance, executable);
    CString args;
    if (first) args += first;
    if (second) args += second;
    CWinThread* thread = AfxGetThread();
    CWnd* main = thread ? thread->GetMainWnd() : NULL;
    if ((UINT_PTR)ShellExecuteA(main->m_hWnd, "open", executable, args, folder, SW_SHOW) <= 32)
        throw std::runtime_error("ShellExecute failed");
}
CString applicationBaseUrl();
CString documentUrl(CRobloxDoc*, const char*);
void CRobloxDoc::handle_4500d0()
{
    try { launch(documentUrl(this, "Visit"), (" -script \"loadfile('" + applicationBaseUrl() + "/game/visit.ashx')()\"")); }
    catch (const std::exception& e) { AfxMessageBox(e.what(), 0, 0); }
}
void CRobloxDoc::handle_4501c0()
{
    try { launch(documentUrl(this, "Server"), (" -script \"loadfile('" + applicationBaseUrl() + "/game/gameserver.ashx')(0, 53640)\"")); }
    catch (const std::exception& e) { AfxMessageBox(e.what(), 0, 0); }
}
void CRobloxDoc::handle_4502b0()
{
    try { launch(NULL, (" -script \"loadfile('" + applicationBaseUrl() + "/game/join.ashx?UserID=0&serverPort=53640')()\"")); }
    catch (const std::exception& e) { AfxMessageBox(e.what(), 0, 0); }
}
