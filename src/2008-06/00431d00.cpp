// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" __declspec(dllimport) int __stdcall PostMessageA(void* hWnd, unsigned int msg, unsigned int wParam, long lParam);

struct CREATESTRUCTA;
struct CRuntimeClass;
extern CRuntimeClass commandBarsClass;
extern const unsigned int indicators[6];

class CWinAppLike {
public:
    unsigned int GetProfileIntA(const char* section, const char* entry, int def);
};
struct ModuleState { void* pad; CWinAppLike* m_pCurrentWinApp; };
ModuleState* __stdcall AfxGetModuleState();
inline CWinAppLike* AfxGetApp() { return AfxGetModuleState()->m_pCurrentWinApp; }

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);
class ImageManager { public: virtual ~ImageManager(); long m_dwRef; int SetIcons(unsigned int id, int state); void InternalAddRef() { InterlockedIncrement(&m_dwRef); } };
ImageManager* XTPImageManager();
void initImages(ImageManager* m);

class ToolTipContext { public: void SetStyle(int style); };
class CommandBarsOptions { public: void ShowKeyboardCues(int show); };
class CommandBars {
public:
    char pad[0x74];
    CommandBarsOptions* m_pOptions;
    ImageManager* GetImageManager() const;
    ToolTipContext* GetToolTipContext() const;
    void SetImageManager(ImageManager* m);
    CommandBarsOptions* GetCommandBarsOptions() const { return m_pOptions; }
};

class FrameBase {
public:
    virtual ~FrameBase();
    char pad0[0x1c];
    void* m_hWnd;
    char pad1[0xc8];
    CommandBars* m_pCommandBars;
    int OnCreate(CREATESTRUCTA* lpCreateStruct);
    int InitCommandBars(CRuntimeClass* cls);
    CommandBars* GetCommandBars() const { return m_pCommandBars; }
};

class Thing { public: Thing(); ~Thing(); char pad[0x14]; };
template<class T> class Owned { public: T* p; void reset(T* q); };
struct StatusBar { int Create(void* parent, unsigned long style, unsigned int id); int SetIndicators(const unsigned int* ids, int n); char pad[0x10]; };
struct ThemeManager { void SetTheme(int t); char pad[0x2c]; };
struct PaintManager { static void SetTheme(int t); };
struct DockingPaneManager {
    void InstallDockingPanes(void* site, int clipChildren);
    void SetTheme(int t);
    char pad[0xf8];
    int m_bShowContents;
    int m_bAlpha;
    char pad2[0x4c];
};
struct TabPaintManager { char pad[0x24]; int m_24; };
struct TabClientWnd {
    int Attach(void* frame, int autoTheme);
    TabPaintManager* GetPaintManager();
    void EnableToolTips(int behaviour);
    char pad[0x124];
};

class __declspec(novtable) HeartbeatListener { public: virtual void onEvent(const void*, int) = 0; };
class CMainFrame : public FrameBase, public HeartbeatListener
{
public:
    Owned<Thing> m_f4;
    char pad_f8[0x0c];
    bool m_104;
    char pad_105[0x33];
    DockingPaneManager m_paneManager;
    TabClientWnd m_tabClient;
    char pad_3a8[0xc];
    ThemeManager m_theme;
    StatusBar m_statusBar;
    int OnCreate(CREATESTRUCTA* lpCreateStruct);
    void ShowFrame(int show);
    void LoadLayout();
    void SetFullScreen(int on);
    virtual void onEvent(const void*, int);
};

int CMainFrame::OnCreate(CREATESTRUCTA* lpCreateStruct)
{
    if (FrameBase::OnCreate(lpCreateStruct) == -1)
        return -1;
    if (!m_statusBar.Create(this, 0x50008200, 0xe801))
        return 0;
    if (!m_statusBar.SetIndicators(indicators, sizeof(indicators) / sizeof(unsigned int)))
        return 0;
    if (!InitCommandBars(&commandBarsClass))
        return -1;
    m_theme.SetTheme(2);
    PaintManager::SetTheme(4);
    m_paneManager.InstallDockingPanes(this, 1);
    m_paneManager.SetTheme(9);
    m_tabClient.Attach(this, 0);
    m_tabClient.GetPaintManager()->m_24 = 0;
    m_tabClient.EnableToolTips(1);
    CommandBars* pCommandBars = GetCommandBars();
    if (!pCommandBars)
        return 0;
    pCommandBars->GetImageManager()->SetIcons(0x91, 0);
    m_paneManager.m_bShowContents = 1;
    m_paneManager.m_bAlpha = 1;
    pCommandBars->GetCommandBarsOptions()->ShowKeyboardCues(2);
    pCommandBars->GetToolTipContext()->SetStyle(2);
    XTPImageManager()->InternalAddRef();
    pCommandBars->SetImageManager(XTPImageManager());
    XTPImageManager()->SetIcons(0x91, 0);
    m_104 = true;
    ShowFrame(1);
    initImages(XTPImageManager());
    LoadLayout();
    if (AfxGetApp()->GetProfileIntA("Settings", "fullscreen", 0) == 1)
        SetFullScreen(1);
    PostMessageA(m_hWnd, 0x111, 0x8101, 0);
    m_f4.reset(new Thing());
    return 0;
}
