// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// >>> native-status (generated) -- do not edit >>>
// CloneToolFactory | 2008-06 | inactive
// unmapped (no indexed address) | unmapped (no binary link) | by -
// <<< native-status | src 50a6aad1 | roc native-status --write
#include "v8datamodel/DataModel.h"
#include "tool/BasicMouseTools.h"
#include "StandardVerbs.h"

namespace RBX {
template<> MouseCommand* TToolVerb<CloneTool, RunStateVerb>::newMouseCommand()
{
    return new CloneTool(dataModel->getWorkspace());
}
}
