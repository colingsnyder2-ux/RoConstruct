// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL
// INFERRED: RBX::Reflection::EnumPropertyDescriptor::sub_004485b0 (placeholder name for 004485b0 from the identity tier; body byte-proved against the native headers by the placeholder lane)
#include "reflection/property.h"
#include "reflection/enumconverter.h"

namespace RBX { namespace Reflection {

void EnumPropertyDescriptor::sub_004485b0(const DescribedBase* instance, Value& value) const
{
	value = getEnumValue(instance);
}

}}
