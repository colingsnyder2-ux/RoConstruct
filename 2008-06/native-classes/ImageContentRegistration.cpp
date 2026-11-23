// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
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

// 0055fa70 (registry placeholder func_0055fa70; cdecl, no this; only caller the CApp COM method at 00406260 after
// AFX_MANAGE_STATE). INFERRED name after the 2007 OpenRBX ContentProvider::clearFileCache (a free function here, like
// the unit's other 2008 members getLocalCachePath 0055f940 / registerImageContent 0055fbc0). Evidence:
// getLocalCachePath(false), CStringT != "" through _mbscmp with "" 0080b716, FindFirstFile(path + "*.*" 008104dc)
// with the out-of-line CStringT operator+(const CStringT&, PCXSTR) 0055de10 (Concatenate 0055d840), then
// DeleteFile(path + cFileName) for every non-directory entry.
void clearFileCache()
{
    ATL::CPath path = getLocalCachePath(false);
    if (path.m_strPath != "") {
        WIN32_FIND_DATA FindFileData;
        HANDLE hFind = FindFirstFile(path.m_strPath + "*.*", &FindFileData);
        if (hFind != INVALID_HANDLE_VALUE) {
            do {
                if (!(FindFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY))
                    DeleteFile(path.m_strPath + FindFileData.cFileName);
            } while (FindNextFile(hFind, &FindFileData));
        }
    }
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

// Template members emitted by this unit (bodies byte-identical to the 2008-06 client).
template class boost::scoped_ptr<RBX::MD5Hasher>;
