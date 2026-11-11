// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast
// >>> native-status (generated) -- do not edit >>>
// PropertyGridWriteTrial | 2008-06 | draft (no current byte proof)
// no original address mapped to this file yet | by -
// <<< native-status | src 964c8a85 | roc native-status --write
#include "PropertyGridItems.h"
#include "v8tree/Instance.h"
#include "DataModelLock.cpp"

template<>
void XItem<float, CXTPPropertyGridItem, RBX::Reflection::TypedPropertyDescriptor<float> >::writeValue(RBX::Instance* instance, const float& value)
{
    RBX::DataModel::Lock lock(grid->dataModel);
    descriptor->setValue(instance, value);
}

// Template members emitted by this unit (bodies byte-identical to the 2008-06 client).
template class XItem<float,CXTPPropertyGridItem,RBX::Reflection::TypedPropertyDescriptor<float> >;
