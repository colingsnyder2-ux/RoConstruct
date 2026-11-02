#include "NativeSurfaceSiblingsTrial.h"
#include "StandardVerbs.h"
namespace RBX {
template<> const Name& Named<SurfaceTool, &sInletTool>::getName() const { return NativeToolName<InletTool>::get(); }
template<> MouseCommand* TToolVerb<InletTool, RunStateVerb>::newMouseCommand() { return new InletTool(dataModel->getWorkspace()); }
}
