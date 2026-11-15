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
