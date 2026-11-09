#pragma once
#include "v8datamodel/MouseCommand.h"
namespace RBX {
extern char sGameTool[];
class GameTool : public Named<MouseCommand, sGameTool> {
    std::string cursor;
    bool canDrag(PartInstance*, const G3D::Vector3&);
    virtual MouseCommand* onMouseDown(const UIEvent&);
    virtual void onMouseIdle(const UIEvent&);
    virtual void onMouseHover(const UIEvent&);
    virtual const std::string getCursorName() const { return cursor; }
public:
    GameTool(Workspace*);
    virtual ~GameTool();
    virtual MouseCommand* isSticky() const;
};
typedef char GameToolSize[sizeof(GameTool) == 0x38 ? 1 : -1];
}
