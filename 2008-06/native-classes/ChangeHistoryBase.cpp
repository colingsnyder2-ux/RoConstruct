// >>> native-status (generated) -- do not edit >>>
// ChangeHistoryBase | 2008-06 | inactive
// unmapped (no indexed address) | unmapped (no binary link) | by -
// <<< native-status | src 93ff2a94 | roc native-status --write
#include "v8datamodel/ChangeHistoryService.h"

void RBX::ChangeHistoryService::initializeBase()
{
    if (enabled) {
        commit("base");
        while (history.size() > 1)
            mergeFirst();
    }
}
