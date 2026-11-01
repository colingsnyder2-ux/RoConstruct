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
