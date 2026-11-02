#include "NativeSurfaceSiblingsTrial.h"
#include "StandardVerbs.h"
namespace RBX {
template<> const Name& Named<SurfaceTool, sRightMotorTool>::getName() const { return NativeToolName<RightMotorTool>::get(); }
template<> MouseCommand* TToolVerb<RightMotorTool, RunStateVerb>::newMouseCommand() { return new RightMotorTool(dataModel->getWorkspace()); }
}
