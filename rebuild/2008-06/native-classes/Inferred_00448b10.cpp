// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL
// INFERRED: RBX::Reflection::EnumPropertyDescriptor::sub_00448b10 (placeholder name for 00448b10 from the identity tier; body byte-proved against the native headers by the placeholder lane)
#include "reflection/property.h"

void RBX::Reflection::EnumPropertyDescriptor::sub_00448b10(RBX::Reflection::DescribedBase* instance, const RBX::Reflection::Value& value) const
{
    setEnumValue(instance, value.get<int>());
}
