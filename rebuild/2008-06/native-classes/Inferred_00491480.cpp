// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL
// 00491480: real name from the identity registry; body byte-proved against the native headers (named lane)
#include <string>
#include "util/Name.h"
#include "reflection/reflection.h"

namespace RBX {
namespace Reflection {

std::string PropertyDescriptor::getStringValue(const DescribedBase* instance) const
{
	hasStringValue();
	return std::string("");
}

}
}
