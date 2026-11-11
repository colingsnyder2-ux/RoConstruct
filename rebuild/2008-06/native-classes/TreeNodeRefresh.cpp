// >>> native-status (generated) -- do not edit >>>
// TreeNodeRefresh | 2008-06 | draft (no current byte proof)
// 0/1 mapped addresses byte-exact | 1 unproved | no mapped strings | by king_originala (chatgpt:gpt-6.1-sol)
// <<< native-status | src a63d2766 | roc native-status --write
#include "CRobloxTreeCtrl.h"

void CRobloxTreeCtrlNode::refreshText()
{
    if (textDirty) {
        if (item && item != TVI_ROOT) {
            CRect rect;
            if (tree->GetItemRect(item, &rect, FALSE))
                tree->InvalidateRect(&rect, TRUE);
        }
        textDirty = false;
    }
}
