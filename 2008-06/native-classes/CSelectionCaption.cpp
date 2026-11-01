#include "CSelectionCaption.h"

IMPLEMENT_DYNAMIC(CSelectionCaption, CXTCaption)

CSelectionCaption::CSelectionCaption()
{
}

bool CSelectionCaption::filter(const RBX::Selection*, const RBX::SelectionChanged&,
                               const RBX::Selection*, const RBX::SelectionChanged&)
{
    return true;
}
