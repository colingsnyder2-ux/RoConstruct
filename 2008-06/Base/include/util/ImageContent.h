#pragma once
// >>> native-status (generated) -- do not edit >>>
// ImageContent | 2008-06 | inactive
// unmapped (no binary link) | unmapped (no binary link) | by -
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
