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

