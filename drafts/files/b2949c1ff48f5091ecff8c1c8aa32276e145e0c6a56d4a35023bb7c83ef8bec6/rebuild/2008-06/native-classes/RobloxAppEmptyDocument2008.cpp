// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include "CRobloxApp.h"
#include "CIDEDocManager.h"
void CRobloxApp::initializeEmptyDocument()
{
    // 0044a2c0 reads CWinApp::m_pDocManager (+58), then browser template (+20).
    static_cast<CIDEDocManager*>(m_pDocManager)->templates[0]->OpenDocumentFile(NULL, TRUE);
}
