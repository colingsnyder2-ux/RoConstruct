#pragma once

#include "tool/SurfaceTool.h"
#include "v8datamodel/Decal.h"

namespace RBX {
extern char sDecalTool[];

// RBX::DecalTool (RTTI .?AVDecalTool@RBX@@ 0094be24 with base Named<SurfaceTool, sDecalTool> 0094bdc0; vtables
// 0083387c INamed / 00833860 IRenderable, both stored by the 0x50-byte ctor 005a19f0 that Workspace::startDecalDrag
// 005a3d40 news). Layout from that ctor: SurfaceTool (0x48) then the dragged decal shared_ptr at +0x48 / +0x4c.
// INamed slots: getName 005a1810, onMouseDown 00619a80, onMouseHover = SurfaceTool 00619e50, onKeyDown 00619d00,
// onMouseMove 00619c90, dtor 005a1b70, getCursorName 005a1ac0 ("ArrowCursorDecalDrag" 008338c0), and an empty
// applyToSurface (0070bdf0, the shared empty void(arg) body). The IRenderable side keeps SurfaceTool::render3dAdorn.
class DecalTool : public Named<SurfaceTool, sDecalTool> {
    boost::shared_ptr<Decal> decal;
protected:
    virtual MouseCommand* onMouseDown(const UIEvent&);
    virtual MouseCommand* onKeyDown(const UIEvent&);
    virtual void onMouseMove(const UIEvent&);
    virtual const std::string getCursorName() const { return "ArrowCursorDecalDrag"; }  // 005a1ac0
public:
    virtual void applyToSurface(Surface*) {}
    // 005a19f0 (emitted in the Workspace unit): default-constructed decal, then assigned shared_from(decal)
    // (shared_count assignment 004025b0), then capture() (00615820).
    DecalTool(Workspace* workspace, Decal* decal) : Named<SurfaceTool, sDecalTool>(workspace)
    {
        this->decal = shared_from(decal);
        capture();
    }
};
typedef char DecalToolSize[sizeof(DecalTool) == 0x50 ? 1 : -1];
}
