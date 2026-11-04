#include "PropertyGridItems.h"
#include "v8tree/Instance.h"
#include "DataModelLock.cpp"

template<>
void XItem<float, CXTPPropertyGridItem, RBX::Reflection::TypedPropertyDescriptor<float> >::writeValue(RBX::Instance* instance, const float& value)
{
    RBX::DataModel::Lock lock(grid->dataModel);
    descriptor->setValue(instance, value);
}
