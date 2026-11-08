// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// >>> native-status (generated) -- do not edit >>>
// LDrawAssetState | 2008-06 | selection unverified
// unmapped (no indexed address) | by -
// <<< native-status | src e10d6826 | roc native-status --write
#include <shlobj.h>
#include <string>
#include <boost/thread/once.hpp>
#include <memory>
#include "util/StandardOut.h"
#include "util/LDrawMapRoot.h"

namespace RBX { namespace LDraw2Lua {
std::auto_ptr<LDraw2RobloxMapRoot> currentMap;
boost::once_flag assetFolderOnce = BOOST_ONCE_INIT;
std::string assetFolder;

void initializeAssetFolder()
{
    char path[MAX_PATH];
    if (SHGetFolderPathAndSubDirA(NULL, CSIDL_COMMON_APPDATA, NULL, 0, "Roblox\\content\\", path) == S_OK)
        assetFolder = path;
    else
        StandardOut::singleton()->print(MESSAGE_WARNING, "Failed to get asset folder from registry");
}
} }

