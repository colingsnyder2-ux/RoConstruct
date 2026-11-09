#pragma once
#include "NativeSurfaceToolTrial.h"
namespace RBX {
#define SURFACE_TOOL_DECL(Type) \
extern char s##Type[]; \
class Type : public Named<SurfaceTool, s##Type> { \
    virtual const std::string getCursorName() const; \
    virtual void applyToSurface(Surface*); \
public: \
    Type(Workspace* workspace) : Named<SurfaceTool, s##Type>(workspace) {} \
    virtual MouseCommand* isSticky() const; \
}; \
typedef char Type##SizeCheck[sizeof(Type)==0x48?1:-1];
SURFACE_TOOL_DECL(GlueTool)
SURFACE_TOOL_DECL(WeldTool)
SURFACE_TOOL_DECL(StudsTool)
SURFACE_TOOL_DECL(InletTool)
SURFACE_TOOL_DECL(HingeTool)
SURFACE_TOOL_DECL(RightMotorTool)
SURFACE_TOOL_DECL(LeftMotorTool)
SURFACE_TOOL_DECL(OscillateMotorTool)
SURFACE_TOOL_DECL(ModelSetFrontTool)
#undef SURFACE_TOOL_DECL
}
