// >>> native-status (generated) -- do not edit >>>
// DocumentLaunch | 2008-06 | selection unverified
// unmapped (no binary link) | by -
// <<< native-status | src ffd063b0 | roc native-status --write
#include <afxwin.h>
#include <afxpriv.h>
#include <shlobj.h>
#include <stdexcept>

void AFXAPI AfxGetModuleShortFileName(HINSTANCE, CString&);

void launchDocumentProcess(const char* first, const char* second)
{
    CString folder;
    if (SHGetFolderPathA(NULL, CSIDL_COMMON_DOCUMENTS, NULL, 0, folder.GetBuffer(MAX_PATH)) != S_OK)
        throw std::runtime_error("Unable to get common document folder");
    folder.ReleaseBuffer();
    CString executable;
    AfxGetModuleShortFileName(AfxGetApp()->m_hInstance, executable);
    CString arguments;
    if (first) arguments += first;
    if (second) arguments += second;
    CWnd* main = AfxGetMainWnd();
    if ((UINT_PTR)ShellExecuteA(main->m_hWnd, "open", executable, arguments, folder, SW_SHOW) <= 32)
        throw std::runtime_error("ShellExecute failed");
}
