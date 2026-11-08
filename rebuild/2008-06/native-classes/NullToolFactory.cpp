// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include "v8datamodel/DataModel.h"
#include "tool/NullTool.h"
#include "StandardVerbs.h"

namespace RBX {
template<> MouseCommand* TToolVerb<NullTool, RunStateVerb>::newMouseCommand()
{
    return new NullTool(dataModel->getWorkspace());
}
}
