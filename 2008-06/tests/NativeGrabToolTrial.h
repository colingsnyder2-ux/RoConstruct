#pragma once
#include "v8datamodel/DataModel.h"
#include "v8datamodel/Workspace.h"
#include "v8datamodel/MouseCommand.h"
namespace RBX {
extern char sGrabTool[];
class GrabTool : public Named<MouseCommand, sGrabTool> {
    std::string cursor;
    virtual MouseCommand* onMouseDown(const UIEvent&);
    virtual void onMouseIdle(const UIEvent&);
    virtual void onMouseHover(const UIEvent&);
    virtual const std::string getCursorName() const { return cursor; }
public:
    __declspec(noinline) GrabTool(Workspace*);
    virtual ~GrabTool();
    virtual MouseCommand* isSticky() const;
};
typedef char grab_size[sizeof(GrabTool)==0x38?1:-1];
}
