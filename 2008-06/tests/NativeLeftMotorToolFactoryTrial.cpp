#include "NativeSurfaceSiblingsTrial.h"
#include "StandardVerbs.h"
namespace RBX {
template<> const Name& Named<SurfaceTool, &sLeftMotorTool>::getName() const { return NativeToolName<LeftMotorTool>::get(); }
template<> MouseCommand* TToolVerb<LeftMotorTool, RunStateVerb>::newMouseCommand() { return new LeftMotorTool(dataModel->getWorkspace()); }
}
