// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL
// INFERRED: sub_004d8d10 (placeholder name for 004d8d10 from the identity tier; body byte-proved against the native headers by the placeholder lane)
#include "util/Name.h"
#include "v8datamodel/Sky.h"

namespace RBX {

boost::shared_ptr<Object> __stdcall sub_004d8d10()
{
	return Creatable<Instance>::create<Sky>();
}

}
