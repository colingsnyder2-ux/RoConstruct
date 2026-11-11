// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/mfc-noinline-pcxstr /I{headers}/std-noinline-string
// >>> native-status (generated) -- do not edit >>>
// SurfaceTool | 2008-06 | draft (no current byte proof)
// 0/1 mapped addresses byte-exact | 1 unproved | no mapped strings | by king_originala (deepseek:deepseek-flash)
// <<< native-status | src 0567f138 | roc native-status --write
#include "tool/SurfaceTool.h"

namespace RBX {
SurfaceTool::SurfaceTool(Workspace* workspace) : MouseCommand(workspace), surface(NULL) {}
}
