#include "v8tree/Service.h"
namespace RBX {
const ServiceProvider* ServiceProvider::findServiceProvider(const Instance* context)
{
    while (context) {
        if (const ServiceProvider* service = dynamic_cast<const ServiceProvider*>(context))
            return service;
        context = context->getParent();
    }
    return 0;
}
}
