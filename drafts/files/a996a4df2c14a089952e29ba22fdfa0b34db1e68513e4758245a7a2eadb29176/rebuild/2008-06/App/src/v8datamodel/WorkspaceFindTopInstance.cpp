// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
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

// 005a3380: find Workspace in context's ancestry (including self).
Workspace* Workspace::findWorkspace(const Instance* context)
{
    const Instance* p = context;
    while (p) {
        Workspace* w = Instance::fastDynamicCast<Workspace>(const_cast<Instance*>(p));
        if (w)
            return w;
        p = p->getParent();
    }
    return NULL;
}

// 005a3390: world of the Workspace containing context, if any.
World* Workspace::getWorldIfInWorkspace(const Instance* context)
{
    Workspace* ws = findWorkspace(context);
    if (!ws)
        return NULL;
    if (context != ws && !const_cast<Instance*>(context)->isDescendantOf(ws))
        return NULL;
    return ws->getWorld();
}

// 005a33d0: true if context is in a Workspace.
bool Workspace::contextInWorkspace(const Instance* context)
{
    Workspace* ws = findWorkspace(context);
    if (!ws)
        return false;
    if (context != ws && !const_cast<Instance*>(context)->isDescendantOf(ws))
        return false;
    return true;
}
}
