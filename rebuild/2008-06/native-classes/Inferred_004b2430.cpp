// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL
// INFERRED: sub_004b2430 (placeholder name for 004b2430 from the identity tier; body byte-proved against the native headers by the placeholder lane)
#include "util/Name.h"
#include "v8datamodel/JointInstance.h"

namespace RBX {

boost::shared_ptr<Object> __stdcall sub_004b2430()
{
	return Creatable<Instance>::create<Snap>();
}

}
