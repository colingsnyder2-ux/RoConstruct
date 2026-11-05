// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/mfc-noinline-pcxstr /I{headers}/std-noinline-string
#include "tool/SurfaceTool.h"

namespace RBX {
SurfaceTool::SurfaceTool(Workspace* workspace) : MouseCommand(workspace), surface(NULL) {}
}
