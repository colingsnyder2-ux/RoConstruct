// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// >>> native-status (generated) -- do not edit >>>
// ContentProviderGetFile | 2008-06 | selection unverified
// unmapped (no indexed address) | by -
// <<< native-status | src d76583e2 | roc native-status --write
#include "util/NativeContentProvider.h"
#include <G3D/format.h>
#include <stdexcept>

namespace RBX {
std::string ContentProvider::getFile(ContentId ticket)
{
    CachedContent* content = loadContent(ticket, /* SyncHttpRequest */ 2, 0);
    if (content && registerFile(content))
        return *content->filename;
    throw std::runtime_error(G3D::format("Unable to load %s", ticket.c_str()));
}
}
