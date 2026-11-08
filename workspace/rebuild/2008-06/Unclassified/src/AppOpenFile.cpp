#include "CRobloxApp.h"
#include "CIDEDocManager.h"
#include "CRobloxDoc.h"

BOOL CRobloxApp::openFile(std::string file)
{
    CIDEDocManager* manager = static_cast<CIDEDocManager*>(m_pDocManager);
    CDocTemplate* documents = manager->templates[1];
    for (POSITION position = documents->GetFirstDocPosition(); position;) {
        CRobloxDoc* document = static_cast<CRobloxDoc*>(documents->GetNextDoc(position));
        if (!document->loadFromString(file)) return FALSE;
    }
    return TRUE;
}
