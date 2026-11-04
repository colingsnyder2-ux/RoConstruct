// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/mfc-noinline-pcxstr /I{headers}/std-noinline-string
#include "tool/FlatTool.h"
#include "v8datamodel/Surface.h"
#include "v8datamodel/PartInstance.h"

namespace RBX {
const std::string FlatTool::getCursorName() const { return "FlatCursor"; }
MouseCommand* FlatTool::isSticky() const { return new FlatTool(workspace); }
void FlatTool::applyToSurface(Surface* surface) {
    surface->getPartInstance()->destroyJoints();
    surface->flat();
    surface->getPartInstance()->join();
}
}
