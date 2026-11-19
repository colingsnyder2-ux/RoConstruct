// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL
// INFERRED: sub_005a1910 (placeholder name for 005a1910 from the identity tier; body byte-proved against the native headers by the placeholder lane)
#include "v8tree/Instance.h"
#include "v8datamodel/PartInstance.h"
#include "V8DataModel/PartInstance.h"

void __cdecl sub_005a1910(RBX::Instance* instance)
{
    if (RBX::PartInstance* part = dynamic_cast<RBX::PartInstance*>(instance))
        part->join();
    else
        instance->for_eachChild(&sub_005a1910);
}
