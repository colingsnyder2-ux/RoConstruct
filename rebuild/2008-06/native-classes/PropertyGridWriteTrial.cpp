// >>> native-status (generated) -- do not edit >>>
// PropertyGridWriteTrial | 2008-06 | inactive
// unmapped (no binary link) | by -
// <<< native-status | src 72396fc5 | roc native-status --write
#include "PropertyGridItems.h"
#include "v8tree/Instance.h"
#include "DataModelLock.cpp"

template<>
void XItem<float, CXTPPropertyGridItem, RBX::Reflection::TypedPropertyDescriptor<float> >::writeValue(RBX::Instance* instance, const float& value)
{
    RBX::DataModel::Lock lock(grid->dataModel);
    descriptor->setValue(instance, value);
}
