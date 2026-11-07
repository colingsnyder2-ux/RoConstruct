// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// >>> native-status (generated) -- do not edit >>>
// HttpTransport | 2008-06 | inactive
// unmapped (no binary link) | unmapped (no binary link) | by -
// <<< native-status | src 652e57a7 | roc native-status --write
#include "util/Http.h"
#include <sstream>

namespace RBX {
extern int httpTransportMode;

void Http::post(std::istream& input, bool compress, std::string& response)
{
    if (additionalHeaders.empty()) {
        if (httpTransportMode == 0) httpRequest(true, input, compress, NULL, response);
        else if (httpTransportMode == 1) httpRequestAlternate(true, input, compress, NULL, response);
    } else {
        const char* headers = additionalHeaders.c_str();
        if (httpTransportMode == 0) httpRequest(true, input, compress, headers, response);
        else if (httpTransportMode == 1) httpRequestAlternate(true, input, compress, headers, response);
    }
}

void Http::get(std::string& response)
{
    const char* headers = NULL;
    if (!additionalHeaders.empty()) headers = additionalHeaders.c_str();
    std::istringstream input;
    try {
        if (httpTransportMode == 0) httpRequest(false, input, false, headers, response);
        else if (httpTransportMode == 1) httpRequestAlternate(false, input, false, headers, response);
    } catch (...) {
        if (httpTransportMode == 0) httpRequest(false, input, false, headers, response);
        else if (httpTransportMode == 1) httpRequestAlternate(false, input, false, headers, response);
    }
}
}
