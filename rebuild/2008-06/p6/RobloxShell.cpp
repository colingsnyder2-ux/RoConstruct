// P6 client: CRobloxApp::InitInstance 0044d810 order, original resources, and a
// place document template from resource 129. Rendering and play go through the
// recovered player's engine via P6Engine.cpp. Not byte-verified.
#include <afxwin.h>
#include <afxole.h>
#include <afxcmn.h>
#include <afxext.h>
#include <afxmt.h>
#include <XTToolkitPro.h>
#include <stdio.h>
#include <vector>
#include "P6Engine.h"
#pragma comment(lib, "version.lib")

static const UINT IDR_MAINFRAME_ROBLOX = 128; // RT_MENU/RT_ACCELERATOR/RT_GROUP_ICON 128
static const UINT IDR_PLACE = 129;            // RT_MENU and doc string "Places (*.rbxl)"
static const UINT ID_P6_AUTOCLOSE = 1;
static const UINT ID_P6_COMMAND = 2;
static const UINT IDD_P6_ABOUT = 117;              // 00401220 passes 0x75 to the dialog base
static const UINT ID_VIEW_PROPERTIES = 32783;      // CMainFrame map, handler 0042e610
static const UINT ID_RUN = 32966;                  // toolbar 137: Run, Pause, Reset
static const UINT ID_PAUSE = 32967;
static const UINT ID_RESET = 32968;
static const UINT ID_VIEW_OUTPUT = 32927;          // CMainFrame map, handler 0042fbb0
static const UINT ID_VIEW_EXPLORER = 32792;        // CMainFrame map, handler 0042e5e0
static const UINT ID_TOOLS_EXECUTE_SCRIPT = 33009; // CRobloxApp map, handler 0044a300
static const UINT ID_TOOLS_PLAY_SOLO = 33028;      // Tools > Test > Play Solo

class CRobloxCommandLineInfo : public CCommandLineInfo {
public:
    bool autoClose;
    bool visible;
    bool play;
    bool pickTest;
    CString* expecting;
    CString capture, script, saveAs, post, runFile, select, setProperty, editScript;
    CRobloxCommandLineInfo() : autoClose(false), visible(false), play(false), pickTest(false), expecting(NULL) {}
    virtual void ParseParam(const char* param, BOOL flag, BOOL last) {
        if (expecting) { *expecting = param; expecting = NULL; return; }
        if (flag && !lstrcmpiA(param, "p6-autoclose")) { autoClose = true; return; }
        if (flag && !lstrcmpiA(param, "p6-visible")) { autoClose = visible = true; return; }
        if (flag && !lstrcmpiA(param, "p6-play")) { play = true; return; }
        if (flag && !lstrcmpiA(param, "p6-pick-test")) { pickTest = true; return; }
        if (flag && !lstrcmpiA(param, "p6-capture")) { expecting = &capture; return; }
        if (flag && !lstrcmpiA(param, "p6-script")) { expecting = &script; return; }
        if (flag && !lstrcmpiA(param, "p6-saveas")) { expecting = &saveAs; return; }
        if (flag && !lstrcmpiA(param, "p6-command")) { expecting = &post; return; }
        if (flag && !lstrcmpiA(param, "p6-runfile")) { expecting = &runFile; return; }
        if (flag && !lstrcmpiA(param, "p6-select")) { expecting = &select; return; }
        if (flag && !lstrcmpiA(param, "p6-editscript")) { expecting = &editScript; return; }
        if (flag && !lstrcmpiA(param, "p6-setprop")) { expecting = &setProperty; return; }
        CCommandLineInfo::ParseParam(param, flag, last);
    }
};

static CString g_capture, g_script, g_saveAs, g_runFile;
static CString g_select, g_setProperty, g_editScript;
static CDialog* g_about;
static CString g_commands;
struct UndoMove { void* item; float position[3]; };
static CCriticalSection g_outputLock;
static CString g_outputPending;
// Script threads may report from anywhere; the UI thread drains this in OnIdle.
static void queueOutput(const char* message) {
    CSingleLock lock(&g_outputLock, TRUE);
    g_outputPending += message;
    g_outputPending += "\r\n";
}
static std::vector<UndoMove> g_undo; // ponytail: moves only, unbounded; original undo covers every edit
static bool g_play;
static UINT g_post;
static bool g_openFailed;
static bool g_pickTest;

