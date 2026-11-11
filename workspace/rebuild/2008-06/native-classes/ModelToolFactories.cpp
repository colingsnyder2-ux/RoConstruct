// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// >>> native-status (generated) -- do not edit >>>
// ModelToolFactories | 2008-06 | draft (no current byte proof)
// no original address mapped to this file yet | by -
// <<< native-status | src dad0503d | roc native-status --write
#include "v8datamodel/DataModel.h"
#include "tool/ModelTools.h"
#include "StandardVerbs.h"

namespace RBX {
template<> MouseCommand* TToolVerb<AnchorTool, RunStateVerb>::newMouseCommand()
{
    return new AnchorTool(dataModel->getWorkspace());
}

template<> MouseCommand* TToolVerb<LockTool, RunStateVerb>::newMouseCommand()
{
    return new LockTool(dataModel->getWorkspace());
}
}
