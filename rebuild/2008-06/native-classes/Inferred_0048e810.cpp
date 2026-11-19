// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL
// INFERRED: sub_0048e810 (placeholder name for 0048e810 from the identity tier; body byte-proved against the native headers by the placeholder lane)
#include "util/Name.h"
#include "v8datamodel/Hopper.h"

namespace RBX {

boost::shared_ptr<Object> __stdcall sub_0048e810()
{
    return Creatable<Instance>::create<HopperBin>();
}

}
