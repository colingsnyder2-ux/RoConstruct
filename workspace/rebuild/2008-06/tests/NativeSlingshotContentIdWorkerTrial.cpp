#include "util/ContentProvider.h"
namespace RBX {
ContentId ContentId::fromAssets(const char* path) {
 std::string prefix("rbxasset://");
 return ContentId(prefix + path);
}
}
