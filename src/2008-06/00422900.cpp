// from server: 100% by king_originala
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: xtp-11.2.2-lib-imports roc_selection_tree_do_action_5729c0d2b29d1b06.cpp

// Candidate translation unit (score above; library headers required).
#include "Controls/XTTreeBase.h"

class CSelectionTreeCtrl : public CXTTreeBase
{
protected:
    virtual void DoAction(HTREEITEM hItem, BOOL bLeft, UINT nFlags, CPoint point);
};

void CSelectionTreeCtrl::DoAction(HTREEITEM hItem, BOOL bLeft, UINT nFlags, CPoint point)
{
    CXTTreeBase::DoAction(hItem, bLeft, nFlags, point);
}
