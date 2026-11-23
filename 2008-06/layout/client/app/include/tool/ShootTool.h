// =============================================================================
// ShootTool.h
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/app/include/tool/ShootTool.h
//
// Recovered from the shipped binary and tidied for this layout. Where this file
// is a compiled unit, its object is checked identical to the live recovery source
// (same compiler and flags). Not a source-only client, a server match or a runtime gate.
// Names or fields marked "// INFERRED:" are not in the binary and rest on stated evidence.
// Hex numbers in comments are addresses in the 2008-06 binary; more notes are in
// rebuild/2008-06/layout/evidence.json.
// =============================================================================

#pragma once

#include "v8datamodel/MouseCommand.h"
#include "v8datamodel/PartInstance.h"
#include "util/PV.h"

namespace RBX
{
class ShootTool : public MouseCommand {
    boost::shared_ptr<PartInstance> projectile;
    bool enabled;
    int delay;
    int remaining;
    void shoot(const UIEvent&);
protected:
    virtual MouseCommand* onMouseDown(const UIEvent&);
    virtual void onMouseIdle(const UIEvent&);
    virtual void onMouseMove(const UIEvent&);
    virtual MouseCommand* onMouseUp(const UIEvent&);
    virtual const std::string getCursorName() const;
    virtual boost::shared_ptr<PartInstance> createProjectile() = 0;
    virtual PV launch(const UIEvent&, const G3D::CoordinateFrame&) = 0;
    virtual int getShootSound() = 0;
public:
    __declspec(noinline) ShootTool(Workspace*, bool, int);
};
typedef char ShootToolSize[sizeof(ShootTool) == 0x30 ? 1 : -1];
}
