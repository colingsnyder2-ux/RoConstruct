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
static const UINT ID_P6_COMMAND = 2;
static const UINT IDD_P6_ABOUT = 117;              // 00401220 passes 0x75 to the dialog base
static const UINT ID_VIEW_PROPERTIES = 32783;      // CMainFrame map, handler 0042e610
static const UINT ID_RUN = 32966;                  // toolbar 137: Run, Pause, Reset
static const UINT ID_PAUSE = 32967;
static const UINT ID_RESET = 32968;
static const UINT ID_VIEW_EXPLORER = 32792;        // CMainFrame map, handler 0042e5e0
static const UINT ID_TOOLS_EXECUTE_SCRIPT = 33009; // CRobloxApp map, handler 0044a300
static const UINT ID_TOOLS_PLAY_SOLO = 33028;      // Tools > Test > Play Solo

class CRobloxCommandLineInfo : public CCommandLineInfo {
public:
    bool autoClose;
    bool visible;
    bool play;
    CString* expecting;
    CString capture, script, saveAs, post, runFile, select, setProperty;
    CRobloxCommandLineInfo() : autoClose(false), visible(false), play(false), expecting(NULL) {}
    virtual void ParseParam(const char* param, BOOL flag, BOOL last) {
        if (expecting) { *expecting = param; expecting = NULL; return; }
        if (flag && !lstrcmpiA(param, "p6-autoclose")) { autoClose = true; return; }
        if (flag && !lstrcmpiA(param, "p6-visible")) { autoClose = visible = true; return; }
        if (flag && !lstrcmpiA(param, "p6-play")) { play = true; return; }
        if (flag && !lstrcmpiA(param, "p6-capture")) { expecting = &capture; return; }
        if (flag && !lstrcmpiA(param, "p6-script")) { expecting = &script; return; }
        if (flag && !lstrcmpiA(param, "p6-saveas")) { expecting = &saveAs; return; }
        if (flag && !lstrcmpiA(param, "p6-command")) { expecting = &post; return; }
        if (flag && !lstrcmpiA(param, "p6-runfile")) { expecting = &runFile; return; }
        if (flag && !lstrcmpiA(param, "p6-select")) { expecting = &select; return; }
        if (flag && !lstrcmpiA(param, "p6-setprop")) { expecting = &setProperty; return; }
        CCommandLineInfo::ParseParam(param, flag, last);
    }
};

static CString g_capture, g_script, g_saveAs, g_runFile;
static CString g_select, g_setProperty;
static CDialog* g_about;
static bool g_play;
static UINT g_post;
static bool g_openFailed;

