// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL
// INFERRED: sub_004b3060 (placeholder name for 004b3060 from the identity tier; body byte-proved against the native headers by the placeholder lane)
#include "util/Name.h"
#include "V8DataModel/JointInstance.h"

namespace RBX {

boost::shared_ptr<Object> __stdcall sub_004b3060()
{
	return Creatable<Instance>::create<Glue>();
}

}
