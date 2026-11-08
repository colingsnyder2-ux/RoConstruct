// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include "tool/NullTool.h"
#include "StandardVerbs.h"

namespace RBX {
char sNullTool[] = "NullTool";
NullTool::NullTool(Workspace* workspace) : Named<MouseCommand, sNullTool>(workspace) {}
NullTool::~NullTool() {}

const std::string NullTool::getCursorName() const { return "ArrowFarCursor"; }
MouseCommand* NullTool::isSticky() const { return new NullTool(workspace); }
MouseCommand* NullTool::onMouseUp(const UIEvent&)
{
    releaseCapture();
    return this;
}

template<> const Name& Named<MouseCommand, sNullTool>::getName() const
{
    return NativeToolName<NullTool>::get();
}
template<> MouseCommand* TToolVerb<NullTool, RunStateVerb>::newMouseCommand()
{
    return new NullTool(dataModel->getWorkspace());
}
}
