// Inactive native 2008-06 CRbxPlayDocTemplate::getPlayDocument and the pending play-error helpers
// (native-headers/AppLeaves2008/RbxDocTemplates2008.h). The original imports CSimpleStringT::IsEmpty (mfc90 #4311)
// and operator PCXSTR (#910) here; the recorder compiles this unit through that noinline profile.
#include "AppLeaves2008/RbxDocTemplates2008.h"
#include <afxpriv.h>
#include <stdexcept>
#include <string>
#include "CRobloxDoc.h"

extern CRobloxDoc* activeRobloxDoc;                          // 0096c238 (ActiveDocumentData.cpp)
void setActiveDocument(bool active, CRobloxDoc* document);   // 00405aa0 (ActiveDocument.cpp)

boost::scoped_ptr<std::exception> pendingPlayError;          // 0096dcf4

void setPendingPlayError(const std::exception& e)
{
    pendingPlayError.reset(new std::runtime_error(e.what()));
}

void throwPendingPlayError()
{
    if (pendingPlayError)
    {
        std::runtime_error error(pendingPlayError->what());
        pendingPlayError.reset();
        throw error;
    }
}

CDocument* CRbxPlayDocTemplate::getPlayDocument()
{
    if (playDocument == NULL)
    {
        pendingPlayError.reset();
        CDocument* document = openDocumentFile(NULL, TRUE);
        try
        {
            throwPendingPlayError();
        }
        catch (...)
        {
            AfxMessageBox(AFX_IDP_FAILED_TO_CREATE_DOC);
            if (document)
                document->OnCloseDocument();
            throw;
        }
        if (document == NULL)
        {
            if (!lastError.IsEmpty())
                throw std::runtime_error((LPCTSTR)lastError);
            throw std::runtime_error("OpenDocumentFile returned NULL");
        }
        playDocument = document;
        return document;
    }
    else
    {
        if (!playDocument->SaveModified())
            throw std::runtime_error("User cancelled");
        SetDefaultTitle(playDocument);
        if (!playDocument->OnNewDocument())
            throw std::runtime_error("CDocument::OnNewDocument returned FALSE");
        if (activeRobloxDoc == playDocument)
            setActiveDocument(true, activeRobloxDoc);
        POSITION pos = playDocument->GetFirstViewPosition();
        while (pos)
        {
            CView* view = playDocument->GetNextView(pos);
            pendingPlayError.reset();
            ::SendMessage(view->m_hWnd, WM_INITIALUPDATE, 0, 0);
        }
        return playDocument;
    }
}
