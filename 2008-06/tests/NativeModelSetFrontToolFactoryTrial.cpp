#include "NativeSurfaceSiblingsTrial.h"
#include "StandardVerbs.h"
namespace RBX {
template<> const Name& Named<SurfaceTool, &sModelSetFrontTool>::getName() const { return NativeToolName<ModelSetFrontTool>::get(); }
template<> MouseCommand* TToolVerb<ModelSetFrontTool, RunStateVerb>::newMouseCommand() { return new ModelSetFrontTool(dataModel->getWorkspace()); }
}
