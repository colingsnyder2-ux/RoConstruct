// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include "util/Name.h"

namespace RBX {
	extern char sModel[];
	static const Name& partName = Name::declare(sModel, 2000);
}
