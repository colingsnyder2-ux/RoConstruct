// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include "tool/BasicMouseTools.h"
#include "tool/DragTool.h"
#include "v8datamodel/Workspace.h"
#include "v8datamodel/DataModel.h"
#include "StandardVerbs.h"

namespace RBX {
char sGrabTool[] = "Grab";
GrabTool::GrabTool(Workspace* workspace)
    : Named<MouseCommand, sGrabTool>(workspace), cursor("ArrowCursor") {}
GrabTool::~GrabTool() {}

void GrabTool::onMouseIdle(const UIEvent& input) { onMouseHover(input); }

void GrabTool::onMouseHover(const UIEvent& input)
{
    PartInstance* part = getUnlockedPartByLocalCharacter(input);
    if (!part) cursor = "ArrowFarCursor";
    else if (part->getPartLocked()) cursor = "ArrowCursor";
    else cursor = "DragCursor";
}

MouseCommand* GrabTool::onMouseDown(const UIEvent& input)
{
    G3D::Vector3 point;
    PartInstance* part = getUnlockedPartByLocalCharacter(input, point);
    if (part) {
        std::vector<Instance*> dragInstances;
        dragInstances.push_back(getTopSelectable3d(part));
        return DragTool::onMouseDown(part, point, dragInstances, input, workspace,
                                     boost::shared_ptr<Instance>());
    }
    return NULL;
}

MouseCommand* GrabTool::isSticky() const { return new GrabTool(workspace); }

template<> const Name& Named<MouseCommand, sGrabTool>::getName() const
{
    return NativeToolName<GrabTool>::get();
}
template<> MouseCommand* TToolVerb<GrabTool, RunStateVerb>::newMouseCommand()
{
    return new GrabTool(dataModel->getWorkspace());
}
}

// Template members emitted by this unit (bodies byte-identical to the 2008-06 client).
template class std::_Container_base_aux_alloc_real<std::allocator<RBX::Instance *> >;
template class std::_Vector_const_iterator<RBX::Instance *,std::allocator<RBX::Instance *> >;
template class std::_Vector_iterator<RBX::Instance *,std::allocator<RBX::Instance *> >;
