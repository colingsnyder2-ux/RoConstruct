#include "v8datamodel/ChangeHistoryService.h"

void RBX::ChangeHistoryService::initializeBase()
{
    if (enabled) {
        commit("base");
        while (history.size() > 1)
            mergeFirst();
    }
}
