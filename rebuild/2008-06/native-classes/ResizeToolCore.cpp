// >>> native-status (generated) -- do not edit >>>
// ResizeToolCore | 2008-06 | 1 byte-exact, inactive (not link-selected)
// 1/1 mapped addresses byte-exact | 0 unproved | no mapped strings | by king_originala (chatgpt:gpt-6.1-sol)
// <<< native-status | src dd8a41e2 | roc native-status --write
#include "v8datamodel/DataModel.h"
#include "v8datamodel/Workspace.h"
#include "tool/ResizeTool.h"
#include "StandardVerbs.h"
namespace RBX {
char sResizeTool[] = "Resize";
ResizeTool::ResizeTool(Workspace* w) : Named<ArrowToolBase, sResizeTool>(w), overHandle(false), moveAxis(0), movePerp(0) {}

template<> MouseCommand* TToolVerb<ResizeTool, RunStateVerb>::newMouseCommand() {
    return new ResizeTool(dataModel->getWorkspace());
}

template<> const Name& Named<ArrowToolBase, sResizeTool>::getName() const {
    return NativeToolName<ResizeTool>::get();
}
}
