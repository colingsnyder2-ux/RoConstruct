// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast
// 2008-06 native Debugable / Log static data (inactive). Values read from the exe .data image.
#include "util/Debug.h"
#include <string>
#include <fstream>
#include "util/Log.h"

namespace RBX
{
	Debugable::AssertAction Debugable::assertAction = Debugable::IgnoreAssert; // 0094627c (.data, initial 1)
	bool Debugable::validatingDebug = false;                                    // 00974ac0 (.bss)
	Log::Severity Log::aggregateWorstSeverity = Log::Information;               // INFERRED: address unknown, zero-initialised
}
