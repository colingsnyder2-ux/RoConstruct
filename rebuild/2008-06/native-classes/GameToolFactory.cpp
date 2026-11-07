// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// >>> native-status (generated) -- do not edit >>>
// GameToolFactory | 2008-06 | inactive
// unmapped (no binary link) | by -
// <<< native-status | src 28ee0e00 | roc native-status --write
#include "v8datamodel/DataModel.h"
#include "tool/BasicMouseTools.h"
#include "StandardVerbs.h"

namespace RBX {
template<> MouseCommand* TToolVerb<GameTool, RunStateVerb>::newMouseCommand()
{
    return new GameTool(dataModel->getWorkspace());
}
}
