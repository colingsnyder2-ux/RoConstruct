// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/slingshot-load
// >>> native-status (generated) -- do not edit >>>
// ContentIdAssets | 2008-06 | draft (no current byte proof)
// 0/2 mapped addresses byte-exact | 2 unproved | 1 referenced strings (not rechecked) | by king_originala (+1) (deepseek:deepseek-flash)
// <<< native-status | src f75c04c7 | roc native-status --write
#include "util/NativeContentProvider.h"
namespace RBX {
ContentId ContentId::fromAssets(const char* path) {
 std::string prefix("rbxasset://");
 return ContentId(prefix + path);
}
}
