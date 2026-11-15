// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
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
