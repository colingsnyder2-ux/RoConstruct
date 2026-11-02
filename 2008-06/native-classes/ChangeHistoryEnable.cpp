#include "v8datamodel/ChangeHistoryService.h"
#include "security/SecurityContext.h"

void RBX::ChangeHistoryService::setEnabled(bool value)
{
    Security::Context::current().requirePermission(Security::Administrator, "ChangeHistoryService.enabled");
    if (value != enabled) {
        enabled = value;
        if (value) start();
        else {
            reset();
            connectionAdded.disconnect();
            connectionRemoved.disconnect();
            connectionChanged.disconnect();
        }
    }
}
