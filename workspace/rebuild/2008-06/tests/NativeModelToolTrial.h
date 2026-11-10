#pragma once
#include "v8datamodel/DataModel.h"
#include "v8datamodel/Workspace.h"
#include "v8datamodel/MouseCommand.h"
namespace RBX {
class ModelTool : public MouseCommand {
protected:
    boost::shared_ptr<Instance> target;
    virtual void onMouseHover(const UIEvent&);
public:
    ModelTool(Workspace*);
};
typedef char model_tool_size[sizeof(ModelTool)==0x24?1:-1];
}
