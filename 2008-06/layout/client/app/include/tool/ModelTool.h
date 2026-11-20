#pragma once

#include "v8datamodel/MouseCommand.h"

namespace RBX {
class ModelTool : public MouseCommand {
protected:
    boost::shared_ptr<Instance> target;
    virtual void onMouseHover(const UIEvent&);
    // 0063dda0: IRenderable slot 3 of the ModelTool / AnchorTool / LockTool IRenderable vtables 0084a2c4 / 00839760 /
    // 008397d8 (shouldRender2d, shouldRender3dAdorn, render2d, then this body before render3dSelect).
    virtual void render3dAdorn(Adorn*);
public:
    ModelTool(Workspace*);
};
typedef char ModelToolSize[sizeof(ModelTool) == 0x24 ? 1 : -1];
}