// 00431d00: status bar 0000e801, then command bars with the frame menu.
class CMainFrame : public CXTPMDIFrameWnd {
    DECLARE_DYNAMIC(CMainFrame)
    CXTPStatusBar statusBar;
    CXTPDockingPaneManager panes;
    CTreeCtrl explorer;
    CEdit output;
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
    void SelectHandle(void* handle, HTREEITEM item = NULL) {
        if (!item) item = explorer.GetRootItem();
        for (; item; item = explorer.GetNextSiblingItem(item)) {
            if ((void*)explorer.GetItemData(item) == handle) { explorer.SelectItem(item); return; }
            if (explorer.GetChildItem(item)) SelectHandle(handle, explorer.GetChildItem(item));
        }
    }
    CString NameOf(void* handle, HTREEITEM item) {
        for (; item; item = explorer.GetNextSiblingItem(item)) {
            if ((void*)explorer.GetItemData(item) == handle) return explorer.GetItemText(item);
            CString name = NameOf(handle, explorer.GetChildItem(item));
            if (!name.IsEmpty()) return name;
        }
        return CString();
    }
    void TestPicks() {
        for (int i = 1; i < 10; ++i) {
            void* hit = P6EnginePick(i / 10.0f, 0.5f);
            printf("p6: pick %.1f %s\n", i / 10.0f, hit ? (LPCSTR)NameOf(hit, explorer.GetRootItem()) : "-");
        }
        float start[3], end[3];
        void* item = P6EngineDragBegin(0.35f, 0.5f, start);
        printf("p6: drag begin %s\n", item ? "hit" : "miss");
        if (item) {
            printf("p6: drag to %d\n", P6EngineDragTo(0.45f, 0.55f));
            P6DataGetPosition(item, end);
            printf("p6: drag %g %g %g to %g %g %g\n", start[0], start[1], start[2], end[0], end[1], end[2]);
            UndoMove move = {item, {start[0], start[1], start[2]}};
            g_undo.push_back(move);
            SendMessage(WM_COMMAND, ID_EDIT_UNDO);
            P6DataGetPosition(item, end);
            printf("p6: undone to %g %g %g\n", end[0], end[1], end[2]);
        }
    }
    void DrainOutput() {
        CSingleLock lock(&g_outputLock, TRUE);
        if (g_outputPending.IsEmpty()) return;
        output.SetSel(output.GetWindowTextLength(), -1);
        output.ReplaceSel(g_outputPending);
        g_outputPending.Empty();
    }
    afx_msg void OnViewOutput() {
        if (panes.IsPaneClosed(ID_VIEW_OUTPUT)) panes.ShowPane(ID_VIEW_OUTPUT);
        else panes.ClosePane(ID_VIEW_OUTPUT);
    }
    afx_msg void OnUpdateViewOutput(CCmdUI* ui) { ui->SetCheck(!panes.IsPaneClosed(ID_VIEW_OUTPUT)); }
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
    afx_msg void OnExplorerOpen(NMHDR*, LRESULT* result);
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
        if (item && !g_editScript.IsEmpty()) {
            LRESULT result;
            OnExplorerOpen(NULL, &result);
        }
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
        if (!output.Create(WS_CHILD | WS_VISIBLE | WS_VSCROLL | ES_MULTILINE | ES_AUTOVSCROLL | ES_READONLY, CRect(0, 0, 0, 0), this, 3)) return -1;
        CXTPDockingPane* log = panes.CreatePane(ID_VIEW_OUTPUT, CRect(0, 0, 500, 120), xtpPaneDockBottom);
        log->SetTitle(_T("Output"));
        log->Attach(&output);
        P6DataSetOutput(queueOutput);
        return 0;
    }
    afx_msg void OnTimer(UINT_PTR id) {
        if (id == ID_P6_COMMAND) {
            KillTimer(id);
            printf("p6: command %u\n", g_post);
            PostMessage(WM_COMMAND, g_post);
            int comma = g_commands.Find(',');
            g_post = comma < 0 ? 0 : (UINT)atoi(g_commands.Mid(comma + 1));
            g_commands = comma < 0 ? CString() : g_commands.Mid(comma + 1);
            if (g_post) SetTimer(ID_P6_COMMAND, 700, NULL);
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
        DrainOutput();
        CString text;
        output.GetWindowText(text);
        printf("p6: output chars=%d marker=%d\n", text.GetLength(), text.Find("p6-output-marker") >= 0);
        P6EngineReport();
        if (g_pickTest) TestPicks();
        if (!g_saveAs.IsEmpty()) {
            CFrameWnd* child = GetActiveFrame();
            CDocument* document = child ? child->GetActiveDocument() : NULL;
            printf("p6: save %s\n", document && document->OnSaveDocument(g_saveAs) ? "ok" : "failed");
        }
        if (!g_capture.IsEmpty()) printf("p6: capture %s\n", P6EngineCapture(g_capture) ? "ok" : "failed");
        CFrameWnd* activeChild = GetActiveFrame();
        if (activeChild && activeChild->GetActiveDocument()) activeChild->GetActiveDocument()->SetModifiedFlag(FALSE); // tests must not stop at the save prompt
        PostMessage(WM_CLOSE);
    }
    DECLARE_MESSAGE_MAP()
};
IMPLEMENT_DYNAMIC(CMainFrame, CXTPMDIFrameWnd)
BEGIN_MESSAGE_MAP(CMainFrame, CXTPMDIFrameWnd)
    ON_WM_CREATE()
    ON_COMMAND(ID_VIEW_EXPLORER, &CMainFrame::OnViewExplorer)
    ON_COMMAND(ID_VIEW_PROPERTIES, &CMainFrame::OnViewProperties)
    ON_COMMAND(ID_VIEW_OUTPUT, &CMainFrame::OnViewOutput)
    ON_UPDATE_COMMAND_UI(ID_VIEW_OUTPUT, &CMainFrame::OnUpdateViewOutput)
    ON_UPDATE_COMMAND_UI(ID_VIEW_PROPERTIES, &CMainFrame::OnUpdateViewProperties)
    ON_NOTIFY(TVN_SELCHANGED, 1, &CMainFrame::OnExplorerSelect)
    ON_NOTIFY(NM_DBLCLK, 1, &CMainFrame::OnExplorerOpen)
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
        g_undo.clear();
        P6EngineClose();
        CDocument::OnCloseDocument();
    }
};
IMPLEMENT_DYNCREATE(CRobloxDoc, CDocument)

