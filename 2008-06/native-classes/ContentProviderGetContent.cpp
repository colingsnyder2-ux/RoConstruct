// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include "util/NativeContentProvider.h"
#include <G3D/format.h>
#include <fstream>
#include <sstream>
#include <stdexcept>

namespace RBX {
std::auto_ptr<std::istream> ContentProvider::getContent(ContentId id)
{
    CachedContent* content = loadContent(id, 2, 0);
    if (!content)
        throw std::runtime_error(G3D::format("Unable to load %s", id.c_str()));
    if (content->data)
        return std::auto_ptr<std::istream>(new std::istringstream(*content->data, std::ios::in));
    return std::auto_ptr<std::istream>(new std::ifstream(content->filename->c_str(), std::ios::in | std::ios::binary));
}
}
