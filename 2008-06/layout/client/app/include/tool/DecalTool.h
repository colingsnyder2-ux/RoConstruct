// =============================================================================
// DecalTool.h
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/app/include/tool/DecalTool.h
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
#include "v8datamodel/Decal.h"

namespace RBX
{
extern char sDecalTool[];

class DecalTool : public Named<SurfaceTool, sDecalTool> {
    boost::shared_ptr<Decal> decal;
protected:
    virtual MouseCommand* onMouseDown(const UIEvent&);
    virtual MouseCommand* onKeyDown(const UIEvent&);
    virtual void onMouseMove(const UIEvent&);
    virtual const std::string getCursorName() const { return "ArrowCursorDecalDrag"; }  // 005a1ac0
public:
    virtual void applyToSurface(Surface*) {}
    DecalTool(Workspace* workspace, Decal* decal) : Named<SurfaceTool, sDecalTool>(workspace)
    {
        this->decal = shared_from(decal);
        capture();
    }
};
typedef char DecalToolSize[sizeof(DecalTool) == 0x50 ? 1 : -1];
}
