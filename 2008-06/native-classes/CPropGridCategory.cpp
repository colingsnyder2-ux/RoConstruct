// >>> native-status (generated) -- do not edit >>>
// CPropGridCategory | 2008-06 | draft (no current byte proof)
// no original address mapped to this file yet | by -
// <<< native-status | src 69104413 | roc native-status --write
#include "CPropGrid.h"
#include "util/Name.h"

CXTPPropertyGridItem* CPropGrid::getCategory(const RBX::Name& name)
{
    CXTPPropertyGridItem* category = FindItem(name.c_str());
    if (!category) {
        category = AddCategory(name.c_str());
        category->Expand();
    }
    return category;
}
