#include "NativeSurfaceSiblingsTrial.h"
#include "StandardVerbs.h"
namespace RBX {
template<> const Name& Named<SurfaceTool, sWeldTool>::getName() const { return NativeToolName<WeldTool>::get(); }
template<> MouseCommand* TToolVerb<WeldTool, RunStateVerb>::newMouseCommand() { return new WeldTool(dataModel->getWorkspace()); }
}
