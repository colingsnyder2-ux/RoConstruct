// >>> native-status (generated) -- do not edit >>>
// CPropGrid | 2008-06 | inactive
// unmapped (no binary link) | unmapped (no binary link) | by -
// <<< native-status | src 269550c9 | roc native-status --write
#include "CPropGrid.h"
IMPLEMENT_DYNAMIC(CPropGrid, CXTPPropertyGrid)

CPropGrid::CPropGrid() : dataModel(NULL), posted(false), dirty(false)
{
    m_bHelpVisible = FALSE;
}

CPropGrid::~CPropGrid()
{
}
