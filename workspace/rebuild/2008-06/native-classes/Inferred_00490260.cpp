// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL
// INFERRED: sub_00490260 (placeholder name for 00490260 from the identity tier; body byte-proved against the native headers by the placeholder lane)
#include "util/Name.h"
#include "v8datamodel/Teams.h"

namespace RBX {

boost::shared_ptr<Object> __stdcall sub_00490260()
{
	return Creatable<Instance>::create<Teams>();
}

}
