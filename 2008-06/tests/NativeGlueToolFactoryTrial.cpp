#include "NativeSurfaceSiblingsTrial.h"
#include "StandardVerbs.h"
namespace RBX {
template<> const Name& Named<SurfaceTool, &sGlueTool>::getName() const { return NativeToolName<GlueTool>::get(); }
template<> MouseCommand* TToolVerb<GlueTool, RunStateVerb>::newMouseCommand() { return new GlueTool(dataModel->getWorkspace()); }
}
