// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /GS-
#include "../native-headers/CRobloxTreeCtrl.h"

void CRobloxTreeCtrlNode::refreshText()
{
    if (textDirty) {
        if (item != NULL && item != (HTREEITEM)0xffff0000) {
            RECT rect;
            if (tree->GetItemRect(item, &rect, FALSE)) {
                ::InvalidateRect(tree->m_hWnd, &rect, TRUE);
            }
        }
        textDirty = false;
    }
}
