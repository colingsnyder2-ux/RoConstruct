#include "NativeSurfaceSiblingsTrial.h"
#include "StandardVerbs.h"
namespace RBX {
template<> const Name& Named<SurfaceTool, &sStudsTool>::getName() const { return NativeToolName<StudsTool>::get(); }
template<> MouseCommand* TToolVerb<StudsTool, RunStateVerb>::newMouseCommand() { return new StudsTool(dataModel->getWorkspace()); }
}
