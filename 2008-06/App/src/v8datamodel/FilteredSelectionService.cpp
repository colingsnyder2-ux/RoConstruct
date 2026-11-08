// >>> native-status (generated) -- do not edit >>>
// FilteredSelectionService | 2008-06 | inactive
// unmapped (no indexed address) | unmapped (no binary link) | by -
// <<< native-status | src 14d696a9 | roc native-status --write
#include "v8datamodel/Selection.h"
#include "v8datamodel/PVInstance.h"

namespace RBX {
template<> FilteredSelection<PVInstance>* ServiceProvider::create<FilteredSelection<PVInstance> >(const Instance* context) {
    while (context) {
        if (const ServiceProvider* service = dynamic_cast<const ServiceProvider*>(context))
            return service->create<FilteredSelection<PVInstance> >();
        context = context->getParent();
    }
    return NULL;
}
}
