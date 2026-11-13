// >>> native-status (generated) -- do not edit >>>
// AppDocumentStartup | 2008-06 | draft (no current byte proof)
// 0/1 mapped addresses byte-exact | 1 unproved | no mapped strings | by tester (ntech:glm-4.5-air)
// <<< native-status | src a3b980f3 | roc native-status --write
#include "CRobloxApp.h"
#include "CIDEDocManager.h"

void CRobloxApp::initializeEmptyDocument()
{
    static_cast<CIDEDocManager*>(m_pDocManager)->templates[0]->OpenDocumentFile(NULL, TRUE);
}
