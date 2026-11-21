// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL
// INFERRED: sub_0049ea80 (placeholder name for 0049ea80 from the identity tier; body byte-proved against the native headers by the placeholder lane)
#include "util/Name.h"
#include "script/Script.h"

namespace RBX {

boost::shared_ptr<Object> __stdcall sub_0049ea80()
{
	return Creatable<Instance>::create<Script>();
}

}
