#pragma once
// >>> native-status (generated) -- do not edit >>>
// SurfaceTools | 2008-06 | inactive
// unmapped (no indexed address) | unmapped (no binary link) | by -
// <<< native-status | src f4e22179 | roc native-status --write

#include "tool/SurfaceTool.h"

namespace RBX {
#define RBX_SURFACE_TOOL(Type) \
extern char s##Type[]; \
class Type : public Named<SurfaceTool, s##Type> { \
    virtual const std::string getCursorName() const; \
    virtual void applyToSurface(Surface*); \
public: \
    Type(Workspace* workspace) : Named<SurfaceTool, s##Type>(workspace) {} \
    virtual MouseCommand* isSticky() const; \
}; \
typedef char Type##Size[sizeof(Type) == 0x48 ? 1 : -1];
RBX_SURFACE_TOOL(GlueTool)
RBX_SURFACE_TOOL(WeldTool)
RBX_SURFACE_TOOL(StudsTool)
RBX_SURFACE_TOOL(InletTool)
RBX_SURFACE_TOOL(HingeTool)
RBX_SURFACE_TOOL(RightMotorTool)
RBX_SURFACE_TOOL(LeftMotorTool)
RBX_SURFACE_TOOL(OscillateMotorTool)
RBX_SURFACE_TOOL(ModelSetFrontTool)
#undef RBX_SURFACE_TOOL
}
