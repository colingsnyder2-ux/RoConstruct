// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /I{headers}/../../../tools/rbxgs/Client/App/include
// 0056e200: real name from the identity registry; body byte-proved against the native headers (named lane)
#include "reflection/reflection.h"
#include "util/Name.h"

namespace RBX {
namespace Reflection {

template<>
std::string TypedPropertyDescriptor<double>::getStringValue(const DescribedBase* instance) const
{
	return StringConverter<double>::convertToString(getValue(instance));
}

}
}
