// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL
// 0056e240: real name from the identity registry; body byte-proved against the native headers (named lane)
#include "util/Name.h"
#include "reflection/Property.h"

namespace RBX {
namespace Reflection {

template<>
bool TypedPropertyDescriptor<double>::setStringValue(DescribedBase* instance, const std::string& text) const
{
	double value;
	if (StringConverter<double>::convertToValue(text, value))
	{
		setValue(instance, value);
		return true;
	}
	return false;
}

}
}
