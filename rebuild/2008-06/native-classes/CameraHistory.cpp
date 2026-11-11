// >>> native-status (generated) -- do not edit >>>
// CameraHistory | 2008-06 | selection unverified
// unmapped (no binary link) | by -
// <<< native-status | src 80007491 | roc native-status --write
#include "v8datamodel/ChangeHistoryService.h"

namespace RBX {
template<> ChangeHistoryService* ServiceProvider::find<ChangeHistoryService>(const Instance* context) {
    while (context) {
        if (const ServiceProvider* service = dynamic_cast<const ServiceProvider*>(context))
            return service->find<ChangeHistoryService>();
        context = context->getParent();
    }
    return NULL;
}

void recordCameraHistory(const char* name, const Instance* context) {
    ChangeHistoryService* history = ServiceProvider::find<ChangeHistoryService>(context);
    if (history) history->commit(name);
}
}
