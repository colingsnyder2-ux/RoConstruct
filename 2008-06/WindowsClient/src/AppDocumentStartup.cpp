// >>> native-status (generated) -- do not edit >>>
// AppDocumentStartup | 2008-06 | selection unverified
// unmapped (no indexed address) | by -
// <<< native-status | src a3b980f3 | roc native-status --write
#include "CRobloxApp.h"
#include "CIDEDocManager.h"

void CRobloxApp::initializeEmptyDocument()
{
    static_cast<CIDEDocManager*>(m_pDocManager)->templates[0]->OpenDocumentFile(NULL, TRUE);
}
