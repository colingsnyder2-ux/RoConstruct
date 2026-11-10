#include "CPropGrid.h"

void CPropGrid::addProperty(const RBX::Reflection::ClassDescriptor* classDesc,
                            const RBX::Reflection::PropertyDescriptor* propDesc)
{
    CXTPPropertyGridItem* category = getCategory(classDesc->name);
    Item* item = new Item(propDesc, this);
    category->AddChildItem(item);
    propertyItems[propDesc] = item;
    items.push_back(item);
}
