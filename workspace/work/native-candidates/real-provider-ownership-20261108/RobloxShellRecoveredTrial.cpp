// P6 client: CRobloxApp::InitInstance 0044d810 order, original resources, and a
// place document template from resource 129. Rendering and play go through the
// recovered player's engine via P6Engine.cpp. Not byte-verified.
#include <afxwin.h>
#include <afxole.h>
#include <afxcmn.h>
#include <afxext.h>
#include <afxmt.h>
#include <XTToolkitPro.h>
#include "../native-headers/MyXTPCommandBars.h"
#include "../native-headers/CAboutRobloxDialog.h"
#include <stdio.h>
#include <vector>
#include "P6Engine.h"
#pragma comment(lib, "version.lib")

void InitializeAllIcons(CXTPImageManager*);

static const UINT IDR_MAINFRAME_ROBLOX = 128; // RT_MENU/RT_ACCELERATOR/RT_GROUP_ICON 128
static const UINT IDR_PLACE = 129;            // RT_MENU and doc string "Places (*.rbxl)"
static const UINT ID_P6_AUTOCLOSE = 1;
static const UINT ID_P6_COMMAND = 2;
static const UINT IDD_P6_ABOUT = 117;              // 00401220 passes 0x75 to the dialog base
static const UINT ID_VIEW_PROPERTIES = 32783;      // CMainFrame map, handler 0042e610
static const UINT ID_RUN = 32966;                  // toolbar 137: Run, Pause, Reset
static const UINT ID_PAUSE = 32967;
static const UINT ID_RESET = 32968;
static const UINT ID_HELP_OBJECT_BROWSER = 32990;  // CRobloxApp map, handler 0044a2e0
static const UINT ID_VIEW_FULLSCREEN = 33012;      // CMainFrame map, handler 00431ce0
static const UINT ID_INSERT_OBJECT = 32895;
static const UINT ID_EDIT_DUPLICATE = 32773;
static const UINT ID_FORMAT_ROTATE = 32835;
static const UINT ID_FORMAT_TILT = 32836;
static const UINT ID_EDIT_LOCK = 32784;
static const UINT ID_EDIT_UNLOCK_ALL = 32785;
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
    bool checkNativeMD5;
    CString* expecting;
    CString holdDelay, capture, script, saveAs, post, runFile, select, setProperty, editScript;
    CRobloxCommandLineInfo() : autoClose(false), visible(false), play(false), pickTest(false), checkNativeMD5(false), expecting(NULL) {}
    virtual void ParseParam(const char* param, BOOL flag, BOOL last) {
        if (expecting) { *expecting = param; expecting = NULL; return; }
        if (flag && !lstrcmpiA(param, "p6-autoclose")) { autoClose = true; return; }
        if (flag && !lstrcmpiA(param, "p6-check-md5")) { checkNativeMD5 = true; return; }
        if (flag && !lstrcmpiA(param, "p6-visible")) { autoClose = visible = true; return; }
        if (flag && !lstrcmpiA(param, "p6-play")) { play = true; return; }
        if (flag && !lstrcmpiA(param, "p6-holdw")) { expecting = &holdDelay; return; }
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
#include "CMainFrame.h"

static void RunScriptFile(const CString& path);

#include "CRobloxDoc.h"

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

class CNullDoc : public CDocument {
    DECLARE_DYNCREATE(CNullDoc)
};
IMPLEMENT_DYNCREATE(CNullDoc, CDocument)

// Help > Object Browser: classes and summaries from ReflectionMetadata.xml.
class CObjectBrowser : public CView {
    DECLARE_DYNCREATE(CObjectBrowser)
    CTreeCtrl tree;
public:
    virtual void OnDraw(CDC*) {}
    afx_msg int OnCreate(LPCREATESTRUCT create) {
        if (CView::OnCreate(create) == -1) return -1;
        if (!tree.Create(WS_CHILD | WS_VISIBLE | TVS_HASLINES | TVS_HASBUTTONS | TVS_LINESATROOT, CRect(0, 0, 0, 0), this, 1)) return -1;
        char path[MAX_PATH];
        GetModuleFileName(NULL, path, MAX_PATH);
        CString file(path);
        file = file.Left(file.ReverseFind('\\') + 1) + "ReflectionMetadata.xml";
        CStdioFile metadata;
        if (!metadata.Open(file, CFile::modeRead)) return 0;
        CString line;
        HTREEITEM item = NULL;
        while (metadata.ReadString(line)) {
            int at = line.Find("name=\"Name\">");
            if (at >= 0) item = tree.InsertItem(line.Mid(at + 12, line.Find('<', at + 12) - at - 12));
            at = line.Find("name=\"summary\">");
            if (at >= 0 && item) tree.InsertItem(line.Mid(at + 15, line.Find('<', at + 15) - at - 15), item);
        }
        printf("p6: object browser nodes=%u\n", tree.GetCount());
        return 0;
    }
    afx_msg void OnSize(UINT type, int width, int height) {
        CView::OnSize(type, width, height);
        if (tree.m_hWnd) tree.MoveWindow(0, 0, width, height);
    }
    DECLARE_MESSAGE_MAP()
};
IMPLEMENT_DYNCREATE(CObjectBrowser, CView)
BEGIN_MESSAGE_MAP(CObjectBrowser, CView)
    ON_WM_CREATE()
    ON_WM_SIZE()
END_MESSAGE_MAP()

#include "CRobloxView.h"

// 00449910 owns 129 place, 185 browser, 207 script and 138 object browser. 185 is online-only and absent.
class CIDEDocManager : public CDocManager {
public:
    CDocTemplate* placeTemplate;
    CDocTemplate* scriptTemplate;
    CDocTemplate* browserTemplate;
    CIDEDocManager() {
        placeTemplate = new CMultiDocTemplate(IDR_PLACE, RUNTIME_CLASS(CRobloxDoc), RUNTIME_CLASS(CMDIChildWnd), RUNTIME_CLASS(CRobloxView));
        AddDocTemplate(placeTemplate);
        // Not added to the manager, so File New and Open stay place-only.
        scriptTemplate = new CMultiDocTemplate(207, RUNTIME_CLASS(CScriptDoc), RUNTIME_CLASS(CMDIChildWnd), RUNTIME_CLASS(CScriptView));
        browserTemplate = new CMultiDocTemplate(138, RUNTIME_CLASS(CNullDoc), RUNTIME_CLASS(CMDIChildWnd), RUNTIME_CLASS(CObjectBrowser));
    }
};

#include "CRobloxApp.h"

// Normally supplied by mfcs90.lib, which this client does not link yet.
extern "C" { int _afxForceEXCLUDE; int _afxForceSTDAFX; }

CRobloxApp theApp;




