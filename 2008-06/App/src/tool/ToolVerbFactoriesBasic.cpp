// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/mfc-noinline-pcxstr /I{headers}/std-noinline-string
// >>> native-status (generated) -- do not edit >>>
// ToolVerbFactoriesBasic | 2008-06 | inactive
// unmapped (no indexed address) | unmapped (no binary link) | by -
// <<< native-status | src 5a862aee | roc native-status --write
#undef _RELEASEASSERT
#include "v8datamodel/DataModel.h"
#include "v8datamodel/Workspace.h"
#include "tool/BasicMouseTools.h"
#include "tool/FlatTool.h"
#include "StandardVerbs.h"

namespace RBX {
template<> MouseCommand* TToolVerb<CloneTool, RunStateVerb>::newMouseCommand() { return new CloneTool(dataModel->getWorkspace()); }
template<> MouseCommand* TToolVerb<FlatTool, RunStateVerb>::newMouseCommand() { return new FlatTool(dataModel->getWorkspace()); }
template<> MouseCommand* TToolVerb<GameTool, RunStateVerb>::newMouseCommand() { return new GameTool(dataModel->getWorkspace()); }
template<> MouseCommand* TToolVerb<GrabTool, RunStateVerb>::newMouseCommand() { return new GrabTool(dataModel->getWorkspace()); }
template<> MouseCommand* TToolVerb<HammerTool, RunStateVerb>::newMouseCommand() { return new HammerTool(dataModel->getWorkspace()); }
template<> MouseCommand* TToolVerb<LaserTool, RunStateVerb>::newMouseCommand() { return new LaserTool(dataModel->getWorkspace()); }
}
