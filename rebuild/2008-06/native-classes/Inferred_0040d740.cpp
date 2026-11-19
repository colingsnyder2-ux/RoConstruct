// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNATIVE_DEBUGSETTINGS_PENDING
// INFERRED: sub_0040d740 (placeholder name for 0040d740 from the identity tier; body byte-proved against the native headers by the placeholder lane)
#define NATIVE_DEBUGSETTINGS_PENDING
#include "util/Name.h"
#include "v8datamodel/DebugSettings.h"

namespace RBX {

boost::shared_ptr<Object> __stdcall sub_0040d740()
{
	return Creatable<Instance>::create<DebugSettings>();
}

}
