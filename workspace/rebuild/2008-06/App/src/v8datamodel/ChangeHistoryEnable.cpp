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

void RBX::ChangeHistoryService::onServiceProvider(const ServiceProvider* oldProvider, const ServiceProvider* newProvider)
{
    if (oldProvider) {
        reset();
        connectionAdded.disconnect();
        connectionRemoved.disconnect();
        connectionChanged.disconnect();
        context = NULL;
    }
    if (newProvider) context = const_cast<ServiceProvider*>(newProvider);
}
