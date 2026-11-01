// P6 client: CRobloxApp::InitInstance 0044d810 order, original resources, and a
// place document template from resource 129. Rendering and play go through the
// recovered player's engine via P6Engine.cpp. Not byte-verified.
#include <afxwin.h>
#include <afxole.h>
#include <afxcmn.h>
#include <afxext.h>
#include <XTToolkitPro.h>
#include <stdio.h>
#include "P6Engine.h"

static const UINT IDR_MAINFRAME_ROBLOX = 128; // RT_MENU/RT_ACCELERATOR/RT_GROUP_ICON 128
static const UINT IDR_PLACE = 129;            // RT_MENU and doc string "Places (*.rbxl)"
static const UINT ID_P6_AUTOCLOSE = 1;

class CRobloxCommandLineInfo : public CCommandLineInfo {
public:
    bool autoClose;
    bool visible;
    bool play;
    CString* expecting;
    CString capture, script, saveAs;
    CRobloxCommandLineInfo() : autoClose(false), visible(false), play(false), expecting(NULL) {}
    virtual void ParseParam(const char* param, BOOL flag, BOOL last) {
        if (expecting) { *expecting = param; expecting = NULL; return; }
        if (flag && !lstrcmpiA(param, "p6-autoclose")) { autoClose = true; return; }
        if (flag && !lstrcmpiA(param, "p6-visible")) { autoClose = visible = true; return; }
        if (flag && !lstrcmpiA(param, "p6-play")) { play = true; return; }
        if (flag && !lstrcmpiA(param, "p6-capture")) { expecting = &capture; return; }
        if (flag && !lstrcmpiA(param, "p6-script")) { expecting = &script; return; }
        if (flag && !lstrcmpiA(param, "p6-saveas")) { expecting = &saveAs; return; }
        CCommandLineInfo::ParseParam(param, flag, last);
    }
};

static CString g_capture, g_script, g_saveAs;
static bool g_play;
static bool g_openFailed;

// 00431d00: status bar 0000e801, then command bars with the frame menu.
class CMainFrame : public CXTPMDIFrameWnd {
    DECLARE_DYNAMIC(CMainFrame)
    CXTPStatusBar statusBar;
public:
    afx_msg int OnCreate(LPCREATESTRUCT create) {
        if (CXTPMDIFrameWnd::OnCreate(create) == -1) return -1;
        static const UINT indicators[] = {ID_SEPARATOR};
        if (!statusBar.Create(this) || !statusBar.SetIndicators(indicators, 1)) return -1;
        if (!InitCommandBars()) return -1;
        CXTPCommandBars* bars = GetCommandBars();
        XTPPaintManager()->SetTheme(xtpThemeOffice2003);
        CXTPCommandBar* menu = bars->SetMenu(_T("Menu Bar"), IDR_MAINFRAME_ROBLOX);
        if (!menu) return -1;
        menu->SetFlags(xtpFlagIgnoreSetMenuMessage); // keep menu 128; template 129 has File only
        return 0;
    }
    afx_msg void OnTimer(UINT_PTR id) {
        if (id != ID_P6_AUTOCLOSE) { CXTPMDIFrameWnd::OnTimer(id); return; }
        KillTimer(id);
        printf("p6: autoclose frames=%d\n", P6EngineFrames());
        P6EngineReport();
        if (!g_saveAs.IsEmpty()) {
            CFrameWnd* child = GetActiveFrame();
            CDocument* document = child ? child->GetActiveDocument() : NULL;
            printf("p6: save %s\n", document && document->OnSaveDocument(g_saveAs) ? "ok" : "failed");
        }
        if (!g_capture.IsEmpty()) printf("p6: capture %s\n", P6EngineCapture(g_capture) ? "ok" : "failed");
        PostMessage(WM_CLOSE);
    }
    DECLARE_MESSAGE_MAP()
};
IMPLEMENT_DYNAMIC(CMainFrame, CXTPMDIFrameWnd)
BEGIN_MESSAGE_MAP(CMainFrame, CXTPMDIFrameWnd)
    ON_WM_CREATE()
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
    virtual BOOL OnSaveDocument(LPCTSTR path) {
        int status = P6EngineSave(path);
        if (status) printf("p6: save status %d\n", status);
        else SetModifiedFlag(FALSE);
        return !status;
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
        int status = P6EngineOpen(m_hWnd, GetDocument()->GetPathName(), rect.Width(), rect.Height(), g_play);
        printf("p6: engine open %d\n", status);
        if (!status && !g_script.IsEmpty()) printf("p6: script %d\n", P6EngineScript(g_script));
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
        g_script = command.script;
        g_saveAs = command.saveAs;
        g_play = command.play;
        AddDocTemplate(new CMultiDocTemplate(IDR_PLACE, RUNTIME_CLASS(CRobloxDoc), RUNTIME_CLASS(CMDIChildWnd), RUNTIME_CLASS(CRobloxView)));
        CMainFrame* frame = new CMainFrame;
        if (!frame->LoadFrame(IDR_MAINFRAME_ROBLOX)) { delete frame; return FALSE; }
        m_pMainWnd = frame;
        CXTPCommandBar* menu = frame->GetCommandBars()->GetMenuBar();
        printf("p6: frame=%p menus=%d\n", frame->m_hWnd, menu ? menu->GetControlCount() : -1);
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
