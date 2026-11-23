// =============================================================================
// SurfaceTools.h
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/app/include/tool/SurfaceTools.h
//
// Recovered from the shipped binary and tidied for this layout. Where this file
// is a compiled unit, its object is checked identical to the live recovery source
// (same compiler and flags). Not a source-only client, a server match or a runtime gate.
// Names or fields marked "// INFERRED:" are not in the binary and rest on stated evidence.
// Hex numbers in comments are addresses in the 2008-06 binary; more notes are in
// rebuild/2008-06/layout/evidence.json.
// =============================================================================

#pragma once

#include "tool/SurfaceTool.h"

namespace RBX
{
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
