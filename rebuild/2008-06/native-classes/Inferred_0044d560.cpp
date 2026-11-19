// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL
// INFERRED: sub_0044d560 (placeholder name for 0044d560 from the identity tier; body byte-proved against the native headers by the placeholder lane)
#include "util/Name.h"
#include "v8datamodel/Team.h"

namespace RBX {

boost::shared_ptr<Object> __stdcall sub_0044d560()
{
	return Creatable<Instance>::create<Team>();
}

}
