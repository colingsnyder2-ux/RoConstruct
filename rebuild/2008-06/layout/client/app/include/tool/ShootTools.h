// =============================================================================
// ShootTools.h
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/app/include/tool/ShootTools.h
//
// Recovered from the shipped binary and tidied for this layout. Where this file
// is a compiled unit, its object is checked identical to the live recovery source
// (same compiler and flags). Not a source-only client, a server match or a runtime gate.
// Names or fields marked "// INFERRED:" are not in the binary and rest on stated evidence.
// Hex numbers in comments are addresses in the 2008-06 binary; more notes are in
// rebuild/2008-06/layout/evidence.json.
// =============================================================================

#pragma once

#include "tool/ShootTool.h"

namespace RBX
{
extern char sRocketTool[];
extern char sSlingshotTool[];

class RocketTool : public Named<ShootTool, sRocketTool> {
    virtual boost::shared_ptr<PartInstance> createProjectile();
    virtual PV launch(const UIEvent&, const G3D::CoordinateFrame&);
    virtual int getShootSound();
public:
    RocketTool(Workspace* workspace) : Named<ShootTool, sRocketTool>(workspace, false, 90) {}
    virtual MouseCommand* isSticky() const;
};
typedef char RocketToolSize[sizeof(RocketTool) == 0x30 ? 1 : -1];

class SlingshotTool : public Named<ShootTool, sSlingshotTool> {
    virtual boost::shared_ptr<PartInstance> createProjectile();
    virtual PV launch(const UIEvent&, const G3D::CoordinateFrame&);
    virtual int getShootSound();
public:
    SlingshotTool(Workspace* workspace) : Named<ShootTool, sSlingshotTool>(workspace, true, 5) {}
    virtual MouseCommand* isSticky() const;
};
typedef char SlingshotToolSize[sizeof(SlingshotTool) == 0x30 ? 1 : -1];
}
