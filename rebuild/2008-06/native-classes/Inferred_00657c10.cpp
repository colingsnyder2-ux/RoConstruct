// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /I{headers}/../../../tools/rbxgs/Client/App/include
// 00657c10: real name from the identity registry; body byte-proved against the native headers (named lane)
#include "boost/algorithm/string/detail/classification.hpp"
#include "util/Name.h"

namespace boost {
namespace algorithm {

detail::is_classifiedF __cdecl is_space(const std::locale& Loc)
{
	return detail::is_classifiedF(std::ctype_base::space, Loc);
}

}
}
