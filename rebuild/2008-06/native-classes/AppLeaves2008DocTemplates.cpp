// Inactive native 2008-06 CRbxDocTemplate / CRbxPlayDocTemplate (native-headers/AppLeaves2008/RbxDocTemplates2008.h).
// >>> native-status (generated) -- do not edit >>>
// AppLeaves2008DocTemplates | 2008-06 | selection unverified
// unmapped (no binary link) | by -
// <<< native-status | src 2fec990b | roc native-status --write
#include "AppLeaves2008/RbxDocTemplates2008.h"
#include <afxpriv.h>
#include "CRobloxApp.h"

extern CRobloxApp theApp;   // 0096dbe0 (ecx of the 00449bf0 call in 0044a170)

#ifdef NATIVE_APPLEAVES2008_PENDING
// 0044a170: theApp.initializeFramework(true) (push 1; 00449bf0 tests its argument as a byte), then the
// CDocTemplate::CreateNewFrame import. Needs CRobloxApp::initializeFramework(bool); the committed header declares
// it as (void*), see the proposal in tests/record_native_app_leaves2008.py.
CFrameWnd* CRbxDocTemplate::CreateNewFrame(CDocument* pDoc, CFrameWnd* pOther)
{
    theApp.initializeFramework(true);
    return CMultiDocTemplate::CreateNewFrame(pDoc, pOther);
}
#endif

void CRbxPlayDocTemplate::RemoveDocument(CDocument* pDoc)
{
    CMultiDocTemplate::RemoveDocument(pDoc);
    if (pDoc == playDocument)
        playDocument = 0;
}

CDocument* CRbxPlayDocTemplate::openDocumentFile(LPCTSTR lpszPathName, BOOL bMakeVisible)
{
    lastError = "";
    CDocument* pDocument = CreateNewDocument();
    if (pDocument == NULL)
    {
        lastError = "CDocTemplate::CreateNewDocument returned NULL";
        AfxMessageBox(AFX_IDP_FAILED_TO_CREATE_DOC);
        return NULL;
    }

    BOOL bAutoDelete = pDocument->m_bAutoDelete;
    pDocument->m_bAutoDelete = FALSE;
    CFrameWnd* pFrame = CreateNewFrame(pDocument, NULL);
    pDocument->m_bAutoDelete = bAutoDelete;
    if (pFrame == NULL)
    {
        lastError = "CreateNewFrame returned NULL";
        AfxMessageBox(AFX_IDP_FAILED_TO_CREATE_DOC);
        delete pDocument;
        return NULL;
    }

    if (lpszPathName == NULL)
    {
        SetDefaultTitle(pDocument);
        if (!bMakeVisible)
            pDocument->m_bEmbedded = TRUE;
        if (!pDocument->OnNewDocument())
        {
            lastError = "CDocument::OnNewDocument returned FALSE";
            pFrame->DestroyWindow();
            return NULL;
        }
        m_nUntitledCount++;
    }
    else
    {
        CWaitCursor wait;
        if (!pDocument->OnOpenDocument(lpszPathName))
        {
            lastError = "CDocument::OnNewDocument returned FALSE (v2)";
            pFrame->DestroyWindow();
            return NULL;
        }
        pDocument->SetPathName(lpszPathName);
    }

    InitialUpdateFrame(pFrame, pDocument, bMakeVisible);
    return pDocument;
}
