// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <string>
#include <boost/thread/once.hpp>

namespace RBX { namespace LDraw2Lua {
extern boost::once_flag assetFolderOnce;
extern std::string assetFolder;
void initializeAssetFolder();

std::string originalAssetFolder()
{
    boost::call_once(&initializeAssetFolder, assetFolderOnce);
    return assetFolder;
}

std::string resolveMapPath(const char* path)
{
    typedef std::string (__cdecl *Append)(const std::string&, const char*);
    Append append = &std::operator+<char, std::char_traits<char>, std::allocator<char> >;
    return static_cast<const std::string&>(append(originalAssetFolder(), path));
}
} }
