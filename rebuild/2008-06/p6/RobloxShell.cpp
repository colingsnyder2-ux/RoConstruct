// P6 client: CRobloxApp::InitInstance 0044d810 order, original resources, and a
// place document template from resource 129. Rendering and play go through the
// recovered player's engine via P6Engine.cpp. Not byte-verified.
#include <afxwin.h>
#include <afxole.h>
#include <afxcmn.h>
#include <afxext.h>
#include <stdio.h>
#include "P6Engine.h"

static const UINT IDR_MAINFRAME_ROBLOX = 128; // RT_MENU/RT_ACCELERATOR/RT_GROUP_ICON 128
static const UINT IDR_PLACE = 129;            // RT_MENU and doc string "Places (*.rbxl)"
static const UINT ID_P6_AUTOCLOSE = 1;

class CRobloxCommandLineInfo : public CCommandLineInfo {
public:
    bool autoClose;
    bool visible;
    bool expectCapture;
    CString capture;
    CRobloxCommandLineInfo() : autoClose(false), visible(false), expectCapture(false) {}
    virtual void ParseParam(const char* param, BOOL flag, BOOL last) {
        if (expectCapture) { capture = param; expectCapture = false; return; }
        if (flag && !lstrcmpiA(param, "p6-autoclose")) { autoClose = true; return; }
        if (flag && !lstrcmpiA(param, "p6-visible")) { autoClose = visible = true; return; }
        if (flag && !lstrcmpiA(param, "p6-capture")) { expectCapture = true; return; }
        CCommandLineInfo::ParseParam(param, flag, last);
    }
};

static CString g_capture;
static bool g_openFailed;

class CMainFrame : public CMDIFrameWnd {
    DECLARE_DYNAMIC(CMainFrame)
public:
    afx_msg void OnTimer(UINT_PTR id) {
        if (id != ID_P6_AUTOCLOSE) { CMDIFrameWnd::OnTimer(id); return; }
        KillTimer(id);
        printf("p6: autoclose frames=%d\n", P6EngineFrames());
        P6EngineReport();
        if (!g_capture.IsEmpty()) printf("p6: capture %s\n", P6EngineCapture(g_capture) ? "ok" : "failed");
        PostMessage(WM_CLOSE);
    }
    DECLARE_MESSAGE_MAP()
};
IMPLEMENT_DYNAMIC(CMainFrame, CMDIFrameWnd)
BEGIN_MESSAGE_MAP(CMainFrame, CMDIFrameWnd)
    ON_WM_TIMER()
END_MESSAGE_MAP()

class CRobloxDoc : public CDocument {
    DECLARE_DYNCREATE(CRobloxDoc)
public:
    virtual BOOL OnOpenDocument(LPCTSTR path) {
        if (P6EngineReadable(path)) return TRUE;
        printf("p6: could not read place: %s\n", path);
        g_openFailed = true;
        return FALSE;
    }
    virtual void OnCloseDocument() {
        P6EngineClose();
        CDocument::OnCloseDocument();
    }
};
IMPLEMENT_DYNCREATE(CRobloxDoc, CDocument)

class CRobloxView : public CView {
    DECLARE_DYNCREATE(CRobloxView)
public:
    virtual void OnDraw(CDC*) {}
    virtual void OnInitialUpdate() {
        CView::OnInitialUpdate();
        CRect rect;
        GetClientRect(rect);
        int status = P6EngineOpen(m_hWnd, GetDocument()->GetPathName(), rect.Width(), rect.Height());
        printf("p6: engine open %d\n", status);
    }
    afx_msg void OnSize(UINT type, int width, int height) {
        CView::OnSize(type, width, height);
        P6EngineResize();
    }
    DECLARE_MESSAGE_MAP()
};
IMPLEMENT_DYNCREATE(CRobloxView, CView)
BEGIN_MESSAGE_MAP(CRobloxView, CView)
    ON_WM_SIZE()
END_MESSAGE_MAP()

class CRobloxApp : public CWinApp {
public:
    virtual BOOL InitInstance() {
        setvbuf(stdout, NULL, _IONBF, 0);
        InitCommonControls();
        if (!CWinApp::InitInstance()) return FALSE;
        if (!AfxOleInit()) return FALSE;
        CRobloxCommandLineInfo command;
        ParseCommandLine(command);
        g_capture = command.capture;
        AddDocTemplate(new CMultiDocTemplate(IDR_PLACE, RUNTIME_CLASS(CRobloxDoc), RUNTIME_CLASS(CMDIChildWnd), RUNTIME_CLASS(CRobloxView)));
        CMainFrame* frame = new CMainFrame;
        if (!frame->LoadFrame(IDR_MAINFRAME_ROBLOX)) { delete frame; return FALSE; }
        m_pMainWnd = frame;
        CMenu* menu = frame->GetMenu();
        printf("p6: frame=%p menus=%d\n", frame->m_hWnd, menu ? menu->GetMenuItemCount() : -1);
        frame->ShowWindow(command.autoClose && !command.visible ? SW_HIDE : m_nCmdShow);
        frame->UpdateWindow();
        if (command.m_nShellCommand == CCommandLineInfo::FileOpen && !ProcessShellCommand(command)) return FALSE;
        if (command.autoClose) frame->SetTimer(ID_P6_AUTOCLOSE, 5000, NULL);
        return TRUE;
    }
    virtual BOOL OnIdle(LONG count) {
        BOOL more = CWinApp::OnIdle(count);
        return P6EngineFrame() || more;
    }
    virtual int ExitInstance() {
        printf("p6: ExitInstance\n");
        int code = CWinApp::ExitInstance();
        return g_openFailed ? 1 : code;
    }
    DECLARE_MESSAGE_MAP()
};
BEGIN_MESSAGE_MAP(CRobloxApp, CWinApp)
    ON_COMMAND(ID_FILE_OPEN, &CWinApp::OnFileOpen)
END_MESSAGE_MAP()

// Normally supplied by mfcs90.lib, which this client does not link yet.
extern "C" { int _afxForceEXCLUDE; int _afxForceSTDAFX; }

CRobloxApp theApp;
