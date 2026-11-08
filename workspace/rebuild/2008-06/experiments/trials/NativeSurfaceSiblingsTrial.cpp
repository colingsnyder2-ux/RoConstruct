#include "NativeSurfaceSiblingsTrial.h"
#include "StandardVerbs.h"
namespace RBX {
#define SURFACE_TOOL_FACTORY(Type) \
template<> MouseCommand* TToolVerb<Type, RunStateVerb>::newMouseCommand() { return new Type(dataModel->getWorkspace()); } \
void forceDestroy(Type* p) { delete p; }
SURFACE_TOOL_FACTORY(GlueTool)
SURFACE_TOOL_FACTORY(WeldTool)
SURFACE_TOOL_FACTORY(StudsTool)
SURFACE_TOOL_FACTORY(InletTool)
SURFACE_TOOL_FACTORY(HingeTool)
SURFACE_TOOL_FACTORY(RightMotorTool)
SURFACE_TOOL_FACTORY(LeftMotorTool)
SURFACE_TOOL_FACTORY(OscillateMotorTool)
SURFACE_TOOL_FACTORY(ModelSetFrontTool)
#undef SURFACE_TOOL_FACTORY
}
