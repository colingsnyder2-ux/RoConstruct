#include "tool/GroupDragTool.h"
#include "v8datamodel/Workspace.h"
namespace RBX {
typedef char group_drag_size[(sizeof(GroupDragTool)==0x38)?1:-1];
GroupDragTool::GroupDragTool(PartInstance* mousePart, const G3D::Vector3&, const std::vector<boost::weak_ptr<PartInstance> >& parts, Workspace* workspace)
    : Named<MouseCommand, sGroupDragTool>(workspace), dragging(false) {
    megaDragger.reset(new MegaDragger(mousePart, parts, static_cast<RootInstance*>(workspace)));
}
GroupDragTool::~GroupDragTool() {}
}
