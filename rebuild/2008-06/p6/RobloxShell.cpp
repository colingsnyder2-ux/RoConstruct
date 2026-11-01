// P6 shell: CRobloxApp::InitInstance 0044d810 order with the engine calls still
// absent. Original resources come from gen_res.py. Not byte-verified.
#include <afxwin.h>
#include <afxole.h>
#include <afxcmn.h>
#include <afxext.h>
#include <stdio.h>

static const UINT IDR_MAINFRAME_ROBLOX = 128; // RT_MENU/RT_ACCELERATOR/RT_GROUP_ICON 128
static const UINT ID_P6_AUTOCLOSE = 1;

class CRobloxCommandLineInfo : public CCommandLineInfo {
public:
    bool autoClose;
    CRobloxCommandLineInfo() : autoClose(false) {}
    virtual void ParseParam(const char* param, BOOL flag, BOOL last) {
        if (flag && !lstrcmpiA(param, "p6-autoclose")) { autoClose = true; return; }
        CCommandLineInfo::ParseParam(param, flag, last);
    }
};

class CMainFrame : public CMDIFrameWnd {
public:
    afx_msg void OnTimer(UINT_PTR id) {
        if (id == ID_P6_AUTOCLOSE) { printf("p6: autoclose\n"); KillTimer(id); PostMessage(WM_CLOSE); return; }
        CMDIFrameWnd::OnTimer(id);
    }
    afx_msg void OnDestroy() { printf("p6: OnDestroy\n"); CMDIFrameWnd::OnDestroy(); }
    virtual void PostNcDestroy() { printf("p6: PostNcDestroy\n"); CMDIFrameWnd::PostNcDestroy(); }
    DECLARE_MESSAGE_MAP()
};
BEGIN_MESSAGE_MAP(CMainFrame, CMDIFrameWnd)
    ON_WM_TIMER()
    ON_WM_DESTROY()
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
        CMainFrame* frame = new CMainFrame;
        if (!frame->LoadFrame(IDR_MAINFRAME_ROBLOX)) { delete frame; return FALSE; }
        m_pMainWnd = frame;
        CMenu* menu = frame->GetMenu();
        printf("p6: frame=%p menus=%d\n", frame->m_hWnd, menu ? menu->GetMenuItemCount() : -1);
        frame->ShowWindow(command.autoClose ? SW_HIDE : m_nCmdShow);
        printf("p6: shown\n");
        frame->UpdateWindow();
        printf("p6: updated\n");
        if (command.autoClose) frame->SetTimer(ID_P6_AUTOCLOSE, 1500, NULL);
        printf("p6: init done\n");
        return TRUE;
    }
    virtual int Run() {
        printf("p6: Run\n");
        return CWinApp::Run();
    }
    virtual BOOL OnIdle(LONG count) {
        if (!count) printf("p6: idle\n");
        return CWinApp::OnIdle(count);
    }
    virtual int ExitInstance() {
        printf("p6: ExitInstance\n");
        return CWinApp::ExitInstance();
    }
};

// Normally supplied by mfcs90.lib, which this shell does not link yet.
extern "C" { int _afxForceEXCLUDE; int _afxForceSTDAFX; }

CRobloxApp theApp;
