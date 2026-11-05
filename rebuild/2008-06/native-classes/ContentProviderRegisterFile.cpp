// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include "util/NativeContentProvider.h"
#include "util/ImageContent.h"
#include <sstream>

namespace RBX {
bool ContentProvider::registerFile(CachedContent* item)
{
    CachedContent temp;
    {
        boost::mutex::scoped_lock lock(contentCacheMutex);
        temp = *item;
    }
    if (!temp.filename) {
        std::istringstream stream(*temp.data);
        ContentId hash = registerImageContent(stream, Name::getNullName());
        std::string filename = findHashFile(hash);
        if (filename.empty()) return false;
        temp.filename.reset(new std::string(filename));
        boost::mutex::scoped_lock lock(contentCacheMutex);
        *item = temp;
    }
    return true;
}
}
