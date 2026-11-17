// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /I{headers}/../../../tools/rbxgs/Client/App/include
// INFERRED: sub_00415150 (placeholder name for 00415150 from the identity tier; body byte-proved by the placeholder lane, includes as the lane resolved them)
#include "v8datamodel/ChangeHistoryService.h"
#include "v8tree/Instance.h"
#include "util/Object.h"
#include "boost/shared_ptr.hpp"
#include "util/Name.h"

namespace RBX {

boost::shared_ptr<Object> __stdcall sub_00415150()
{
	return Creatable<Instance>::create<ChangeHistoryService>();
}

}
