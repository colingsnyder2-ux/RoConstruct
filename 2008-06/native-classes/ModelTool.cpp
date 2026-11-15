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
}
