#pragma once
#include "v8datamodel/DataModel.h"
#include "v8datamodel/Workspace.h"
#include "tool/ToolsArrow.h"
#include "tool/MegaDragger.h"
#include "util/NormalId.h"
#include "G3D/Ray.h"
namespace RBX {
extern const char* sAxisMoveTool;
class AxisMoveTool : public Named<ArrowToolBase, &sAxisMoveTool> {
    std::auto_ptr<MegaDragger> megaDragger;
    std::string cursor;
    bool dragging;
    G3D::Vector2int16 mouseDownView;
    G3D::Ray dragRay;
    int axis;
    G3D::Vector3 dragPoint;
    bool bounds(Extents&);
    bool hitHandle(const UIEvent&, G3D::Vector3&, NormalId&);
    virtual MouseCommand* onMouseDown(const UIEvent&);
    virtual void onMouseMove(const UIEvent&);
    virtual MouseCommand* onMouseUp(const UIEvent&);
    virtual void onMouseIdle(const UIEvent&);
    virtual void render2d(Adorn*);
    virtual void render3dAdorn(Adorn*);
    virtual const std::string getCursorName() const { return cursor; }
public:
    AxisMoveTool(Workspace*);
    virtual MouseCommand* isSticky() const;
};
typedef char axis_size_check[sizeof(AxisMoveTool) == 0x74 ? 1 : -1];
}
