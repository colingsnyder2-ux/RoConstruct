#pragma once
// >>> native-status (generated) -- do not edit >>>
// ShootTools | 2008-06 | selection unverified
// unmapped (no binary link) | by -
// <<< native-status | src 29459a8e | roc native-status --write

#include "tool/ShootTool.h"

namespace RBX {
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
