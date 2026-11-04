#pragma once

#include "v8datamodel/PVInstance.h"
#include "tool/ToolsArrow.h"
#include "util/NormalId.h"

namespace RBX {
extern char sResizeTool[];
class ResizeTool : public Named<ArrowToolBase, sResizeTool> {
    boost::weak_ptr<PVInstance> targetPV;
    bool overHandle;
    NormalId localNormalId;
    G3D::Vector3 hitPointGrid;
    G3D::Vector2int16 down;
    int moveAxis;
    int movePerp;
    virtual MouseCommand* onMouseDown(const UIEvent&);
    virtual void onMouseMove(const UIEvent&);
    virtual MouseCommand* onMouseUp(const UIEvent&);
    virtual void onMouseHover(const UIEvent&);
    virtual void render2d(Adorn*);
    virtual void render3dAdorn(Adorn*);
    virtual const std::string getCursorName() const;
    void findTargetPV(const UIEvent&);
    void capturedDrag(int);
public:
    ResizeTool(Workspace*);
    virtual MouseCommand* isSticky() const;
};
typedef char ResizeToolSize[sizeof(ResizeTool) == 0x48 ? 1 : -1];
}
