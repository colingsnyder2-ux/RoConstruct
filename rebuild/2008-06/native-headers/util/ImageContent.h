#pragma once
// >>> native-status (generated) -- do not edit >>>
// ImageContent | 2008-06 | draft (no current byte proof)
// no original address mapped to this file yet | by -
// <<< native-status | src 1ec73e6f | roc native-status --write
#include <iosfwd>
#include "util/Name.h"

namespace RBX {
class ContentId;
const Name& getMimeType(const char*);
ContentId registerImageContent(std::istream&, const Name&);
std::string findHashFile(ContentId);
std::string findAsset(ContentId);
}
