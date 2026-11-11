#pragma once
// >>> native-status (generated) -- do not edit >>>
// IDEDocManager2008 | 2008-06 | selection unverified
// unmapped (no binary link) | by -
// <<< native-status | src 4e9ca587 | roc native-status --write
// Inactive native 2008-06 recovery: CIDEDocManager, the IDE document manager CRobloxApp::InitInstance installs
// (`m_pDocManager = new CIDEDocManager(command.noStartPage)`). CRobloxApp.cpp keeps its own local declaration for
// that call; this header is the recovered layout, and nothing in the CRobloxApp unit includes it.
#include <afxwin.h>
#include "AppLeaves2008/RbxDocTemplates2008.h"

// RTTI of vtable 0081685c: CIDEDocManager : CDocManager : CObject (no CRuntimeClass of its own: slot 0 is the mfc90
// CDocManager::GetRuntimeClass import). sizeof 0x30: InitInstance news 0x30 before the constructor 00449910.
// Constructor 00449910: CDocManager() (mfc90), vptr 0081685c, then four templates, each built inline and handed to
// CDocManager::AddDocTemplate (mfc90) right after its member store:
//   +0x24 new(0x98) CRbxPlayDocTemplate(0x81, CRobloxDoc, CRbxChildFrame, noStartPage ? CRobloxReportDocView :
//         CRobloxView) (the view class is read first: the argument is tested before the RUNTIME_CLASS calls);
//   +0x20 new(0x90) CRbxDocTemplate(0xb9, CBrowserDoc, CChildFrame, CIDEBrowserView);
//   +0x28 new(0x90) CRbxDocTemplate(0xcf, CScriptDoc, CMDIChildWnd, CScriptEditor);
//   +0x2c new(0x90) CRbxDocTemplate(0x8a, CNullDoc, CMDIChildWnd, CObjectBrowser).
// The runtime classes are the GetThisClass getters the constructor calls (CRuntimeClass names read from 00818364,
// 00819070, 0080e484, 008172c0, 0080cf74, 0080e468, 0080cfac, 0081b208, 0081b1ec, 00812520, 00812410).
// ??_G 0044a150 calls ~CDocManager (mfc90) directly: no destructor of its own.
// Vtable slots overridden: 13 DoPromptFileName 00449ae0, 15 OnFileNew 0044abd0; everything else is CDocManager's.
class CIDEDocManager : public CDocManager
{
public:
    explicit CIDEDocManager(bool noStartPage);   // 00449910

    // 00449ae0: a NULL template means the play template (+0x24), then CDocManager::DoPromptFileName (tail jump).
    virtual BOOL DoPromptFileName(CString& fileName, UINT nIDSTitle, DWORD lFlags, BOOL bOpenFileDialog,
                                  CDocTemplate* pTemplate);
    // 0044abd0 (catch funclet 0044ac40): clears pendingPlayError, opens a new play document through the play
    // template's OpenDocumentFile(NULL, TRUE) (vtable +0x88), then rethrows a recorded open error into a catch that
    // reports it (00428850), shows AFX_IDP_FAILED_TO_CREATE_DOC and closes the half-open document (vtable +0x84).
    virtual void OnFileNew();

    CRbxDocTemplate* browserTemplate;      // +0x20 (0xb9: CBrowserDoc / CChildFrame / CIDEBrowserView)
    CRbxPlayDocTemplate* playTemplate;     // +0x24 (0x81; 0044abd0 / 00449ae0 read it; 0044bbf0 reaches
                                           // getPlayDocument 0044b9a0 through it)
    CRbxDocTemplate* scriptTemplate;       // +0x28 (0xcf: CScriptDoc / CMDIChildWnd / CScriptEditor)
    CRbxDocTemplate* objectBrowserTemplate; // +0x2c (0x8a: CNullDoc / CMDIChildWnd / CObjectBrowser)
};
