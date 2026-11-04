#include "v8tree/Service.h"
const RBX::ServiceProvider* SoundWorker_findServiceProvider(const RBX::Instance* context)
{
    while (context) {
        if (const RBX::ServiceProvider* service = dynamic_cast<const RBX::ServiceProvider*>(context))
            return service;
        context = context->getParent();
    }
    return 0;
}
