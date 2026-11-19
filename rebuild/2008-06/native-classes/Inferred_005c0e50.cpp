// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL
// INFERRED: sub_005c0e50 (placeholder name for 005c0e50 from the identity tier; body byte-proved against the native headers by the placeholder lane)
#include "util/Name.h"
#include "v8datamodel/Explosion.h"

namespace RBX {

boost::shared_ptr<Object> __stdcall sub_005c0e50()
{
	return Creatable<Instance>::create<Explosion>();
}

}