static void* g_scriptItem;

static void captureSource(const char*, const char* name, const char* value, int, void* context) {
    if (!lstrcmpA(name, "Source")) *static_cast<CString*>(context) = value;
}

// Scintilla from the original's SciLexer.dll; CScriptEditor itself is not recovered.
class CScriptView : public CView {
    DECLARE_DYNCREATE(CScriptView)
    enum { SCI_GETLENGTH = 2006, SCI_GETTEXT = 2182, SCI_SETTEXT = 2181 };
    CWnd editor;
public:
    virtual void OnDraw(CDC*) {}
    CString Text() {
        int size = (int)editor.SendMessage(SCI_GETLENGTH) + 1;
        CString text;
        editor.SendMessage(SCI_GETTEXT, size, (LPARAM)text.GetBuffer(size));
        text.ReleaseBuffer();
        return text;
    }
    void Load(const CString& text) { editor.SendMessage(SCI_SETTEXT, 0, (LPARAM)(LPCSTR)text); }
    afx_msg int OnCreate(LPCREATESTRUCT create) {
        if (CView::OnCreate(create) == -1) return -1;
        static HMODULE lexer = LoadLibrary("SciLexer.dll");
        return lexer && editor.CreateEx(0, "Scintilla", "", WS_CHILD | WS_VISIBLE, CRect(0, 0, 0, 0), this, 1) ? 0 : -1;
    }
    afx_msg void OnSize(UINT type, int width, int height) {
        CView::OnSize(type, width, height);
        if (editor.m_hWnd) editor.MoveWindow(0, 0, width, height);
    }
    DECLARE_MESSAGE_MAP()
};
IMPLEMENT_DYNCREATE(CScriptView, CView)
BEGIN_MESSAGE_MAP(CScriptView, CView)
    ON_WM_CREATE()
    ON_WM_SIZE()
