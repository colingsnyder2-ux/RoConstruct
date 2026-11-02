#pragma once
#include "v8datamodel/DataModel.h"
#include "v8datamodel/Workspace.h"
#include "v8datamodel/MouseCommand.h"
namespace RBX {
extern char sCloneTool[];
class CloneTool : public Named<MouseCommand, sCloneTool> {
    boost::shared_ptr<PartInstance> partInstance;
    virtual MouseCommand* onMouseDown(const UIEvent&);
    virtual void onMouseIdle(const UIEvent&);
    virtual const std::string getCursorName() const;
public:
    __declspec(noinline) CloneTool(Workspace*);
    virtual MouseCommand* isSticky() const;
};
typedef char clone_size[sizeof(CloneTool)==0x24?1:-1];
}

