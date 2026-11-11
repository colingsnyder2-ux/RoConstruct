// >>> native-status (generated) -- do not edit >>>
// ChangeHistoryBase | 2008-06 | draft (no current byte proof)
// 0/1 mapped addresses byte-exact | 1 unproved | no mapped strings | by king_originala (chatgpt:gpt-6.1-sol)
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
