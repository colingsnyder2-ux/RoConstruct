// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// >>> native-status (generated) -- do not edit >>>
// ModelTool | 2008-06 | draft (no current byte proof)
// 0/1 mapped addresses byte-exact | 1 unproved | no mapped strings | by colin (chatgpt:gpt-6.1-sol)
// <<< native-status | src dfba5308 | roc native-status --write
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
}
