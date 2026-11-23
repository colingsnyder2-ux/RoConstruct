#pragma once

#include "tool/ModelTool.h"

namespace RBX {
extern char sAnchorTool[];
extern char sLockTool[];
class AnchorTool : public Named<ModelTool, sAnchorTool> {
    bool anchored;
    virtual const std::string getCursorName() const;
    virtual void onMouseHover(const UIEvent&);
    virtual MouseCommand* onMouseDown(const UIEvent&);
    // 005c72e0 (`mov eax, ecx; ret 4`): vftable slot 8 of AnchorTool 0083977c and of LockTool (ModelTool's own vftable
    // 0084a2e4 keeps MouseCommand::onMouseUp 005a0140); the 2007 openrbx tool/ToolsSurface.h has this inline override.
    virtual MouseCommand* onMouseUp(const UIEvent&) { return this; }
public:
    AnchorTool(Workspace* workspace) : Named<ModelTool, sAnchorTool>(workspace), anchored(false) {}
};
class LockTool : public Named<ModelTool, sLockTool> {
    virtual const std::string getCursorName() const;
    virtual MouseCommand* onMouseDown(const UIEvent&);
    // 005c72e0 (shared with AnchorTool, slot 8 of the LockTool vftable; openrbx tool/ToolsSurface.h inline override).
    virtual MouseCommand* onMouseUp(const UIEvent&) { return this; }
public:
    LockTool(Workspace* workspace) : Named<ModelTool, sLockTool>(workspace) {}
};
typedef char AnchorToolSize[sizeof(AnchorTool) == 0x28 ? 1 : -1];
typedef char LockToolSize[sizeof(LockTool) == 0x24 ? 1 : -1];
}
