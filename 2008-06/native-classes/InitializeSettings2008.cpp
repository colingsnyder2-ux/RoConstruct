// native-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MD /D_AFXDLL /D_DLL /I{headers}/mfc-noinline-pcxstr-len /I{headers}/std-noinline-string
// 2008-06 native CRobloxApp::initializeSettings 0044c760 (inactive). Structure from the 2007 OpenRBX Roblox.cpp
// FUN_004509e0 (read for evidence), checked against the 2008 disassembly: registry key and profile settings, the Settings
// XML exchange (AppSettings.xml next to the exe: SilentCrashReport, BaseUrl, ContentFolder with HKLM Software\Roblox
// BaseUrl as the fallback), the content asset folder, then the four GlobalSettings items and GlobalSettings::loadState.
// INFERRED: local names, CPath use and the helper at 0044c620 (GlobalSettings state dump, called last) from the disassembly.
#include "CRobloxApp.h"
#include <atlbase.h>
#include <atlpath.h>
#include <afxpriv.h>
#include "../native-headers/CMainFrame.h"
#include "../native-headers/CRenderSettings.h"
#include "../native-headers/AuthoringSettings.h"
#include "AppLeaves2008/RobloxCrashReporter2008.h"
#include "util/ContentProvider.h"
#include "v8datamodel/DebugSettings.h"
#include "v8datamodel/GameSettings.h"

extern CString nativeCrashReportText;   // 0096dcf0: the BaseUrl string
void nativeLogGlobalSettings();         // 0044c620

void CRobloxApp::initializeSettings()
{
    SetRegistryKey("ROBLOX Corporation");
    LoadStdProfileSettings(6);

    CXTPPropExchangeXMLNode px(TRUE, NULL, "Settings");
    px.SetCompactMode(FALSE);

    CString moduleFileName;
    AfxGetModuleShortFileName(AfxGetApp()->m_hInstance, moduleFileName);
    ATL::CPath path(moduleFileName);
    path.RemoveFileSpec();
    px.LoadFromFile(path.m_strPath + "\\AppSettings.xml");

    {
        BOOL silent = TRUE;
        if (!PX_Bool(&px, "SilentCrashReport", silent) || silent) {
            silent = FALSE;
            ATL::CRegKey key;
            if (key.Open(HKEY_CURRENT_USER, "Software\\ROBLOX Corporation\\Roblox", KEY_READ) == ERROR_SUCCESS) {
                DWORD value = 0;
                key.QueryDWORDValue("SilentCrashReport", value);
                silent = value;
                nativeCrashReportText.ReleaseBuffer();
            }
        }
        silentCrashReport = silent != FALSE;
    }

    PX_String(&px, "BaseUrl", nativeCrashReportText);
    if (nativeCrashReportText.IsEmpty()) {
        ATL::CRegKey key;
        if (key.Open(HKEY_LOCAL_MACHINE, "Software\\Roblox", KEY_READ) == ERROR_SUCCESS) {
            ULONG length = 1024;
            key.QueryStringValue("BaseUrl", nativeCrashReportText.GetBuffer(1024), &length);
            nativeCrashReportText.ReleaseBuffer();
        }
    }

    CString contentFolder;
    PX_String(&px, "ContentFolder", contentFolder);
    if (!contentFolder.IsEmpty()) {
        ATL::CPath assetFolder;
        assetFolder.Combine(path, contentFolder);
        RBX::ContentProvider::setAssetFolder(assetFolder);   // static 00560590: no singleton() call in 0044c760
    }

    CRenderSettings::singleton();
    AuthoringSettings::singleton();
    RBX::DebugSettings::singleton();
    RBX::GameSettings::singleton();
    RBX::GlobalSettings::singleton()->loadState();
    nativeLogGlobalSettings();
}
