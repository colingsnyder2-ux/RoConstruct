// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /I{headers}/../../../tools/rbxgs/Client/App/include
// INFERRED: sub_00578160 (placeholder name for 00578160 from the identity tier; body byte-proved by the placeholder lane, includes as the lane resolved them)
#include "util/Name.h"
#include "v8tree/Instance.h"
#include "v8datamodel/BodyMovers.h"

namespace RBX {

boost::shared_ptr<Object> __stdcall sub_00578160()
{
    return Creatable<Instance>::create<BodyGyro>();
}

}
