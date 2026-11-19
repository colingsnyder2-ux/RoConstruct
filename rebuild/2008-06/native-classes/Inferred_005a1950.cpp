// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL
// INFERRED: sub_005a1950 (placeholder name for 005a1950 from the identity tier; body byte-proved against the native headers by the placeholder lane)
#include "util/Name.h"
#include "v8datamodel/PartInstance.h"

namespace RBX {

void sub_005a1950(Instance* instance)
{
    if (PartInstance* part = dynamic_cast<PartInstance*>(instance))
        part->destroyJoints();
    else
        instance->for_eachChild(&sub_005a1950);
}

}
