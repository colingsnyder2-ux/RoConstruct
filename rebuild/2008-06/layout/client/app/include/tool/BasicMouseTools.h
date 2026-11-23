// =============================================================================
// BasicMouseTools.h
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/app/include/tool/BasicMouseTools.h
//
// Recovered from the shipped binary and tidied for this layout. Where this file
// is a compiled unit, its object is checked identical to the live recovery source
// (same compiler and flags). Not a source-only client, a server match or a runtime gate.
// Names or fields marked "// INFERRED:" are not in the binary and rest on stated evidence.
// Hex numbers in comments are addresses in the 2008-06 binary; more notes are in
// rebuild/2008-06/layout/evidence.json.
// =============================================================================

#pragma once

#include "v8datamodel/MouseCommand.h"
#include "v8datamodel/PartInstance.h"

namespace RBX
{
extern char sCloneTool[];
extern char sGameTool[];
extern char sGrabTool[];
extern char sHammerTool[];
extern char sLaserTool[];

class CloneTool : public Named<MouseCommand, sCloneTool> {
    boost::shared_ptr<PartInstance> partInstance;
    virtual MouseCommand* onMouseDown(const UIEvent&);
    virtual void onMouseIdle(const UIEvent&);
    virtual const std::string getCursorName() const;
public:
    CloneTool(Workspace*);
    virtual MouseCommand* isSticky() const;
};
typedef char CloneToolSize[sizeof(CloneTool) == 0x24 ? 1 : -1];

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
typedef char GrabToolSize[sizeof(GrabTool) == 0x38 ? 1 : -1];

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
typedef char HammerToolSize[sizeof(HammerTool) == 0x24 ? 1 : -1];

class LaserTool : public Named<MouseCommand, sLaserTool> {
    int frames;
    G3D::Vector3 origin, target;
    virtual MouseCommand* onMouseDown(const UIEvent&);
    virtual void render3dAdorn(Adorn*);
    virtual const std::string getCursorName() const;
public:
    LaserTool(Workspace* workspace) : Named<MouseCommand, sLaserTool>(workspace), frames(0), origin(0,0,0), target(0,0,0) {}
    virtual MouseCommand* isSticky() const;
};
typedef char LaserToolSize[sizeof(LaserTool) == 0x38 ? 1 : -1];
}
