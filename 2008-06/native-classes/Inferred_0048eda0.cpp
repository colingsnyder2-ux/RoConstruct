// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /I{headers}/../../../tools/rbxgs/Client/App/include
// INFERRED: sub_0048eda0 (placeholder name for 0048eda0 from the identity tier; body byte-proved by the placeholder lane, includes as the lane resolved them)
#include "v8datamodel/BodyMovers.h"
#include "v8tree/Instance.h"
#include "util/Object.h"
#include "boost/shared_ptr.hpp"
#include "util/Name.h"

namespace RBX {

boost::shared_ptr<Object> __stdcall sub_0048eda0()
{
	return Creatable<Instance>::create<BodyVelocity>();
}

}
