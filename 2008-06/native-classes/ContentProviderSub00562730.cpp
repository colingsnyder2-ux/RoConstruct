// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: RBX::ContentProvider::sub_00562730 (placeholder name for 00562730 from the identity tier; body from assembly)
#include "util/NativeContentProvider.h"
#include <fstream>
#include <sstream>

namespace RBX {
// INFERRED: 0055f4f0 is an out-of-line stream copy helper (istream, ostream, chunk size); a boost iostreams copy, not recovered here
void __cdecl copyStream(std::istream& in, std::ostream& out, int chunk);

boost::shared_ptr<const std::string> ContentProvider::sub_00562730(const ContentId& id)
{
    CachedContent* content = loadContent(id, 1, NULL);
    if (!content)
        return boost::shared_ptr<const std::string>();
    boost::mutex::scoped_lock lock(contentCacheMutex);
    if (!content->data) {
        std::ifstream file(content->filename->c_str(), std::ios::in | std::ios::binary, _SH_DENYNO);
        std::ostringstream data(std::ios::out);
        copyStream(file, data, 0x1000);
        content->data.reset(new std::string(data.str()));
    }
    return content->data;
}
}
