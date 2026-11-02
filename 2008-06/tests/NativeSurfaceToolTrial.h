#pragma once
#include "v8datamodel/DataModel.h"
#include "v8datamodel/Workspace.h"
#include "v8datamodel/MouseCommand.h"
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
typedef char surface_size_check[sizeof(SurfaceTool)==0x48?1:-1];
}
