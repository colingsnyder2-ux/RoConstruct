#pragma once
// >>> native-status (generated) -- do not edit >>>
// AxisMoveTool | 2008-06 | inactive
// unmapped (no binary link) | unmapped (no binary link) | by -
// <<< native-status | src 1ae357f2 | roc native-status --write

#include <memory>
#include <G3D/Ray.h>
#include "tool/ToolsArrow.h"
#include "util/NormalId.h"

namespace RBX {
class MegaDragger;
class Extents;
extern char sAxisMoveTool[];

class AxisMoveTool : public Named<ArrowToolBase, sAxisMoveTool> {
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
typedef char AxisMoveToolSize[sizeof(AxisMoveTool) == 0x74 ? 1 : -1];
}
