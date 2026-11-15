// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/slingshot-load
#include "util/NativeContentProvider.h"
namespace RBX {
ContentId ContentId::fromAssets(const char* path) {
 std::string prefix("rbxasset://");
 return ContentId(prefix + path);
}
}
