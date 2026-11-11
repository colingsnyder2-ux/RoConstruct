// >>> native-status (generated) -- do not edit >>>
// CSelectionPropGrid | 2008-06 | draft (no current byte proof)
// 0/1 mapped addresses byte-exact | 1 unproved | no mapped strings | by king_originala (chatgpt:gpt-6.1-sol)
// <<< native-status | src 8abcb468 | roc native-status --write
#include "CSelectionPropGrid.h"
IMPLEMENT_DYNAMIC(CSelectionPropGrid, CPropGrid)

CSelectionPropGrid::~CSelectionPropGrid()
{
    setSelection(NULL);
}
