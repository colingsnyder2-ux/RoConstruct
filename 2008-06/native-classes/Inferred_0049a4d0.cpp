// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL
// INFERRED: sub_0049a4d0 (placeholder name for 0049a4d0 from the identity tier; body byte-proved against the native headers by the placeholder lane)
#include "util/Name.h"
#include "script/Script.h"

namespace RBX {

boost::shared_ptr<Object> __stdcall sub_0049a4d0()
{
	return Creatable<Instance>::create<Script>();
}

}
