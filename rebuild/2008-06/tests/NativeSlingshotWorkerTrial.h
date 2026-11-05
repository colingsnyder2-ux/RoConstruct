#pragma once
#include "v8datamodel/DataModel.h"
#include "v8datamodel/Workspace.h"
#include "v8datamodel/MouseCommand.h"
#include "util/PV.h"
namespace RBX {
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
    virtual boost::shared_ptr<PartInstance> createProjectile()=0;
    virtual PV launch(const UIEvent&,const G3D::CoordinateFrame&)=0;
    virtual int getShootSound() = 0;
public:
    __declspec(noinline) ShootTool(Workspace*,bool,int);
};
extern char sSlingshotTool[];
class SlingshotTool : public Named<ShootTool,sSlingshotTool> {
    virtual boost::shared_ptr<PartInstance> createProjectile();
    virtual PV launch(const UIEvent&,const G3D::CoordinateFrame&);
    virtual int getShootSound();
public:
    SlingshotTool(Workspace* w) : Named<ShootTool,sSlingshotTool>(w,true,5) {}
    virtual MouseCommand* isSticky() const;
};
typedef char slingshot_size[sizeof(SlingshotTool)==0x30?1:-1];
}
