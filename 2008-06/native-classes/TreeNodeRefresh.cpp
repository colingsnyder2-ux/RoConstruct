// >>> native-status (generated) -- do not edit >>>
// TreeNodeRefresh | 2008-06 | inactive
// unmapped (no binary link) | unmapped (no binary link) | by -
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
