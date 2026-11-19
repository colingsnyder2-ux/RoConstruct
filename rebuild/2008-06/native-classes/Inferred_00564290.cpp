// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL
// INFERRED: RBX::Reflection::TypedPropertyDescriptor::sub_00564290 (placeholder name for 00564290 from the identity tier; body byte-proved against the native headers by the placeholder lane)
#include "reflection/property.h"

template<>
void RBX::Reflection::TypedPropertyDescriptor<double>::sub_00564290(DescribedBase* instance, const Value& value) const
{
	double converted = value.get<double>();
	getset->setValue(instance, converted);
}
