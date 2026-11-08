// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// >>> native-status (generated) -- do not edit >>>
// ContentRead | 2008-06 | selection unverified
// unmapped (no indexed address) | by -
// <<< native-status | src 715b6cb2 | roc native-status --write
#include "util/ContentRequest.h"
#include "util/StandardOut.h"
#include <sstream>

namespace RBX {
void readContent(RequestCallback callback, RequestResult result, boost::shared_ptr<const std::string> text)
{
    try {
        std::istringstream input(*text);
        callback(result, input);
    } catch (std::exception& error) {
        StandardOut::singleton()->print(MESSAGE_ERROR, "ContentProvider callback exception: %s", error.what());
    }
}
}
