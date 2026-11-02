#include "NativeSurfaceSiblingsTrial.h"
#include "StandardVerbs.h"
namespace RBX {
template<> const Name& Named<SurfaceTool, &sHingeTool>::getName() const { return NativeToolName<HingeTool>::get(); }
template<> MouseCommand* TToolVerb<HingeTool, RunStateVerb>::newMouseCommand() { return new HingeTool(dataModel->getWorkspace()); }
}
