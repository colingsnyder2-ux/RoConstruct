// >>> native-status (generated) -- do not edit >>>
// CRbxDocTemplate | 2008-06 | inactive
// unmapped (no indexed address) | unmapped (no binary link) | by -
// <<< native-status | src 760c928f | roc native-status --write
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
