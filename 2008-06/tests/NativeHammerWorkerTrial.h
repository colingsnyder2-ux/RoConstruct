#pragma once
#include "v8datamodel/DataModel.h"
#include "v8datamodel/Workspace.h"
#include "v8datamodel/MouseCommand.h"
namespace RBX {
extern char sHammerTool[];
class HammerTool : public Named<MouseCommand, sHammerTool> {
    boost::shared_ptr<PartInstance> partInstance;
    virtual MouseCommand* onMouseDown(const UIEvent&);
    virtual void onMouseIdle(const UIEvent&);
    virtual void render3dAdorn(Adorn*);
    virtual const std::string getCursorName() const;
public:
    HammerTool(Workspace* workspace) : Named<MouseCommand, sHammerTool>(workspace) {}
    virtual MouseCommand* isSticky() const;
};
typedef char hammer_size[sizeof(HammerTool)==0x24?1:-1];
}
