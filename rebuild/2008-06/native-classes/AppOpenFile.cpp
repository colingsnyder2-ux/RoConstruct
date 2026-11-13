// >>> native-status (generated) -- do not edit >>>
// AppOpenFile | 2008-06 | draft (no current byte proof)
// 0/1 mapped addresses byte-exact | 1 unproved | no mapped strings | by colin (deepseek:deepseek-chat)
// <<< native-status | src 96be2322 | roc native-status --write
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
