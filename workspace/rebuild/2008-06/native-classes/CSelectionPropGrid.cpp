// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /GS-
#include "CSelectionPropGrid.h"
#include "../native-headers/v8datamodel/SelectionChanged.h"

IMPLEMENT_DYNAMIC(CSelectionPropGrid, CPropGrid)

CSelectionPropGrid::~CSelectionPropGrid()
{
    setSelection(NULL);
}

void CSelectionPropGrid::onEvent(const RBX::Selection*, RBX::SelectionChanged change)
{
    boost::shared_ptr<RBX::Instance>* p = reinterpret_cast<boost::shared_ptr<RBX::Instance>*>(&change);
    if (p[0])
        addInstance(p[0]);
    if (p[1])
        removeInstance(p[1]);
    boost::recursive_mutex::scoped_lock lock(mutex);
    dirty = true;
    pendingItems.clear();
    requestUpdate();
}

