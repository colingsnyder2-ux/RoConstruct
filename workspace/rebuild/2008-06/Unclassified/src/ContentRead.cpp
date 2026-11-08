// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
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
