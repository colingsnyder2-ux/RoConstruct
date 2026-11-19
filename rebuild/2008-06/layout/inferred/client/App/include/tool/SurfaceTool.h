#pragma once

#include "v8datamodel/MouseCommand.h"
#include "v8datamodel/PartInstance.h"
#include "v8datamodel/Surface.h"

namespace RBX {
class SurfaceTool : public MouseCommand {
    boost::shared_ptr<PartInstance> partInstance;
    Surface* surface;
    int surfaceId;
    std::string cursor;
protected:
    virtual MouseCommand* onMouseDown(const UIEvent&);
    virtual void onMouseHover(const UIEvent&);
    virtual void render3dAdorn(Adorn*);
public:
    virtual void applyToSurface(Surface*) = 0;
    SurfaceTool(Workspace*);
};
typedef char SurfaceToolSize[sizeof(SurfaceTool) == 0x48 ? 1 : -1];
}
