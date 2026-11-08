#include "CPropGrid.h"
IMPLEMENT_DYNAMIC(CPropGrid, CXTPPropertyGrid)

CPropGrid::CPropGrid() : dataModel(NULL), posted(false), dirty(false)
{
    m_bHelpVisible = FALSE;
}

CPropGrid::~CPropGrid()
{
}
