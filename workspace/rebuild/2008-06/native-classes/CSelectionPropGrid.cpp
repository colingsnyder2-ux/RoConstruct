#include "CSelectionPropGrid.h"
IMPLEMENT_DYNAMIC(CSelectionPropGrid, CPropGrid)

CSelectionPropGrid::~CSelectionPropGrid()
{
    setSelection(NULL);
}
