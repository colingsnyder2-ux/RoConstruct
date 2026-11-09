// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: mfc-9.0-shared-rtm roc_espeon_nativeplaytemplate90b9d8a6f4d63163.cpp

// Candidate translation unit (score above; library headers required).
#include <afxwin.h>
class NativePlayTemplate:public CMultiDocTemplate { unsigned char observedGap[4]; CString errorText; public: CDocument* OpenDocumentFile(LPCTSTR,BOOL); };
CDocument* NativePlayTemplate::OpenDocumentFile(LPCTSTR lpszPathName,
	BOOL bMakeVisible)
{
	errorText="";
	CDocument* pDocument = CreateNewDocument();
	if (pDocument == NULL)
	{
		errorText="CDocTemplate::CreateNewDocument returned NULL";
		AfxMessageBox(AFX_IDP_FAILED_TO_CREATE_DOC);
		return NULL;
	}
	ASSERT_VALID(pDocument);

	BOOL bAutoDelete = pDocument->m_bAutoDelete;
	pDocument->m_bAutoDelete = FALSE;   // don't destroy if something goes wrong
	CFrameWnd* pFrame = CreateNewFrame(pDocument, NULL);
	pDocument->m_bAutoDelete = bAutoDelete;
	if (pFrame == NULL)
	{
        errorText="CreateNewFrame returned NULL";
		AfxMessageBox(AFX_IDP_FAILED_TO_CREATE_DOC);
		delete pDocument;       // explicit delete on error
		return NULL;
	}
	ASSERT_VALID(pFrame);

	if (lpszPathName == NULL)
	{
		// create a new document - with default document name
		SetDefaultTitle(pDocument);

		// avoid creating temporary compound file when starting up invisible
		if (!bMakeVisible)
			pDocument->m_bEmbedded = TRUE;

		if (!pDocument->OnNewDocument())
		{
			// user has be alerted to what failed in OnNewDocument
			errorText="CDocument::OnNewDocument returned FALSE";
			pFrame->DestroyWindow();
			return NULL;
		}

		// it worked, now bump untitled count
		m_nUntitledCount++;
	}
	else
	{
		// open an existing document
		CWaitCursor wait;
		if (!pDocument->OnOpenDocument(lpszPathName))
		{
			// user has be alerted to what failed in OnOpenDocument
			errorText="CDocument::OnNewDocument returned FALSE (v2)";
			pFrame->DestroyWindow();
			return NULL;
		}
		pDocument->SetPathName(lpszPathName);
	}

	InitialUpdateFrame(pFrame, pDocument, bMakeVisible);
	return pDocument;
}