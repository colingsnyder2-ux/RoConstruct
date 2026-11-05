#include "CRbxDocTemplate.h"
#include "CRobloxApp.h"

extern CRobloxApp theApp;

CFrameWnd* CRbxDocTemplate::CreateNewFrame(CDocument* document, CFrameWnd* other)
{
    theApp.initializeFramework(true);
    return CMultiDocTemplate::CreateNewFrame(document, other);
}

void CRbxPlayDocTemplate::RemoveDocument(CDocument* value)
{
    CMultiDocTemplate::RemoveDocument(value);
    if (value == document) document = NULL;
}
