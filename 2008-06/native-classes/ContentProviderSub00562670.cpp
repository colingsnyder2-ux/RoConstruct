// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: RBX::ContentProvider::sub_00562670 (placeholder name for 00562670 from the identity tier; body from assembly)
#include "util/NativeContentProvider.h"
#include <fstream>
#include <sstream>

namespace RBX {
void ContentProvider::sub_00562670(const ContentId& id, RequestResult& result, std::string& filename)
{
    CachedContent* content = loadContent(id, 1, NULL);
    if (!content) {
        if (id.isHttp() && !isUrlBad(id.c_str())) {
            result = (RequestResult)0;
            return;
        }
        result = (RequestResult)2;
        return;
    }
    if (!registerFile(content)) {
        result = (RequestResult)2;
        return;
    }
    filename = *content->filename;
    result = (RequestResult)1;
}
}
