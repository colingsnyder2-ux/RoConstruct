// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// >>> native-status (generated) -- do not edit >>>
// ControllerEnabled | 2008-06 | selection unverified
// unmapped (no binary link) | by -
// <<< native-status | src 96e11e8d | roc native-status --write
#include "StandardVerbs.h"
#include "v8datamodel/DataModel.h"
#include "v8datamodel/Selection.h"
#include "v8datamodel/PVInstance.h"

namespace RBX {
static __declspec(noinline) bool controllable(PVInstance* item)
{
    return item->isControllable();
}

bool ControllerCommand::isEnabled() const
{
    if (!(selection->size() > 0)) return false;
    FilteredSelection<PVInstance>* items = ServiceProvider::create<FilteredSelection<PVInstance> >(
        static_cast<const ServiceProvider*>(dataModel));
    return items->findFirst(controllable) != NULL;
}
}
