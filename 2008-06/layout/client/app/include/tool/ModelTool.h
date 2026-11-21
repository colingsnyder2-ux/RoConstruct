#pragma once

#include "v8datamodel/MouseCommand.h"

namespace RBX {
class ModelTool : public MouseCommand {
protected:
    boost::shared_ptr<Instance> target;
    virtual void onMouseHover(const UIEvent&);
    virtual void render3dAdorn(Adorn*);
public:
    ModelTool(Workspace*);
};
typedef char ModelToolSize[sizeof(ModelTool) == 0x24 ? 1 : -1];
}
