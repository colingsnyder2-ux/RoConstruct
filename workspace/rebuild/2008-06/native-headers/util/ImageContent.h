#pragma once
#include <iosfwd>
#include "util/Name.h"

namespace RBX {
class ContentId;
const Name& getMimeType(const char*);
ContentId registerImageContent(std::istream&, const Name&);
std::string findHashFile(ContentId);
std::string findAsset(ContentId);
}
