// Inactive native 2008-06 CIDEDocManager constructor 00449910 (native-headers/AppLeaves2008/IDEDocManager2008.h):
// a separate unit because it needs the RUNTIME_CLASS getters of the IDE document, frame and view classes.
// Include order: Scintilla's Platform.h (class Font) before afxhtml.h pulls in comdef.h, whose Font smart pointer
// is __if_not_exists-guarded; CBrowserView.h (XTP, needs min/max and the MFC CCriticalSection) before the RBX
// headers.
#include <afxwin.h>
#include <Platform.h>
#include "CBrowserView.h"
#include "CScriptEditor.h"
#include "AppLeaves2008/IDEDocManager2008.h"
#include "CRobloxDoc.h"
#include "CChildFrame.h"
#include "CRobloxView.h"
#include "CRobloxReportSubViews.h"
#include "CBrowserDoc.h"
#include "CObjectBrowser.h"

CIDEDocManager::CIDEDocManager(bool noStartPage)
{
    playTemplate = new CRbxPlayDocTemplate(0x81, RUNTIME_CLASS(CRobloxDoc), RUNTIME_CLASS(CRbxChildFrame),
                                           noStartPage ? RUNTIME_CLASS(CRobloxReportDocView) : RUNTIME_CLASS(CRobloxView));
    AddDocTemplate(playTemplate);
    browserTemplate = new CRbxDocTemplate(0xb9, RUNTIME_CLASS(CBrowserDoc), RUNTIME_CLASS(CChildFrame),
                                          RUNTIME_CLASS(CIDEBrowserView));
    AddDocTemplate(browserTemplate);
    scriptTemplate = new CRbxDocTemplate(0xcf, RUNTIME_CLASS(CScriptDoc), RUNTIME_CLASS(CMDIChildWnd),
                                         RUNTIME_CLASS(CScriptEditor));
    AddDocTemplate(scriptTemplate);
    objectBrowserTemplate = new CRbxDocTemplate(0x8a, RUNTIME_CLASS(CNullDoc), RUNTIME_CLASS(CMDIChildWnd),
                                                RUNTIME_CLASS(CObjectBrowser));
    AddDocTemplate(objectBrowserTemplate);
}
