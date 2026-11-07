// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// >>> native-status (generated) -- do not edit >>>
// ImageContentRegistration | 2008-06 | inactive
// unmapped (no binary link) | unmapped (no binary link) | by -
// <<< native-status | src a15cc400 | roc native-status --write
#include <windows.h>
#include <atlbase.h>
#include <atlutil.h>
#include <fstream>
#include <boost/scoped_ptr.hpp>
#include "util/FileSystem.h"
#include "util/ContentProvider.h"
#include "util/ImageContent.h"

namespace RBX {
static ATL::CPath getLocalCachePath(bool createPath)
{
    ATL::CPath path;
    if (createPath) {
        static std::string cached = FileSystem::getCacheDirectory(true);
        path.m_strPath.SetString(cached.c_str());
    } else {
        static std::string cached = FileSystem::getCacheDirectory(false);
        path.m_strPath.SetString(cached.c_str());
    }
    return path;
}

ContentId registerImageContent(std::istream& content, const Name& mimeType)
{
    ContentId id;
    {
        boost::scoped_ptr<MD5Hasher> hasher(MD5Hasher::create());
        hasher->addData(content);
        id = ContentId(hasher->toString(), mimeType);
    }
    ATL::CPath filePath = getLocalCachePath(true);
    filePath.Append(id.c_str());
    if (!filePath.FileExists()) {
        std::ofstream output(filePath, std::ios::binary | std::ios::out);
        content.clear();
        content.seekg(0, std::ios::beg);
        do {
            char buffer[1024];
            content.read(buffer, sizeof(buffer));
            output.write(buffer, content.gcount());
        } while (content.gcount() > 0);
    }
    return id;
}
std::string findHashFile(ContentId contentId)
{
    ATL::CPath cachePath = getLocalCachePath(true);
    ATL::CPath filePath = cachePath;
    filePath.Append(contentId.c_str());
    if (!filePath.FileExists()) return "";
    return std::string(filePath);
}
namespace LDraw2Lua { std::string originalAssetFolder(); }

std::string findAsset(ContentId contentId)
{
    const char* suffix = contentId.c_str();
    suffix += 11;
    typedef std::string (__cdecl *Append)(const std::string&, const char*);
    Append append = &std::operator+<char, std::char_traits<char>, std::allocator<char> >;
    ATL::CPath path(append(LDraw2Lua::originalAssetFolder(), suffix).c_str());
    if (!path.FileExists()) return "";
    return std::string(path);
}
}
