// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /I{headers}/../../../tools/rbxgs/Client/App/include
// INFERRED: sub_005c2440 (placeholder name for 005c2440 from the identity tier; body byte-proved by the placeholder lane, includes as the lane resolved them)
#include "v8datamodel/BodyMovers.h"
#include "v8tree/Instance.h"
#include "util/Object.h"
#include "boost/shared_ptr.hpp"
#include "util/Name.h"

namespace RBX {

boost::shared_ptr<Object> __stdcall sub_005c2440()
{
	return Creatable<Instance>::create<BodyPosition>();
}

}
