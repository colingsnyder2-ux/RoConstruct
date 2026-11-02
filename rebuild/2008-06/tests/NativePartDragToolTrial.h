#pragma once
#include "v8datamodel/MouseCommand.h"
#include <boost/shared_ptr.hpp>
#include <G3D/Vector2.h>
namespace RBX {
class Instance;
class RunDragger;
class MegaDragger;
extern const char* sPartDragTool;
class PartDragTool : public Named<MouseCommand, &sPartDragTool> {
    std::auto_ptr<RunDragger> runDragger;
    std::auto_ptr<MegaDragger> megaDragger;
    boost::shared_ptr<Instance> exeShared;
    G3D::Vector2 downPoint;
    bool dragging;
    G3D::Vector3 hitWorld;
public:
    virtual MouseCommand* onMouseDown(const UIEvent&);
    virtual void onMouseIdle(const UIEvent&);
    virtual void onMouseMove(const UIEvent&);
    virtual void onMouseDelta(const UIEvent&);
    virtual MouseCommand* onMouseUp(const UIEvent&);
    virtual MouseCommand* onKeyDown(const UIEvent&);
    virtual void render3dAdorn(Adorn*);
    virtual const std::string getCursorName() const { return dragging ? "GrabRotateCursor" : "DragCursor"; }
    PartDragTool(PartInstance*, const G3D::Vector3&, Workspace*, boost::shared_ptr<Instance>);
    virtual ~PartDragTool();
};
typedef char PartDragToolSize[sizeof(PartDragTool) == 0x44 ? 1 : -1];
}
