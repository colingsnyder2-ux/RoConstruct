// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: atl-9.0-dll-rtm roc_espclaude_92ffea660fe41891.cpp

// Candidate translation unit (score above; library headers required).
#include <memory>
#include <atlbase.h>

struct MfcString {
    __declspec(dllimport) MfcString() throw();
    __declspec(dllimport) ~MfcString();
    __declspec(dllimport) void __cdecl Format(const char* fmt, ...);
    char* p;
};
struct StdString {
    __declspec(dllimport) ~StdString();
    __declspec(dllimport) unsigned int size() const;
    __declspec(dllimport) const char* c_str() const;
    char storage[0x1c];
};
StdString getAppPath(bool a, bool b);

class FrameBase {
public:
    FrameBase();
    virtual ~FrameBase();
    char pad[0xec];
};
namespace RBX {
class RunService;
class Heartbeat;
template<class N, class E> class __declspec(novtable) Listener {
public:
    virtual void onEvent(const N*, E) = 0;
    virtual ~Listener() {}
};
template<class N, class E> class Notifier {
public:
    void addListener(Listener<N, E>* l) const;
};
}
extern RBX::Notifier<RBX::RunService, RBX::Heartbeat> heartbeatNotifier;

class CCmdTargetLike {
public:
    virtual ~CCmdTargetLike();
    long m_dwRef;
    void InternalAddRef() { InterlockedIncrement(&m_dwRef); }
};
CCmdTargetLike* XTPImageManager();

class Thing { public: ~Thing(); };
class Poly { public: virtual ~Poly(); };
struct WindowPos { WindowPos(); char pad[0x2c]; };
struct DockingPaneManager { DockingPaneManager(); ~DockingPaneManager(); void SetImageManager(CCmdTargetLike*); char pad[0x14c]; };
struct TabClientWnd { TabClientWnd(); ~TabClientWnd(); char pad[0x124]; };
struct ThemeManager { ThemeManager(); ~ThemeManager(); char pad[0x2c]; };
struct StatusBar { StatusBar(); ~StatusBar(); char pad[0x10]; };

class RegKey {
public:
    HKEY m_hKey;
    RegKey() throw() : m_hKey(NULL) {}
    ~RegKey() throw() { Close(); }
    LONG Close() throw()
    {
        LONG lRes = ERROR_SUCCESS;
        if (m_hKey != NULL) {
            lRes = RegCloseKey(m_hKey);
            m_hKey = NULL;
        }
        return lRes;
    }
    LONG Open(HKEY hKeyParent, LPCTSTR lpszKeyName, REGSAM samDesired) throw()
    {
        HKEY hKey = NULL;
        LONG lRes = RegOpenKeyEx(hKeyParent, lpszKeyName, 0, samDesired, &hKey);
        if (lRes == ERROR_SUCCESS) {
            lRes = Close();
            m_hKey = hKey;
        }
        return lRes;
    }
    LONG QueryDWORDValue(LPCTSTR pszValueName, DWORD& dwValue) throw()
    {
        DWORD dwType;
        ULONG nBytes = sizeof(DWORD);
        LONG lRes = RegQueryValueEx(m_hKey, pszValueName, NULL, &dwType, reinterpret_cast<LPBYTE>(&dwValue), &nBytes);
        if (lRes != ERROR_SUCCESS)
            return lRes;
        if (dwType != REG_DWORD)
            return ERROR_INVALID_DATA;
        return ERROR_SUCCESS;
    }
};
extern bool g_lockA, g_lockB, g_lockC;

class CMainFrame : public FrameBase, public RBX::Listener<RBX::RunService, RBX::Heartbeat>
{
public:
    std::auto_ptr<Thing> m_f4;
    bool m_f8, m_f9, m_fa;
    int m_fc, m_100;
    bool m_104, m_105;
    MfcString m_settingsFile;
    WindowPos m_wndPos;
    DockingPaneManager m_paneManager;
    TabClientWnd m_tabClient;
    std::auto_ptr<Poly> m_3a8, m_3ac, m_3b0;
    ThemeManager m_theme;
    StatusBar m_statusBar;
    CMainFrame();
    virtual ~CMainFrame();
    virtual void onEvent(const RBX::RunService*, RBX::Heartbeat);
};

CMainFrame::CMainFrame()
    : m_f8(false), m_f9(false), m_fa(false), m_fc(0), m_100(0), m_104(false), m_105(false)
{
    {
        DWORD value = 0;
        RegKey key;
        if (key.Open(HKEY_CURRENT_USER, "Software\\ROBLOX Corporation\\Roblox", KEY_READ) == ERROR_SUCCESS)
            key.QueryDWORDValue("OverrideLockViewGamelayout", value);
        g_lockA = g_lockB = g_lockC = (value == 1);
    }

    StdString path = getAppPath(true, false);
    if (path.size() > 0)
        m_settingsFile.Format("%s\\IDESettings.xml", path.c_str());
    heartbeatNotifier.addListener(this);
    XTPImageManager()->InternalAddRef();
    m_paneManager.SetImageManager(XTPImageManager());
}
