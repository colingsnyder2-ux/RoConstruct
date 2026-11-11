// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// >>> native-status (generated) -- do not edit >>>
// PartTool | 2008-06 | draft (no current byte proof)
// 0/3 mapped addresses byte-exact | 3 unproved | no mapped strings | by colin (+1) (mixed 2)
// <<< native-status | src 8542623e | roc native-status --write
#include "v8datamodel/ToolsPart.h"

namespace RBX {
PartTool::PartTool(Workspace* workspace) : MouseCommand(workspace) {}
void PartTool::onMouseHover(const UIEvent& input)
{
    partInstance = shared_from(getPart(input, NULL));
}
void PartTool::render3dAdorn(Adorn* adorn)
{
    if (partInstance) partInstance->render3dSelect(adorn, SELECT_NORMAL);
}
}
