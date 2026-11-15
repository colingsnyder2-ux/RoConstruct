// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
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
