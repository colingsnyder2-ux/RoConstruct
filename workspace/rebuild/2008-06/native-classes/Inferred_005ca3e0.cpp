// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL
// INFERRED: RBX::Stats::Item::sub_005ca3e0 (placeholder name for 005ca3e0 from the identity tier; body byte-proved against the native headers by the placeholder lane)
#include "Replicator.h"

namespace RBX {

float __fastcall sub_005ca3e0(const void* self)
{
    const unsigned char* p = (const unsigned char*)self;
    if (p[2] != 0)
        return 1.0f;
    if (p[3] != 0)
        return -1.0f;
    return 0.0f;
}

}
