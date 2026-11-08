// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// >>> native-status (generated) -- do not edit >>>
// NullToolFactory | 2008-06 | inactive
// unmapped (no indexed address) | unmapped (no binary link) | by -
// <<< native-status | src 5ac88615 | roc native-status --write
#include "v8datamodel/DataModel.h"
#include "tool/NullTool.h"
#include "StandardVerbs.h"

namespace RBX {
template<> MouseCommand* TToolVerb<NullTool, RunStateVerb>::newMouseCommand()
{
    return new NullTool(dataModel->getWorkspace());
}
}
