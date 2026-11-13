// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/mfc-noinline-pcxstr /I{headers}/std-noinline-string
// >>> native-status (generated) -- do not edit >>>
// FlatTool | 2008-06 | draft (no current byte proof)
// 0/3 mapped addresses byte-exact | 3 unproved | no mapped strings | by colin (+1) (mixed 2)
// <<< native-status | src bd69f327 | roc native-status --write
#include "tool/FlatTool.h"
#include "v8datamodel/Surface.h"
#include "v8datamodel/PartInstance.h"
#include "v8datamodel/DataModel.h"
#include "v8datamodel/Workspace.h"
#include "StandardVerbs.h"

namespace RBX {
char sFlatTool[] = "FlatTool";
const std::string FlatTool::getCursorName() const { return "FlatCursor"; }
MouseCommand* FlatTool::isSticky() const { return new FlatTool(workspace); }
void FlatTool::applyToSurface(Surface* surface) {
    surface->getPartInstance()->destroyJoints();
    surface->flat();
    surface->getPartInstance()->join();
}
template<> MouseCommand* TToolVerb<FlatTool, RunStateVerb>::newMouseCommand() {
    return new FlatTool(dataModel->getWorkspace());
}
template<> const Name& Named<SurfaceTool, sFlatTool>::getName() const {
    return NativeToolName<FlatTool>::get();
}
}
