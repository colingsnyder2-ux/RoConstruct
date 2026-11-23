// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// StatsService constructor 00458520. The base DescribedNonCreatable ctor (00458480) is called with "Stats"
// (pushed 00818c5c); the remaining stores are the vtable pointers of the StatsService/Instance/Service bases.
#include "stats/Stats.h"

namespace RBX
{
	namespace Stats
	{
		StatsService::StatsService() // 00458520
		{
		}
	}
}
