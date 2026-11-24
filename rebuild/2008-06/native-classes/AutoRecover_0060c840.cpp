// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include "v8datamodel/Feature.h"

namespace RBX
{
	// The base constructor call (0060c740), the vtable stores and the temporary
	// std::string("Hole") are all emitted by the compiler. Only setName is
	// written explicitly (0055af90).
	Hole::Hole()
	{
		setName("Hole");
	}
}
