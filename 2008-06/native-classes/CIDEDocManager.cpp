// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/../../../tools/libs/scintilla-mfc-1.20
// >>> native-status (generated) -- do not edit >>>
// CIDEDocManager | 2008-06 | inactive
// unmapped (no binary link) | unmapped (no binary link) | by -
// <<< native-status | src ce99bb96 | roc native-status --write
#include <afxwin.h>
#include <Platform.h>
#include <XTToolkitPro.h>
#include "CIDEDocManager.h"
#include "CRbxDocTemplate.h"
#include "CRobloxDoc.h"
#include "CRobloxView.h"
#include "CRobloxReportSubViews.h"
#include "CBrowserDoc.h"
#include "CBrowserView.h"
#include "CChildFrame.h"
#include "CScriptEditor.h"
#include "CObjectBrowser.h"

CIDEDocManager::CIDEDocManager(bool play)
{
    templates[1] = new CRbxPlayDocTemplate(0x81, RUNTIME_CLASS(CRobloxDoc), RUNTIME_CLASS(CRbxChildFrame),
        play ? RUNTIME_CLASS(CRobloxReportDocView) : RUNTIME_CLASS(CRobloxView));
    AddDocTemplate(templates[1]);
    templates[0] = new CRbxDocTemplate(0xb9, RUNTIME_CLASS(CBrowserDoc), RUNTIME_CLASS(CChildFrame), RUNTIME_CLASS(CIDEBrowserView));
    AddDocTemplate(templates[0]);
    templates[2] = new CRbxDocTemplate(0xcf, RUNTIME_CLASS(CScriptDoc), RUNTIME_CLASS(CMDIChildWnd), RUNTIME_CLASS(CScriptEditor));
    AddDocTemplate(templates[2]);
    templates[3] = new CRbxDocTemplate(0x8a, RUNTIME_CLASS(CNullDoc), RUNTIME_CLASS(CMDIChildWnd), RUNTIME_CLASS(CObjectBrowser));
    AddDocTemplate(templates[3]);
}
