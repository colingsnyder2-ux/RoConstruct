// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include "tool/DragTool.h"
#include "tool/PartDragTool.h"
#include "tool/GroupDragTool.h"
#include "v8datamodel/PartInstance.h"
#include <boost/weak_ptr.hpp>

namespace RBX {
void collectDragParts(const std::vector<Instance*>&, std::vector<boost::weak_ptr<PartInstance> >&);

MouseCommand* DragTool::onMouseDown(PartInstance* hitPart, const G3D::Vector3& hitWorld,
    const std::vector<Instance*>& instances, const UIEvent& input, Workspace* workspace,
    boost::shared_ptr<Instance> decal)
{
    std::vector<boost::weak_ptr<PartInstance> > parts;
    collectDragParts(instances, parts);
    if (parts.size() == 1)
        return static_cast<MouseCommand*>(new PartDragTool(hitPart, hitWorld, workspace, decal))->onMouseDown(input);
    else
        return static_cast<MouseCommand*>(new GroupDragTool(hitPart, hitWorld, parts, workspace))->onMouseDown(input);
}
}
