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
