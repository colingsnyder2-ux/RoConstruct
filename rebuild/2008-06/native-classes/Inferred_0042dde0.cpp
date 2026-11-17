// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL
// INFERRED: sub_0042dde0 (placeholder name for 0042dde0 from the identity tier; body byte-proved against the native headers by the placeholder lane)
#include "util/Name.h"
#include "script/ScriptContext.h"

namespace RBX {

boost::shared_ptr<Object> __stdcall sub_0042dde0()
{
	return Creatable<Instance>::create<ScriptContext>();
}

}
