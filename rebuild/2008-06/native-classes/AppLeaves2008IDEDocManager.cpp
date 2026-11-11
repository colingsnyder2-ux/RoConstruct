// Inactive native 2008-06 CIDEDocManager (native-headers/AppLeaves2008/IDEDocManager2008.h). The original
// bodies sit in the CRobloxApp unit (00449ae0, 0044a150, 0044abd0); the
// constructor 00449910 is in AppLeaves2008IDEDocManagerCtor.cpp (it needs the view/document class headers).
// CRobloxApp.cpp is not edited.
// >>> native-status (generated) -- do not edit >>>
// AppLeaves2008IDEDocManager | 2008-06 | selection unverified
// unmapped (no binary link) | by -
// <<< native-status | src 3162755d | roc native-status --write
#include "AppLeaves2008/IDEDocManager2008.h"
#include <afxpriv.h>
#include <stdexcept>

void reportDocumentException(const std::exception& error);   // 00428850 (DocumentException.cpp)

BOOL CIDEDocManager::DoPromptFileName(CString& fileName, UINT nIDSTitle, DWORD lFlags, BOOL bOpenFileDialog,
                                      CDocTemplate* pTemplate)
{
    if (pTemplate == NULL)
        pTemplate = playTemplate;
    return CDocManager::DoPromptFileName(fileName, nIDSTitle, lFlags, bOpenFileDialog, pTemplate);
}

void CIDEDocManager::OnFileNew()
{
    pendingPlayError.reset();
    CDocument* document = playTemplate->OpenDocumentFile(NULL, TRUE);
    try
    {
        throwPendingPlayError();
    }
    catch (std::exception& e)
    {
        reportDocumentException(e);
        AfxMessageBox(AFX_IDP_FAILED_TO_CREATE_DOC);
        if (document)
            document->OnCloseDocument();
    }
}

// Template members emitted by this unit (bodies byte-identical to the 2008-06 client).
template class boost::scoped_ptr<std::exception>;
