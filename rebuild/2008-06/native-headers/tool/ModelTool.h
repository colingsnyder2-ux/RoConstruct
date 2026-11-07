#pragma once
// >>> native-status (generated) -- do not edit >>>
// ModelTool | 2008-06 | inactive
// unmapped (no binary link) | by -
// <<< native-status | src ae65949a | roc native-status --write

#include "v8datamodel/MouseCommand.h"

namespace RBX {
class ModelTool : public MouseCommand {
protected:
    boost::shared_ptr<Instance> target;
    virtual void onMouseHover(const UIEvent&);
public:
    ModelTool(Workspace*);
};
typedef char ModelToolSize[sizeof(ModelTool) == 0x24 ? 1 : -1];
}
