// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/mfc-noinline-pcxstr /I{headers}/std-noinline-string
// >>> native-status (generated) -- do not edit >>>
// CMainFrameConstructor | 2008-06 | 1 byte-exact, inactive (not link-selected)
// 1/2 mapped addresses byte-exact | 1 unproved | no mapped strings | by EspClaude (+1) (deepseek:deepseek-chat)
// <<< native-status | src 37c5515d | roc native-status --write
#include "CMainFrame.h"
#include "v8datamodel/BrickColor.h"
#include "v8datamodel/ToolsPart.h"
#include "util/FileSystem.h"
#include <atlbase.h>

extern bool nativeLockA, nativeLockB, nativeLockC;

CMainFrame::CMainFrame()
    : stateF8(false), stateF9(false), stateFA(false), monitor(NULL), resource(NULL),
      state104(false), state105(false), splitter(NULL), propertyGrid(NULL), selectionCaption(NULL)
{
    {
        DWORD value = 0;
        ATL::CRegKey key;
        if (key.Open(HKEY_CURRENT_USER, "Software\\ROBLOX Corporation\\Roblox", KEY_READ) == ERROR_SUCCESS)
            key.QueryDWORDValue("OverrideLockViewGamelayout", value);
        nativeLockA = nativeLockB = nativeLockC = (value == 1);
    }
    std::string path = RBX::FileSystem::getUserAppDataDirectory(true, NULL);
    if (path.size() > 0)
        text.Format("%s\\IDESettings.xml", path.c_str());
    RBX::FillTool::color.addListener(this);
    XTPImageManager()->InternalAddRef();
    dockingPanes.SetImageManager(XTPImageManager());
}
