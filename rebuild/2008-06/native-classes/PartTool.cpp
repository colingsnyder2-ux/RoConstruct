// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include "v8datamodel/ToolsPart.h"

namespace RBX {
PartTool::PartTool(Workspace* workspace) : MouseCommand(workspace) {}
void PartTool::onMouseHover(const RBX::UIEvent& input)
{
    partInstance = RBX::shared_from<RBX::PartInstance>(getPart(input, NULL));
}
void PartTool::render3dAdorn(Adorn* adorn)
{
    if (partInstance) partInstance->render3dSelect(adorn, SELECT_NORMAL);
}
}
