// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL
// INFERRED: sub_005c1cf0 (placeholder name for 005c1cf0 from the identity tier; body byte-proved against the native headers by the placeholder lane)
#include "util/Name.h"
#include "V8DataModel/JointInstance.h"

namespace RBX {

boost::shared_ptr<Object> __stdcall sub_005c1cf0()
{
    return Creatable<Instance>::create<Glue>();
}

}
