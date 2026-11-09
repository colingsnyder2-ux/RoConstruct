// >>> native-status (generated) -- do not edit >>>
// CBrowserDocManager | 2008-06 | inactive
// unmapped (no binary link) | by -
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
