// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/mfc-noinline-pcxstr /I{headers}/std-noinline-string
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
