// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL
// INFERRED: sub_00408ce0 (placeholder name for 00408ce0 from the identity tier; body byte-proved against the native headers by the placeholder lane)
#include "util/Name.h"
#include "v8datamodel/Teams.h"

namespace RBX {

boost::shared_ptr<Object> __stdcall sub_00408ce0()
{
	return Creatable<Instance>::create<Teams>();
}

}
