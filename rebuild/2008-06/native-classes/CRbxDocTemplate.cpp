// >>> native-status (generated) -- do not edit >>>
// CRbxDocTemplate | 2008-06 | selection unverified
// unmapped (no binary link) | by -
// <<< native-status | src 889f1d72 | roc native-status --write
#include "CRbxDocTemplate.h"
#include "CRobloxApp.h"

extern CRobloxApp theApp;

CFrameWnd* CRbxDocTemplate::CreateNewFrame(CDocument* document, CFrameWnd* other)
{
    theApp.initializeFramework(reinterpret_cast<void*>(1)); // header takes void* (00449bf0); same push 1
    return CMultiDocTemplate::CreateNewFrame(document, other);
}

void CRbxPlayDocTemplate::RemoveDocument(CDocument* value)
{
    CMultiDocTemplate::RemoveDocument(value);
    if (value == document) document = NULL;
}
