// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL
// INFERRED: RBX::Reflection::EnumPropDescriptor::sub_00448c20 (placeholder name for 00448c20 from the identity tier; body byte-proved against the native headers by the placeholder lane)
#include "reflection/reflection.h"
#include "CRenderSettings.h"
#include "reflection/enumconverter.h"

namespace RBX { namespace Reflection {

template<class Class, typename Enum>
bool EnumPropDescriptor<Class, Enum>::sub_00448c20(DescribedBase* instance, int intValue) const
{
	if (enumDescPtr->isValue(intValue))
	{
		setValue(instance, static_cast<Enum>(intValue));
		return true;
	}
	return false;
}

template bool EnumPropDescriptor<CRenderSettings, CRenderSettings::GraphicsMode>::sub_00448c20(DescribedBase* instance, int intValue) const;

}}