END_MESSAGE_MAP()

class CScriptDoc : public CDocument {
    DECLARE_DYNCREATE(CScriptDoc)
public:
    void* item;
    CScriptView* View() {
        POSITION position = GetFirstViewPosition();
        return position ? static_cast<CScriptView*>(GetNextView(position)) : NULL;
    }
    virtual BOOL DoFileSave() {
        int status = P6DataSetProperty(item, "Source", View()->Text());
        printf("p6: script save %d\n", status);
        if (!status) SetModifiedFlag(FALSE);
        return !status;
    }
};
IMPLEMENT_DYNCREATE(CScriptDoc, CDocument)

class CRobloxView : public CView {
    DECLARE_DYNCREATE(CRobloxView)
public:
    CPoint dragFrom;
    void* dragged;
    float dragStart[3];
public:
    CRobloxView() : dragged(NULL) {}
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
        CRect screen(rect);
        ClientToScreen(screen);
        printf("p6: view %d %d %d %d\n", screen.left, screen.top, screen.Width(), screen.Height());
        if (!status && !g_script.IsEmpty()) printf("p6: script %d\n", P6EngineScript(g_script));
        if (!status && !g_runFile.IsEmpty()) {
            RunScriptFile(g_runFile);
            g_runFile.Empty();
        }
        static_cast<CMainFrame*>(AfxGetMainWnd())->RefreshExplorer();
    }
    afx_msg void OnLButtonDown(UINT, CPoint point) {
        CRect rect;
        GetClientRect(rect);
        SetFocus();
        dragged = P6EngineDragBegin(float(point.x) / rect.Width(), float(point.y) / rect.Height(), dragStart);
        if (!dragged) return;
        static_cast<CMainFrame*>(AfxGetMainWnd())->SelectHandle(dragged);
        SetCapture();
    }
    afx_msg void OnLButtonUp(UINT, CPoint) {
        if (!dragged) return;
        ReleaseCapture();
        float end[3];
        if (!P6DataGetPosition(dragged, end) && (end[0] != dragStart[0] || end[2] != dragStart[2])) {
            UndoMove move = {dragged, {dragStart[0], dragStart[1], dragStart[2]}};
            g_undo.push_back(move);
            GetDocument()->SetModifiedFlag();
            printf("p6: moved %g %g %g\n", end[0], end[1], end[2]);
        }
        dragged = NULL;
    }
    afx_msg void OnUndo() {
        if (g_undo.empty()) return;
        UndoMove move = g_undo.back();
        g_undo.pop_back();
        printf("p6: undo %d\n", P6DataSetPosition(move.item, move.position));
    }
    afx_msg void OnUpdateUndo(CCmdUI* ui) { ui->Enable(!g_undo.empty()); }
    afx_msg void OnRButtonDown(UINT, CPoint point) { dragFrom = point; SetCapture(); }
    afx_msg void OnRButtonUp(UINT, CPoint) { ReleaseCapture(); }
    afx_msg void OnMouseMove(UINT flags, CPoint point) {
        if (dragged) {
            CRect rect;
            GetClientRect(rect);
            P6EngineDragTo(float(point.x) / rect.Width(), float(point.y) / rect.Height());
            return;
        }
        if (!(flags & MK_RBUTTON)) return;
        P6EngineOrbit(-0.01f * (point.x - dragFrom.x), 0.01f * (point.y - dragFrom.y));
        dragFrom = point;
    }
    afx_msg BOOL OnMouseWheel(UINT, short delta, CPoint) {
        P6EngineZoom(delta > 0 ? 0.9f : 1.1f);
        return TRUE;
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
    ON_WM_LBUTTONDOWN()
    ON_WM_LBUTTONUP()
    ON_COMMAND(ID_EDIT_UNDO, &CRobloxView::OnUndo)
    ON_UPDATE_COMMAND_UI(ID_EDIT_UNDO, &CRobloxView::OnUpdateUndo)
    ON_WM_RBUTTONDOWN()
    ON_WM_RBUTTONUP()
    ON_WM_MOUSEMOVE()
    ON_WM_MOUSEWHEEL()
    ON_COMMAND(ID_TOOLS_PLAY_SOLO, &CRobloxView::OnPlaySolo)
    ON_COMMAND(ID_RUN, &CRobloxView::OnRun)
    ON_COMMAND(ID_PAUSE, &CRobloxView::OnPause)
    ON_COMMAND(ID_RESET, &CRobloxView::OnReset)
    ON_UPDATE_COMMAND_UI(ID_RUN, &CRobloxView::OnUpdateRun)
    ON_UPDATE_COMMAND_UI(ID_PAUSE, &CRobloxView::OnUpdatePause)
    ON_UPDATE_COMMAND_UI(ID_TOOLS_PLAY_SOLO, &CRobloxView::OnUpdatePlaySolo)
END_MESSAGE_MAP()

// 00449910 owns templates 129, 185, 207 and 138; 185 and 207 are absent here.
class CIDEDocManager : public CDocManager {
public:
    CDocTemplate* placeTemplate;
    CDocTemplate* scriptTemplate;
    CIDEDocManager() {
        placeTemplate = new CMultiDocTemplate(IDR_PLACE, RUNTIME_CLASS(CRobloxDoc), RUNTIME_CLASS(CMDIChildWnd), RUNTIME_CLASS(CRobloxView));
        AddDocTemplate(placeTemplate);
        // Not added to the manager, so File New and Open stay place-only.
        scriptTemplate = new CMultiDocTemplate(138, RUNTIME_CLASS(CScriptDoc), RUNTIME_CLASS(CMDIChildWnd), RUNTIME_CLASS(CScriptView));
    }
};

class CRobloxApp : public CWinApp {
    CString version;
    static void Stage(const char* original, const char* name) { printf("p6-stage: %s %s\n", original, name); }
    void ReadVersion() {
        char path[MAX_PATH];
        GetModuleFileName(m_hInstance, path, MAX_PATH);
        DWORD unused, size = GetFileVersionInfoSize(path, &unused);
        CByteArray block;
        block.SetSize(size);
        VS_FIXEDFILEINFO* info = NULL;
        UINT length = 0;
        if (size && GetFileVersionInfo(path, 0, size, block.GetData()) && VerQueryValue(block.GetData(), "\\", (void**)&info, &length))
            version.Format("%u.%u.%u.%u", HIWORD(info->dwFileVersionMS), LOWORD(info->dwFileVersionMS), HIWORD(info->dwFileVersionLS), LOWORD(info->dwFileVersionLS));
    }
    bool CrashReportEnabled() {
        HKEY key;
        DWORD enabled = 1, size = sizeof(enabled);
        if (RegOpenKeyEx(HKEY_CURRENT_USER, "Software\\ROBLOX Corporation\\Roblox", 0, KEY_READ, &key) != ERROR_SUCCESS) return true;
        RegQueryValueEx(key, "CrashReport", NULL, NULL, (BYTE*)&enabled, &size);
        RegCloseKey(key);
        return enabled != 0;
    }
public:
    virtual BOOL InitInstance() {
        setvbuf(stdout, NULL, _IONBF, 0);
        Stage("0044d852", "ROBLOX InitInstance");
        InitCommonControls();
        Stage("0044d8ed", "InitCommonControls");
        if (!CWinApp::InitInstance()) return FALSE;
        ReadVersion();
        printf("p6-stage: 0044d951 version %s\n", (LPCSTR)version);
        printf("p6-stage: 0044d998 CrashReport %d (reporter not started)\n", CrashReportEnabled());
        if (!AfxOleInit()) {
            AfxMessageBox(100);
            return FALSE;
        }
        Stage("AfxOleInit", "OLE ready");
        CRobloxCommandLineInfo command;
        ParseCommandLine(command);
        if (command.m_nShellCommand == CCommandLineInfo::AppUnregister || command.m_nShellCommand == CCommandLineInfo::AppRegister) {
            Stage("0044da96", "COM registration requested; not implemented, exiting like original");
            return FALSE;
        }
        AfxEnableControlContainer();
        Stage("0044db44", "AfxEnableControlContainer");
        int startup = P6EngineStartup();
        printf("p6-stage: 0044db4e engine startup %d\n", startup);
        if (startup) return FALSE;
        g_capture = command.capture;
        g_script = command.script;
        g_runFile = command.runFile;
        g_select = command.select;
        g_setProperty = command.setProperty;
        g_editScript = command.editScript;
        g_saveAs = command.saveAs;
        g_play = command.play;
        g_pickTest = command.pickTest;
        m_pDocManager = new CIDEDocManager;
        Stage("00449910", "CIDEDocManager");
        CMainFrame* frame = new CMainFrame;
        if (!frame->LoadFrame(IDR_MAINFRAME_ROBLOX)) { delete frame; return FALSE; }
        m_pMainWnd = frame;
        CXTPCommandBar* menu = frame->GetCommandBars()->GetMenuBar();
        printf("p6: frame=%p menus=%d\n", frame->m_hWnd, menu ? menu->GetControlCount() : -1);
        frame->ShowWindow(command.autoClose && !command.visible ? SW_HIDE : m_nCmdShow);
        frame->UpdateWindow();
        Stage("00449bf0", "frame ready");
        if (command.m_nShellCommand == CCommandLineInfo::FileOpen && !ProcessShellCommand(command)) return FALSE;
        if (command.autoClose) frame->SetTimer(ID_P6_AUTOCLOSE, 5000, NULL);
        g_commands = command.post;
        g_post = (UINT)atoi(command.post);
        if (g_post) frame->SetTimer(ID_P6_COMMAND, 1000, NULL);
        return TRUE;
    }
    virtual BOOL OnIdle(LONG count) {
        BOOL more = CWinApp::OnIdle(count);
        static_cast<CMainFrame*>(m_pMainWnd)->DrainOutput();
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
        static_cast<CIDEDocManager*>(m_pDocManager)->placeTemplate->OpenDocumentFile(NULL);
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
    void OpenScript(void* item, const CString& name) {
        CString source;
        P6DataProperties(item, captureSource, &source);
        CScriptDoc* document = static_cast<CScriptDoc*>(static_cast<CIDEDocManager*>(m_pDocManager)->scriptTemplate->OpenDocumentFile(NULL));
        if (!document) return;
        document->item = item;
        document->SetTitle(name);
        document->View()->Load(source);
        printf("p6: script open %s chars=%d\n", (LPCSTR)name, source.GetLength());
        if (!g_editScript.IsEmpty()) {
            document->View()->Load(source + "\n-- p6 edit\n");
            document->DoFileSave();
            CString after;
            P6DataProperties(item, captureSource, &after);
            printf("p6: script after chars=%d marker=%d\n", after.GetLength(), after.Find("p6 edit") >= 0);
            g_editScript.Empty();
        }
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

void CMainFrame::OnExplorerOpen(NMHDR*, LRESULT* result) {
    HTREEITEM item = explorer.GetSelectedItem();
    CString source;
    source = "\1";
    if (item) P6DataProperties((void*)explorer.GetItemData(item), captureSource, &source);
    if (item && source != "\1") theApp.OpenScript((void*)explorer.GetItemData(item), explorer.GetItemText(item));
    *result = 0;
}

static void RunScriptFile(const CString& path) { CRobloxApp::RunFile(path); }
