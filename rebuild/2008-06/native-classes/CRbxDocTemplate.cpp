// >>> native-status (generated) -- do not edit >>>
// CRbxDocTemplate | 2008-06 | draft (no current byte proof)
// 0/1 mapped addresses byte-exact | 1 unproved | no mapped strings | by king_originala (ntech:glm-4.5-air)
// <<< native-status | src 889f1d72 | roc native-status --write
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
