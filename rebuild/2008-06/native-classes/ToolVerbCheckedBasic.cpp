// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/mfc-noinline-pcxstr /I{headers}/std-noinline-string
// >>> native-status (generated) -- do not edit >>>
// ToolVerbCheckedBasic | 2008-06 | selection unverified
// unmapped (no binary link) | by -
// <<< native-status | src 90de1b6a | roc native-status --write
#undef _RELEASEASSERT
#include "v8datamodel/DataModel.h"
#include "v8datamodel/Workspace.h"
#include "tool/BasicMouseTools.h"
#include "tool/FlatTool.h"
#include "StandardVerbs.h"
#include <typeinfo>

namespace RBX {
template<class Tool, class Base> bool TToolVerb<Tool, Base>::isChecked() const {
    MouseCommand* command = dataModel->getWorkspace()->getCurrentMouseCommand();
    if (command) return typeid(Tool) == typeid(*command);
    return false;
}
template bool TToolVerb<CloneTool, RunStateVerb>::isChecked() const;
template bool TToolVerb<FlatTool, RunStateVerb>::isChecked() const;
template bool TToolVerb<GameTool, RunStateVerb>::isChecked() const;
template bool TToolVerb<GrabTool, RunStateVerb>::isChecked() const;
template bool TToolVerb<HammerTool, RunStateVerb>::isChecked() const;
template bool TToolVerb<LaserTool, RunStateVerb>::isChecked() const;
}
