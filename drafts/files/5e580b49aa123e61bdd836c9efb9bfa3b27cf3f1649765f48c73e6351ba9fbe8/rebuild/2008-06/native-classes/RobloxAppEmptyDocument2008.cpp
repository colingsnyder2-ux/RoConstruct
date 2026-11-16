// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include "CRobloxApp.h"
#include "CIDEDocManager.h"
void CRobloxApp::initializeEmptyDocument()
{
    // 0044a2c0 reads CWinApp::m_pDocManager (+58), then browser template (+20).
    static_cast<CIDEDocManager*>(m_pDocManager)->templates[0]->OpenDocumentFile(NULL, TRUE);
}
#include <algorithm>
#include <functional>
BOOL CRobloxApp::openFiles(std::vector<std::string>::iterator first,
                          std::vector<std::string>::iterator last)
{
    return std::find_if(first, last,
        std::bind1st(std::mem_fun(&CRobloxApp::openFileFailed), this)) == last;
}

int CRobloxApp::openFileFailed(std::string filename)
{
    return !openFile(filename);
}
