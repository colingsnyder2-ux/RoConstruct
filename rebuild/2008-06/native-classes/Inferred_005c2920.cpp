// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL
// INFERRED: sub_005c2920 (placeholder name for 005c2920 from the identity tier; body byte-proved against the native headers by the placeholder lane)
#include "util/Name.h"
#include "v8datamodel/Rocket.h"

namespace RBX {

boost::shared_ptr<Object> __stdcall sub_005c2920()
{
	return Creatable<Instance>::create<Rocket>();
}

}
