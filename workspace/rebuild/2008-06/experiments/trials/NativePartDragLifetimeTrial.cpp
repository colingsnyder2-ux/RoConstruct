#include "tool/PartDragTool.h"
#include "tool/RunDragger.h"
#include "tool/MegaDragger.h"
#include "v8datamodel/PartInstance.h"
#include "v8datamodel/Workspace.h"
namespace RBX {
typedef char part_drag_size[(sizeof(PartDragTool)==0x44)?1:-1];
PartDragTool::PartDragTool(PartInstance* part, const G3D::Vector3& point, Workspace* workspace, boost::shared_ptr<Instance> decal)
    : Named<MouseCommand, sPartDragTool>(workspace), dragDecal(decal), dragging(false), hitWorld(point) {
    runDragger.reset(new RunDragger);
    std::vector<PVInstance*> items;
    items.push_back(part);
    megaDragger.reset(new MegaDragger(part, items, static_cast<RootInstance*>(workspace)));
}
PartDragTool::~PartDragTool() {}
}
