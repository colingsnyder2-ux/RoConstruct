// >>> native-status (generated) -- do not edit >>>
// CBrowserDocManager | 2008-06 | draft (no current byte proof)
// 0/1 mapped addresses byte-exact | 1 unproved | no mapped strings | by king_originala (deepseek:deepseek-flash)
// <<< native-status | src 31f59808 | roc native-status --write
#include "CBrowserDocManager.h"
#include "CBrowserDoc.h"
#include "CBrowserFrameWnd.h"
#include "CBrowserView.h"

CBrowserDocManager::CBrowserDocManager()
{
    browserTemplate = new CSingleDocTemplate(0xb9,
        RUNTIME_CLASS(CBrowserDoc), RUNTIME_CLASS(CBrowserFrameWnd),
        RUNTIME_CLASS(CPlayBrowserView));
    AddDocTemplate(browserTemplate);
}
