#include "CRobloxApp.h"
#include <atlbase.h>
#include "util/standardout.h"
#include "security/SecurityContext.h"
#include "Network/API.h"

IMPLEMENT_DYNAMIC(CRobloxApp, CWinApp)

BEGIN_MESSAGE_MAP(CRobloxApp, CWinApp)
    ON_COMMAND(ID_FILE_NEW, CWinApp::OnFileNew)
    ON_COMMAND(ID_FILE_OPEN, CWinApp::OnFileOpen)
    ON_COMMAND(ID_FILE_PRINT_SETUP, CWinApp::OnFilePrintSetup)
END_MESSAGE_MAP()

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

#include <afxpriv.h>
#include <afxole.h>
#include <afxdisp.h>
#include <stdexcept>
#include "CMainFrame.h"
#include "CRenderSettings.h"

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
void nativeInitializeCallbacks();                     // 0044cbb0
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
        RBX::Network::API::init(version.c_str());
        AfxEnableControlContainer(0);
        initializeSettings();
        nativeInitializeCallbacks();
        if (!nativeStartupMode) nativeStartupMode = CRenderSettings::singleton().graphicsMode;
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

BOOL CRobloxApp::initializeFramework(bool maximized)
{
    if (m_pMainWnd != 0) {
        if (!::IsWindowVisible(m_pMainWnd->m_hWnd))
            ((CMainFrame*)m_pMainWnd)->showFrame(m_nCmdShow);
        return ((CMainFrame*)m_pMainWnd)->m_hWnd != 0;
    }

    CMainFrame* frame = new CMainFrame;
    if (!frame)
        return 0;
    if (!frame->LoadFrame(0x80, 0xcf8000, 0, 0))
        return 0;

    if (maximized)
        frame->hideEditorChrome();
    else
        frame->showEditorChrome(false);

    ::DragAcceptFiles(frame->m_hWnd, 1);
    frame->showFrame(m_nCmdShow);
    m_pMainWnd = frame;

    if (m_atomApp == 0 && m_atomSystemTopic == 0)
        EnableShellOpen();

    return TRUE;
}

#include "CRobloxDHtmlDialog.h"
#include "util/Http.h"
#include <exdispid.h>

IMPLEMENT_DYNAMIC(CRobloxDHtmlDialog, CDHtmlDialog)

BEGIN_EVENTSINK_MAP(CRobloxDHtmlDialog, CDHtmlDialog)
    ON_EVENT(CRobloxDHtmlDialog, 102, DISPID_BEFORENAVIGATE2, BeforeNavigate2,
        VTS_DISPATCH VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PBOOL)
    ON_EVENT(CRobloxDHtmlDialog, 102, DISPID_WINDOWCLOSING, WindowClosing, VTS_BOOL VTS_PBOOL)
END_EVENTSINK_MAP()

__declspec(noinline) HRESULT __cdecl checkDialogUrl(const char* url)
{
    return RBX::Http::trustCheck(url) ? S_OK : E_FAIL;
}

CRobloxDHtmlDialog::CRobloxDHtmlDialog(UINT dialog, UINT html, CWnd* parent)
    : CDHtmlDialog(dialog, html, parent)
{
    m_bUseHtmlTitle = TRUE;
    SetHostFlags(m_dwHostFlags | 0x01844013);
}

CRobloxDHtmlDialog::CRobloxDHtmlDialog(UINT dialog, const char* location, CWnd* parent)
    : CDHtmlDialog(dialog, 0x72, parent), url(location)
{
    m_bUseHtmlTitle = TRUE;
    SetHostFlags(m_dwHostFlags | 0x01844013);
}

int CRobloxDHtmlDialog::OnInitDialog(void)
{
    CDHtmlDialog::OnInitDialog();
    if (url.length() != 0)
    {
        const char* (std::string::*pc)() const = &std::string::c_str;
        Navigate((url.*pc)(), 0, 0, 0, 0, 0);
        return 0;
    }
    return 1;
}

