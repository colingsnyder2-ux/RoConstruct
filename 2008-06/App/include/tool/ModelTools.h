#pragma once
// >>> native-status (generated) -- do not edit >>>
// ModelTools | 2008-06 | inactive
// unmapped (no indexed address) | unmapped (no binary link) | by -
// <<< native-status | src 4240446e | roc native-status --write

#include "tool/ModelTool.h"

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
typedef char AnchorToolSize[sizeof(AnchorTool) == 0x28 ? 1 : -1];
typedef char LockToolSize[sizeof(LockTool) == 0x24 ? 1 : -1];
}
