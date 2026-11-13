// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast /D_AFXDLL /DNDEBUG /D_MBCS
// >>> native-status (generated) -- do not edit >>>
// AppUnit5E0LightingReflection | 2008-06 | draft (no current byte proof)
// no original address mapped to this file yet | by -
// <<< native-status | src b3f8bf2e | roc native-status --write
#include "v8datamodel/Lighting2008.h"
#include <boost/date_time/posix_time/time_formatters.hpp>
namespace RBX {
std::string Lighting::getTimeStr() const
	{
		return boost::posix_time::to_simple_string(timeOfDay);
	}
}
