// =============================================================================
// ModelTools.h
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/app/include/tool/ModelTools.h
//
// Recovered from the shipped binary and tidied for this layout. Where this file
// is a compiled unit, its object is checked identical to the live recovery source
// (same compiler and flags). Not a source-only client, a server match or a runtime gate.
// Names or fields marked "// INFERRED:" are not in the binary and rest on stated evidence.
// Hex numbers in comments are addresses in the 2008-06 binary; more notes are in
// rebuild/2008-06/layout/evidence.json.
// =============================================================================

#pragma once

#include "tool/ModelTool.h"

namespace RBX
{
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
