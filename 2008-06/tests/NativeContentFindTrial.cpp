#define NATIVE_CONTENT_PROVIDER_TYPES_ONLY
#include "NativeContentProviderTrial.cpp"
#include "util/FileSystem.h"
#include <atlutil.h>
namespace RBX {
namespace LDraw2Lua { std::string originalAssetFolder(); }
std::string nativeFindAsset(ContentId id)
{
    typedef std::string (__cdecl *Append)(const std::string&, const char*);
    Append append = &std::operator+<char, std::char_traits<char>, std::allocator<char> >;
    const char* suffix = id.c_str();
    suffix += 11;
    ATL::CPath path(static_cast<const std::string&>(append(LDraw2Lua::originalAssetFolder(), suffix)).c_str());
    if (!path.FileExists()) return "";
    return std::string(path);
}
static ATL::CPath nativeGetLocalCachePath(bool createPath)
{
    ATL::CPath path;
    if (createPath) {
        static std::string s = FileSystem::getCacheDirectory(true);
        path.m_strPath.SetString(s.c_str());
    } else {
        static std::string s = FileSystem::getCacheDirectory(false);
        path.m_strPath.SetString(s.c_str());
    }
    return path;
}
std::string nativeFindHashFile(ContentId id)
{
    ATL::CPath cachePath = nativeGetLocalCachePath(true);
    ATL::CPath filePath = cachePath;
    filePath.Append(id.c_str());
    if (!filePath.FileExists()) return "";
    return std::string(filePath);
}
}
