// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/slingshot-load
// >>> native-status (generated) -- do not edit >>>
// ContentIdAssets | 2008-06 | inactive
// unmapped (no indexed address) | unmapped (no binary link) | by -
// <<< native-status | src f75c04c7 | roc native-status --write
#include "util/NativeContentProvider.h"
namespace RBX {
ContentId ContentId::fromAssets(const char* path) {
 std::string prefix("rbxasset://");
 return ContentId(prefix + path);
}
}
