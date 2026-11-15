// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /GS-
#include "CDataModelPropGrid.h"
IMPLEMENT_DYNAMIC(CDataModelPropGrid, CSelectionPropGrid)

CDataModelPropGrid::CDataModelPropGrid()
{
}

// Template members emitted by this unit (bodies byte-identical to the 2008-06 client).
template class RBX::Listener<RBX::Selection,RBX::SelectionChanged>;
