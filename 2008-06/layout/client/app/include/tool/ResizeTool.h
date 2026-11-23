// =============================================================================
// ResizeTool.h
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/app/include/tool/ResizeTool.h
//
// Recovered from the shipped binary and tidied for this layout. Where this file
// is a compiled unit, its object is checked identical to the live recovery source
// (same compiler and flags). Not a source-only client, a server match or a runtime gate.
// Names or fields marked "// INFERRED:" are not in the binary and rest on stated evidence.
// Hex numbers in comments are addresses in the 2008-06 binary; more notes are in
// rebuild/2008-06/layout/evidence.json.
// =============================================================================

#pragma once

#include "v8datamodel/PVInstance.h"
#include "tool/ToolsArrow.h"
#include "util/NormalId.h"

namespace RBX
{
extern char sResizeTool[];
class ResizeTool : public Named<ArrowToolBase, sResizeTool> {
    boost::weak_ptr<PVInstance> targetPV;
    bool overHandle;
    NormalId localNormalId;
    G3D::Vector3 hitPointGrid;
    G3D::Vector2int16 down;
    int moveAxis;
    int movePerp;
    virtual MouseCommand* onMouseDown(const UIEvent&);
    virtual void onMouseMove(const UIEvent&);
    virtual MouseCommand* onMouseUp(const UIEvent&);
    virtual void onMouseHover(const UIEvent&);
    virtual void render2d(Adorn*);
    virtual void render3dAdorn(Adorn*);
    virtual const std::string getCursorName() const;
    void findTargetPV(const UIEvent&);
    void capturedDrag(int);
public:
    ResizeTool(Workspace*);
    virtual MouseCommand* isSticky() const;
};
typedef char ResizeToolSize[sizeof(ResizeTool) == 0x48 ? 1 : -1];
}
