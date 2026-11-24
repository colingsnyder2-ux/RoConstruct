// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include "v8datamodel/DataModel.h"
#include "tool/BasicMouseTools.h"
#include "StandardVerbs.h"

namespace RBX {
template<> MouseCommand* TToolVerb<HammerTool, RunStateVerb>::newMouseCommand()
{
    return new HammerTool(dataModel->getWorkspace());
}
}
