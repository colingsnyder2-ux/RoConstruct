// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL
// INFERRED: sub_004b32d0 (placeholder name for 004b32d0 from the identity tier; body byte-proved against the native headers by the placeholder lane)
#include "util/Object.h"
#include "util/Object.h"
#include "v8tree/Instance.h"
#include "v8datamodel/JointInstance.h"
#include "V8DataModel/JointInstance.h"

namespace RBX {

boost::shared_ptr<RBX::Object> __stdcall sub_004b32d0()
{
    return RBX::Creatable<RBX::Instance>::create<RBX::Motor>();
}

}
