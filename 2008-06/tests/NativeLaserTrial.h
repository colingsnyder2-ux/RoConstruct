#pragma once
#include "v8datamodel/DataModel.h"
#include "v8datamodel/Workspace.h"
#include "v8datamodel/MouseCommand.h"
namespace RBX {
extern char sLaserTool[];
class LaserTool : public Named<MouseCommand, sLaserTool> {
    int frames;
    G3D::Vector3 origin, target;
    virtual MouseCommand* onMouseDown(const UIEvent&);
    virtual void render3dAdorn(Adorn*);
    virtual const std::string getCursorName() const;
public:
    LaserTool(Workspace* workspace) : Named<MouseCommand, sLaserTool>(workspace), frames(0), origin(0,0,0), target(0,0,0) {}
    virtual MouseCommand* isSticky() const;
};
typedef char laser_size[sizeof(LaserTool)==0x38?1:-1];
}
