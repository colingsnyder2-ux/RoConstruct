// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL
// INFERRED: sub_0041e720 (placeholder name for 0041e720 from the identity tier; body byte-proved against the native headers by the placeholder lane)
#include "util/Name.h"
#include "v8datamodel/Decal.h"

namespace RBX {

boost::shared_ptr<Object> __stdcall sub_0041e720()
{
	return Creatable<Instance>::create<Decal>();
}

}
