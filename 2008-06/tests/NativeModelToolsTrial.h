#pragma once
#include "NativeModelToolTrial.h"
namespace RBX {
extern char sAnchorTool[];
extern char sLockTool[];
class AnchorTool : public Named<ModelTool, sAnchorTool> {
    bool anchored;
    virtual const std::string getCursorName() const;
    virtual void onMouseHover(const UIEvent&);
    virtual MouseCommand* onMouseDown(const UIEvent&);
public:
    AnchorTool(Workspace* workspace) : Named<ModelTool, sAnchorTool>(workspace), anchored(false) {}
};
class LockTool : public Named<ModelTool, sLockTool> {
    virtual const std::string getCursorName() const;
    virtual MouseCommand* onMouseDown(const UIEvent&);
public:
    LockTool(Workspace* workspace) : Named<ModelTool, sLockTool>(workspace) {}
};
typedef char anchor_size[sizeof(AnchorTool)==0x28?1:-1];
typedef char lock_size[sizeof(LockTool)==0x24?1:-1];
}