BOOL CRobloxDHtmlDialog::IsExternalDispatchSafe()
{
    return TRUE;
}

void CRobloxDHtmlDialog::BeforeNavigate2(LPDISPATCH browser, VARIANT* location,
    VARIANT*, VARIANT*, VARIANT*, VARIANT*, BOOL* cancel)
{
    extern long __cdecl checkDialogUrl(const char*);
    CString address(location->bstrVal);
    const char* (ATL::CSimpleStringT<char, 1>::*text)() const = &ATL::CSimpleStringT<char, 1>::operator const char*;
    if (checkDialogUrl((address.*text)()))
        *cancel = 1;
    else
        OnBeforeNavigate(browser, (address.*text)());
}

void CRobloxDHtmlDialog::WindowClosing(BOOL, BOOL* cancel)
{
    *cancel = -1;
    CString result;
    DDX_DHtml_ElementText("DialogResult", DISPID_A_VALUE, result, TRUE);
    const char* (ATL::CSimpleStringT<char, 1>::*text)() const = &ATL::CSimpleStringT<char, 1>::operator const char*;
    if (result.Compare("") != 0 && atoi((result.*text)()) == 1)
        OnOK();
    else
        OnCancel();
}

namespace RBX { const char* get_thread_name(); }
#include "AppLeaves2008/RbxDocTemplates2008.h"

extern CRobloxApp theApp;   // 0096dbe0 (ecx of the 00449bf0 call in 0044a170)

#ifdef NATIVE_APPLEAVES2008_PENDING
CFrameWnd* CRbxDocTemplate::CreateNewFrame(CDocument* pDoc, CFrameWnd* pOther)
{
    theApp.initializeFramework(true);
    return CMultiDocTemplate::CreateNewFrame(pDoc, pOther);
}
#endif

void CRbxPlayDocTemplate::RemoveDocument(CDocument* pDoc)
{
    CMultiDocTemplate::RemoveDocument(pDoc);
    if (pDoc == playDocument)
        playDocument = 0;
}

CDocument* CRbxPlayDocTemplate::openDocumentFile(LPCTSTR lpszPathName, BOOL bMakeVisible)
{
    lastError = "";
    CDocument* pDocument = CreateNewDocument();
    if (pDocument == NULL)
    {
        lastError = "CDocTemplate::CreateNewDocument returned NULL";
        AfxMessageBox(AFX_IDP_FAILED_TO_CREATE_DOC);
        return NULL;
    }

    BOOL bAutoDelete = pDocument->m_bAutoDelete;
    pDocument->m_bAutoDelete = FALSE;
    CFrameWnd* pFrame = CreateNewFrame(pDocument, NULL);
    pDocument->m_bAutoDelete = bAutoDelete;
    if (pFrame == NULL)
    {
        lastError = "CreateNewFrame returned NULL";
        AfxMessageBox(AFX_IDP_FAILED_TO_CREATE_DOC);
        delete pDocument;
        return NULL;
    }

    if (lpszPathName == NULL)
    {
        SetDefaultTitle(pDocument);
        if (!bMakeVisible)
            pDocument->m_bEmbedded = TRUE;
        if (!pDocument->OnNewDocument())
        {
            lastError = "CDocument::OnNewDocument returned FALSE";
            pFrame->DestroyWindow();
            return NULL;
        }
        m_nUntitledCount++;
    }
    else
    {
        CWaitCursor wait;
        if (!pDocument->OnOpenDocument(lpszPathName))
        {
            lastError = "CDocument::OnNewDocument returned FALSE (v2)";
            pFrame->DestroyWindow();
            return NULL;
        }
        pDocument->SetPathName(lpszPathName);
    }

    InitialUpdateFrame(pFrame, pDocument, bMakeVisible);
    return pDocument;
}
