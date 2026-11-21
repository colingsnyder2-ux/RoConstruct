// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL
// INFERRED: sub_0063a080 (placeholder name for 0063a080 from the identity tier; body byte-proved against the native headers by the placeholder lane)
#include "util/Object.h"
#include "util/Object.h"
#include "v8tree/Instance.h"
#include "v8datamodel/Teams.h"

namespace RBX {

boost::shared_ptr<RBX::Object> __stdcall sub_0063a080()
{
	return RBX::Creatable<RBX::Instance>::create<RBX::Teams>();
}

}
