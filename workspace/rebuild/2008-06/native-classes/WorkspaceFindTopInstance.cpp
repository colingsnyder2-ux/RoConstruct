// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// >>> native-status (generated) -- do not edit >>>
// WorkspaceFindTopInstance | 2008-06 | draft (no current byte proof)
// no original address mapped to this file yet | by -
// <<< native-status | src d2301df5 | roc native-status --write
#include "v8datamodel/Workspace.h"

namespace RBX {
Instance* Workspace::findTopInstance(Instance* instance)
{
    Instance* workspace = instance->getParent();
    Instance* data = workspace->getParent();
    while (data->getParent()) {
        workspace = data;
        data = data->getParent();
    }
    while (instance->getParent() != workspace)
        instance = instance->getParent();
    return instance;
}
}
