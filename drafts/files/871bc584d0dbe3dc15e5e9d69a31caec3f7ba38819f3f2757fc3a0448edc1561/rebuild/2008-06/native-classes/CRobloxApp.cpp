// native-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MD /D_AFXDLL /D_DLL /I{headers}/mfc-noinline-pcxstr /I{headers}/std-noinline-string
#include "CRobloxApp.h"
#include <atlbase.h>
#include "util/standardout.h"
#include "security/SecurityContext.h"

IMPLEMENT_DYNAMIC(CRobloxApp, CWinApp)

CRobloxApp::CRobloxApp() : CWinApp(NULL), logManager("Roblox")
{
}

CRobloxApp::~CRobloxApp()
{
}

int CRobloxApp::Run()
{
    RBX::Security::Impersonator impersonator(RBX::Security::LocalGUI);
    return CWinApp::Run();
}

// Callees of InitInstance outside this class. Addresses are the original call targets; names
// are provisional where the owning class is not recovered yet.
#include <afxpriv.h>
#include <afxole.h>
#include <afxdisp.h>
#include <stdexcept>
#include "VersionInfo.h" // PJ Naughter CVersionInfo (OpenRBX declaration)

class CRobloxCommandLineInfo : public CCommandLineInfo {
public:
    bool flag28, flag29, flag2a, flag2b, flag2c, flag2d, embeddedIde, noStartPage; // +28..+2f
    std::vector<std::string> files;                                                  // +30
    CRobloxCommandLineInfo();          // 0044c1b0 (sizeof 72)
    virtual ~CRobloxCommandLineInfo(); // 0044c360
};
class CBrowserDocManager : public CDocManager {
    CDocTemplate* browserTemplate;     // +20
public:
    CBrowserDocManager();              // 00449650 (sizeof 36)
};
class CIDEDocManager : public CDocManager {
    CDocTemplate* templates[4];        // +20..+2c
public:
    CIDEDocManager(bool);              // 00449910 (sizeof 48)
};
class NativeAtlModule { public: HRESULT RegisterServer(BOOL, const CLSID*); }; // 0044bea0
class LogManager { public: static void ReportException(const std::exception&); }; // 00428850
class NativeClassRegistration { public: NativeClassRegistration(); };             // 005c3ca0

extern CString nativeCrashReportText;                 // 0096dcf0
extern NativeAtlModule nativeAtlModule;               // 0096dbb4
extern HRESULT (__stdcall* nativeRegistrationCallback)(); // 0096dd00
extern int nativeStartupMode;                         // 0096d358
void nativeSetOutputMode(int);                        // 00569910
void nativeProfilerEnable(bool);                      // 005c3f00
void nativeInitializeTypes();                         // 004448f0
void nativeInitializeCom();                           // 004495a0
void nativeRegisterNames1();                          // 0041b8a0
void nativeRegisterNames2();                          // 0041bb70
void nativeRegisterNames3();                          // 0041bc40
void nativeSetVersion(const char*);                   // 0049ecf0
void nativeInitializeCallbacks();                     // 0044cbb0
void* nativeStartupContext();                         // 00412d50 (+0x130: startup mode)
void __stdcall nativeSetRegistrationMode(bool);       // 0044d150

BOOL CRobloxApp::InitInstance()
{
    try {
        nativeSetOutputMode(0);
        RBX::StandardOut::singleton()->print(RBX::MESSAGE_INFO, "ROBLOX InitInstance");
        RBX::Security::Impersonator impersonator(RBX::Security::LocalGUI);
        errorUploader.reset(new ErrorUploader);
        InitCommonControls();
        if (!CWinApp::InitInstance()) return FALSE;
        {
            CVersionInfo info;
            CString file;
            AfxGetModuleShortFileName(m_hInstance, file);
            info.Load(file);
            version = info.GetFileVersionAsString();
        }
        {
            ATL::CRegKey key;
            if (key.Open(HKEY_CURRENT_USER, "Software\\ROBLOX Corporation\\Roblox", KEY_READ) == ERROR_SUCCESS) {
                DWORD enabled = 1;
                key.QueryDWORDValue("CrashReport", enabled);
                const DWORD crashReportingEnabled = enabled;
                nativeCrashReportText.ReleaseBuffer();
                if (crashReportingEnabled) logManager.startCrashReporter();
            } else logManager.startCrashReporter();
        }
        if (!AfxOleInit()) {
            AfxMessageBox(100, 0, static_cast<UINT>(-1));
            return FALSE;
        }
        nativeInitializeCom();
        CRobloxCommandLineInfo command;
        ParseCommandLine(command);
        if (command.m_nShellCommand == CCommandLineInfo::AppUnregister) {
            nativeSetRegistrationMode(false);
            if (!nativeRegistrationCallback || SUCCEEDED(nativeRegistrationCallback()))
                ATL::AtlComModuleUnregisterServer(&ATL::_AtlComModule, TRUE, 0);
            return FALSE;
        }
        if (command.m_nShellCommand == CCommandLineInfo::AppRegister) {
            nativeSetRegistrationMode(true);
            nativeAtlModule.RegisterServer(TRUE, 0);
            return FALSE;
        }
        nativeProfilerEnable(true);
        nativeInitializeTypes();
        static NativeClassRegistration classes;
        nativeRegisterNames1();
        nativeRegisterNames2();
        nativeSetVersion(version.c_str());
        AfxEnableControlContainer(0);
        initializeSettings();
        nativeInitializeCallbacks();
        void* startup = nativeStartupContext();
        if (!nativeStartupMode) nativeStartupMode = *reinterpret_cast<int*>((char*)startup + 0x130);
        if (nativeStartupMode == 5) command.noStartPage = true;
        nativeRegisterNames3();
        if (command.m_bRunEmbedded || command.m_bRunAutomated) {
            m_pDocManager = new CIDEDocManager(command.noStartPage);
            if (FAILED(ATL::AtlComModuleRegisterClassObjects(&ATL::_AtlComModule, CLSCTX_LOCAL_SERVER, REGCLS_MULTIPLEUSE))) return FALSE;
            return TRUE;
        }
        if (command.embeddedIde) {
            m_pDocManager = new CBrowserDocManager;
            return ProcessShellCommand(command);
        }
        m_pDocManager = new CIDEDocManager(command.noStartPage);
        if (!initializeFramework(0) || FAILED(ATL::AtlComModuleRegisterClassObjects(&ATL::_AtlComModule, CLSCTX_LOCAL_SERVER, REGCLS_MULTIPLEUSE))) return FALSE;
        if (command.m_nShellCommand == CCommandLineInfo::FileNew) {
            if (command.files.size()) {
                ProcessShellCommand(command);
                return openFiles(command.files.begin(), command.files.end());
            }
            if (!command.noStartPage) initializeEmptyDocument();
            return TRUE;
        }
        if (command.m_nShellCommand == CCommandLineInfo::FileOpen)
            return ProcessShellCommand(command) && openFiles(command.files.begin(), command.files.end());
        return ProcessShellCommand(command);
    } catch (const std::runtime_error& error) {
        LogManager::ReportException(error);
        AfxMessageBox(error.what(), MB_ICONSTOP, 0);
        return FALSE;
    }
}

int CRobloxApp::ExitInstance()
{
    RBX::StandardOut::singleton()->print(RBX::MESSAGE_INFO, "ROBLOX ExitInstance");
    ATL::AtlComModuleRevokeClassObjects(&ATL::_AtlComModule);
    return CWinApp::ExitInstance();
}

void CRobloxApp::initializeEmptyDocument()
{
    OnFileNew();
}
