// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast
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
