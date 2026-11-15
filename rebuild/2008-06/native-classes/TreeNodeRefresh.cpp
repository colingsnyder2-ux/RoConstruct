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
