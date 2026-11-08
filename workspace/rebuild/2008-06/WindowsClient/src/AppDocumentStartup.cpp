#include "CRobloxApp.h"
#include "CIDEDocManager.h"

void CRobloxApp::initializeEmptyDocument()
{
    static_cast<CIDEDocManager*>(m_pDocManager)->templates[0]->OpenDocumentFile(NULL, TRUE);
}
