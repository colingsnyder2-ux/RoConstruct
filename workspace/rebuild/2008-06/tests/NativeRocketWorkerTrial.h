#pragma once
#include "NativeSlingshotWorkerTrial.h"
namespace RBX {
extern char sRocketTool[];
class RocketTool : public Named<ShootTool,sRocketTool> {
    virtual boost::shared_ptr<PartInstance> createProjectile();
    virtual PV launch(const UIEvent&,const G3D::CoordinateFrame&);
    virtual int getShootSound();
public:
    RocketTool(Workspace* w) : Named<ShootTool,sRocketTool>(w,false,90) {}
    virtual MouseCommand* isSticky() const;
};
typedef char rocket_size[sizeof(RocketTool)==0x30 ? 1 : -1];
}
