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
}
