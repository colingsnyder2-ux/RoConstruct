#include "NativeSurfaceSiblingsTrial.h"
#include "StandardVerbs.h"
namespace RBX {
template<> const Name& Named<SurfaceTool, sOscillateMotorTool>::getName() const { return NativeToolName<OscillateMotorTool>::get(); }
template<> MouseCommand* TToolVerb<OscillateMotorTool, RunStateVerb>::newMouseCommand() { return new OscillateMotorTool(dataModel->getWorkspace()); }
}
