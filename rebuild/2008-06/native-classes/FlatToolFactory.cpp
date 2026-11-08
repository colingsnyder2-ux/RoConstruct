// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/mfc-noinline-pcxstr /I{headers}/std-noinline-string
#undef _RELEASEASSERT
#include "v8datamodel/DataModel.h"
#include "v8datamodel/Workspace.h"
#include "tool/FlatTool.h"
#include "StandardVerbs.h"

namespace RBX {
template<> MouseCommand* TToolVerb<FlatTool, RunStateVerb>::newMouseCommand() {
    return new FlatTool(dataModel->getWorkspace());
}
template<> const Name& Named<SurfaceTool, sFlatTool>::getName() const {
    return NativeToolName<FlatTool>::get();
}
}
