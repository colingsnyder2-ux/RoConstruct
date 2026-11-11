#include "CRobloxApp.h"
#include "CIDEDocManager.h"
#include "CRobloxDoc.h"
BOOL CRobloxApp::openFile(std::string file)
{
    CDocTemplate& documents = *static_cast<CIDEDocManager*>(m_pDocManager)->templates[1];
    POSITION position = documents.GetFirstDocPosition();
    while (position) {
        CRobloxDoc* document = static_cast<CRobloxDoc*>(documents.GetNextDoc(position));
        if (!document->loadFromString(file)) return FALSE;
    }
    return TRUE;
}
