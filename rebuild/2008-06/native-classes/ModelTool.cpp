// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include "tool/ModelTool.h"
#include "v8datamodel/Workspace.h"
#include "v8datamodel/PartInstance.h"

namespace RBX {
ModelTool::ModelTool(Workspace* workspace) : MouseCommand(workspace) {}

void ModelTool::onMouseHover(const UIEvent& input)
{
    if (PartInstance* part = getPart(input, NULL))
        target = shared_from(Workspace::findTopInstance(part));
    else
        target.reset();
}

// 0063dda0 (registry placeholder func_0063dda0; IRenderable-subobject slot 0x10 of the ModelTool vtable 0084a2c4 and of
// the AnchorTool / LockTool vtables 00839760 / 008397d8, between AnchorTool's applyAnchored 0063dd50 and
// getCursorName 0063dde0). this is the IRenderable subobject (+4), so [ecx+0x18] is target.px (+0x1c);
// __RTDynamicCast(Instance -> IRenderable), then render3dSelect (IRenderable slot 0x10) with selectState 0.
void ModelTool::render3dAdorn(Adorn* adorn)
{
    // Rejected: the dynamic_cast alone (no explicit target test) drops the original's leading null check (49 of 53 B).
    if (target)
        if (IRenderable* renderable = dynamic_cast<IRenderable*>(target.get()))
            renderable->render3dSelect(adorn, SELECT_NORMAL);
}
}