// 00431d00: status bar 0000e801, then command bars with the frame menu.
class CMainFrame : public CXTPMDIFrameWnd {
    DECLARE_DYNAMIC(CMainFrame)
    CXTPStatusBar statusBar;
    CXTPDockingPaneManager panes;
    CTreeCtrl explorer;
    CXTPPropertyGrid properties;
    void* selected;
    static void addProperty(const char* category, const char* name, const char* value, int readOnly, void* context) {
        CXTPPropertyGrid* grid = static_cast<CXTPPropertyGrid*>(context);
        CXTPPropertyGridItem* group = grid->FindItem(category);
        if (!group) group = grid->AddCategory(category);
        CXTPPropertyGridItem* item = group->AddChildItem(new CXTPPropertyGridItem(name, value));
        item->SetReadOnly(readOnly);
        group->Expand();
    }
    HTREEITEM findNode(HTREEITEM item, const CString& name) {
        for (; item; item = explorer.GetNextSiblingItem(item)) {
            if (explorer.GetItemText(item) == name) return item;
            HTREEITEM child = findNode(explorer.GetChildItem(item), name);
            if (child) return child;
        }
        return NULL;
    }
    static void addNode(int depth, const char* className, const char* name, void* handle, void* context) {
        CMainFrame* frame = static_cast<CMainFrame*>(context);
        if (!depth || depth >= 64) return; // original Explorer has no DataModel root
        if (depth == 1) {
            frame->shown = false;
            static const char* const services[] = {"Workspace", "Players", "Lighting", "StarterPack", "Teams", "SoundService"};
            for (int i = 0; i < 6; ++i)
                if (!lstrcmpA(className, services[i])) frame->shown = true;
        }
        if (!frame->shown) return;
        frame->path[depth] = frame->explorer.InsertItem(name, depth > 1 ? frame->path[depth - 1] : TVI_ROOT);
        frame->explorer.SetItemData(frame->path[depth], (DWORD_PTR)handle);
    }
    HTREEITEM path[64];
    bool shown;
public:
    void ShowProperties(void* item) {
        selected = item;
        properties.ResetContent();
        int count = P6DataProperties(item, addProperty, &properties);
        printf("p6: properties %d\n", -count);
    }
    void SetProperty(const CString& name, const CString& value) {
        int status = P6DataSetProperty(selected, name, value);
        printf("p6: set %s %d\n", (LPCSTR)name, status);
        CMDIChildWnd* child = MDIGetActive();
        if (!status && child && child->GetActiveDocument()) child->GetActiveDocument()->SetModifiedFlag();
    }
    afx_msg void OnExplorerSelect(NMHDR* header, LRESULT* result) {
        HTREEITEM item = explorer.GetSelectedItem();
        if (item) ShowProperties((void*)explorer.GetItemData(item));
        *result = 0;
    }
    afx_msg LRESULT OnGridNotify(WPARAM code, LPARAM data) {
        if (code == XTP_PGN_ITEMVALUE_CHANGED) {
            CXTPPropertyGridItem* item = reinterpret_cast<CXTPPropertyGridItem*>(data);
            SetProperty(item->GetCaption(), item->GetValue());
        }
        return 0;
    }
    afx_msg void OnViewProperties() {
        if (panes.IsPaneClosed(ID_VIEW_PROPERTIES)) panes.ShowPane(ID_VIEW_PROPERTIES);
        else panes.ClosePane(ID_VIEW_PROPERTIES);
    }
    afx_msg void OnUpdateViewProperties(CCmdUI* ui) { ui->SetCheck(!panes.IsPaneClosed(ID_VIEW_PROPERTIES)); }
    void ApplyTestSelection() {
        if (g_select.IsEmpty()) return;
        HTREEITEM item = findNode(explorer.GetRootItem(), g_select);
        printf("p6: select %s %s\n", (LPCSTR)g_select, item ? "found" : "missing");
        if (item) explorer.SelectItem(item);
        int split = g_setProperty.Find('=');
        if (item && split > 0) SetProperty(g_setProperty.Left(split), g_setProperty.Mid(split + 1));
        g_select.Empty();
    }
    void RefreshExplorer() {
        explorer.DeleteAllItems();
        P6DataWalk(addNode, this);
        printf("p6: explorer nodes=%u\n", explorer.GetCount());
        ApplyTestSelection();
    }
    afx_msg void OnViewExplorer() {
        if (panes.IsPaneClosed(ID_VIEW_EXPLORER)) panes.ShowPane(ID_VIEW_EXPLORER);
        else panes.ClosePane(ID_VIEW_EXPLORER);
    }
    afx_msg void OnUpdateViewExplorer(CCmdUI* ui) { ui->SetCheck(!panes.IsPaneClosed(ID_VIEW_EXPLORER)); }
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
        static const struct { UINT id; LPCTSTR title; } toolbars[] = {{128, _T("Standard")}, {137, _T("Run")}, {135, _T("Camera")}};
        for (int i = 0; i < 3; ++i) {
            CXTPToolBar* bar = bars->Add(toolbars[i].title, xtpBarTop);
            if (!bar || !bar->LoadToolBar(toolbars[i].id)) return -1;
        }
        if (!explorer.Create(WS_CHILD | WS_VISIBLE | TVS_HASLINES | TVS_HASBUTTONS | TVS_LINESATROOT, CRect(0, 0, 0, 0), this, 1)) return -1;
        panes.InstallDockingPanes(this);
        panes.SetTheme(xtpPaneThemeOffice2003);
        CXTPDockingPane* pane = panes.CreatePane(ID_VIEW_EXPLORER, CRect(0, 0, 240, 400), xtpPaneDockRight);
        pane->SetTitle(_T("Explorer"));
        pane->Attach(&explorer);
        selected = NULL;
        if (!properties.Create(CRect(0, 0, 0, 0), this, 2)) return -1;
        properties.SetOwner(this);
        CXTPDockingPane* grid = panes.CreatePane(ID_VIEW_PROPERTIES, CRect(0, 0, 240, 300), xtpPaneDockBottom, pane);
        grid->SetTitle(_T("Properties"));
        grid->Attach(&properties);
        return 0;
    }
    afx_msg void OnTimer(UINT_PTR id) {
        if (id == ID_P6_COMMAND) {
            KillTimer(id);
            printf("p6: command %u\n", g_post);
            PostMessage(WM_COMMAND, g_post);
            return;
        }
        if (id != ID_P6_AUTOCLOSE) { CXTPMDIFrameWnd::OnTimer(id); return; }
        KillTimer(id);
        if (g_about) {
            g_about->EndDialog(IDCANCEL);
            SetTimer(ID_P6_AUTOCLOSE, 200, NULL);
            return;
        }
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
    ON_COMMAND(ID_VIEW_EXPLORER, &CMainFrame::OnViewExplorer)
    ON_COMMAND(ID_VIEW_PROPERTIES, &CMainFrame::OnViewProperties)
    ON_UPDATE_COMMAND_UI(ID_VIEW_PROPERTIES, &CMainFrame::OnUpdateViewProperties)
    ON_NOTIFY(TVN_SELCHANGED, 1, &CMainFrame::OnExplorerSelect)
    ON_MESSAGE(XTPWM_PROPERTYGRID_NOTIFY, &CMainFrame::OnGridNotify)
    ON_UPDATE_COMMAND_UI(ID_VIEW_EXPLORER, &CMainFrame::OnUpdateViewExplorer)
    ON_WM_TIMER()
END_MESSAGE_MAP()

static void RunScriptFile(const CString& path);

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
    afx_msg void OnPlaySolo() {
        int status = P6EnginePlay();
        printf("p6: play solo %d\n", status);
        static_cast<CMainFrame*>(AfxGetMainWnd())->RefreshExplorer();
    }
    afx_msg void OnUpdatePlaySolo(CCmdUI* ui) { ui->Enable(P6EngineIsOpen()); }
    afx_msg void OnRun() { P6EngineSetRunning(1); printf("p6: run\n"); }
    afx_msg void OnPause() { P6EngineSetRunning(0); printf("p6: pause\n"); }
    afx_msg void OnReset() {
        CString path = GetDocument()->GetPathName();
        printf("p6: reset\n");
        AfxGetApp()->CloseAllDocuments(FALSE);
        AfxGetApp()->OpenDocumentFile(path);
    }
    afx_msg void OnUpdateRun(CCmdUI* ui) { ui->Enable(P6EngineIsOpen() && !P6EngineRunning()); }
    afx_msg void OnUpdatePause(CCmdUI* ui) { ui->Enable(P6EngineRunning()); }
    virtual void OnInitialUpdate() {
        CView::OnInitialUpdate();
        CRect rect;
        GetClientRect(rect);
        int status = P6EngineOpen(m_hWnd, GetDocument()->GetPathName(), rect.Width(), rect.Height(), g_play);
        printf("p6: engine open %d\n", status);
        if (!status && !g_script.IsEmpty()) printf("p6: script %d\n", P6EngineScript(g_script));
        if (!status && !g_runFile.IsEmpty()) {
            RunScriptFile(g_runFile);
            g_runFile.Empty();
        }
        static_cast<CMainFrame*>(AfxGetMainWnd())->RefreshExplorer();
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
    ON_COMMAND(ID_TOOLS_PLAY_SOLO, &CRobloxView::OnPlaySolo)
    ON_COMMAND(ID_RUN, &CRobloxView::OnRun)
    ON_COMMAND(ID_PAUSE, &CRobloxView::OnPause)
    ON_COMMAND(ID_RESET, &CRobloxView::OnReset)
    ON_UPDATE_COMMAND_UI(ID_RUN, &CRobloxView::OnUpdateRun)
    ON_UPDATE_COMMAND_UI(ID_PAUSE, &CRobloxView::OnUpdatePause)
    ON_UPDATE_COMMAND_UI(ID_TOOLS_PLAY_SOLO, &CRobloxView::OnUpdatePlaySolo)
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
        g_runFile = command.runFile;
        g_select = command.select;
        g_setProperty = command.setProperty;
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
        g_post = (UINT)atoi(command.post);
        if (g_post) frame->SetTimer(ID_P6_COMMAND, 1000, NULL);
        return TRUE;
    }
    virtual BOOL OnIdle(LONG count) {
        BOOL more = CWinApp::OnIdle(count);
        return P6EngineFrame() || more;
    }
    afx_msg void OnAbout() {
        CDialog about(IDD_P6_ABOUT);
        g_about = &about;
        INT_PTR result = about.DoModal();
        g_about = NULL;
        printf("p6: about %d\n", (int)result);
    }
    afx_msg void OnFileNewPlace() {
        CloseAllDocuments(FALSE); // ponytail: engine holds one DataModel; original allows several documents
        OnFileNew();
    }
    afx_msg void OnFileOpenPlace() {
        CString path;
        if (DoPromptFileName(path, AFX_IDS_OPENFILE, OFN_HIDEREADONLY | OFN_FILEMUSTEXIST, TRUE, NULL)) ReplaceDocument(path);
    }
    void ReplaceDocument(const CString& path) {
        CloseAllDocuments(FALSE);
        OpenDocumentFile(path);
    }
    static void RunFile(const CString& path) {
        CStdioFile file;
        if (!file.Open(path, CFile::modeRead)) { printf("p6: execute script unreadable\n"); return; }
        CString text, line;
        while (file.ReadString(line)) text += line + "\n";
        printf("p6: execute script %d\n", P6EngineScript(text));
    }
    afx_msg void OnExecuteScript() {
        CFileDialog dialog(TRUE, "lua", NULL, OFN_FILEMUSTEXIST | OFN_HIDEREADONLY, "Lua scripts (*.lua)|*.lua|All files (*.*)|*.*||");
        if (dialog.DoModal() != IDOK) return;
        RunFile(dialog.GetPathName());
    }
    virtual int ExitInstance() {
        printf("p6: ExitInstance\n");
        int code = CWinApp::ExitInstance();
        return g_openFailed ? 1 : code;
    }
    DECLARE_MESSAGE_MAP()
};
BEGIN_MESSAGE_MAP(CRobloxApp, CWinApp)
    ON_COMMAND(ID_FILE_NEW, &CRobloxApp::OnFileNewPlace)
    ON_COMMAND(ID_FILE_OPEN, &CRobloxApp::OnFileOpenPlace)
    ON_COMMAND(ID_APP_ABOUT, &CRobloxApp::OnAbout)
    ON_COMMAND(ID_TOOLS_EXECUTE_SCRIPT, &CRobloxApp::OnExecuteScript)
END_MESSAGE_MAP()

// Normally supplied by mfcs90.lib, which this client does not link yet.
extern "C" { int _afxForceEXCLUDE; int _afxForceSTDAFX; }

CRobloxApp theApp;

static void RunScriptFile(const CString& path) { CRobloxApp::RunFile(path); }
