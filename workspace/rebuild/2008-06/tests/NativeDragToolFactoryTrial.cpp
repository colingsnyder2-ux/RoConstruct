#include "v8datamodel/MouseCommand.h"
#include "v8datamodel/PartInstance.h"
#include "tool/DragTool.h"
#include "tool/PartDragTool.h"
#include "tool/GroupDragTool.h"
#include <boost/weak_ptr.hpp>
#include <boost/shared_ptr.hpp>
#include <vector>
namespace RBX {
void __cdecl collectDragParts(const std::vector<Instance*>&, std::vector<boost::weak_ptr<PartInstance> >&);
MouseCommand* DragTool::onMouseDown(PartInstance* hitPart, const G3D::Vector3& hitWorld, const std::vector<Instance*>& instances, const UIEvent& input, Workspace* workspace, boost::shared_ptr<Instance> decal) {
    MouseCommand* result;
    {
    std::vector<boost::weak_ptr<PartInstance> > parts;
    collectDragParts(instances, parts);
    MouseCommand* command;
    if (parts.size() == 1) command = new PartDragTool(hitPart, hitWorld, workspace, decal);
    else command = new GroupDragTool(hitPart, hitWorld, parts, workspace);
    result = command->onMouseDown(input);
    }
    return result;
}
}
