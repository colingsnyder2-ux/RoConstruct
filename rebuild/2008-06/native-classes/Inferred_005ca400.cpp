// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL
// INFERRED: RBX::Stats::Item::sub_005ca400 (placeholder name for 005ca400 from the identity tier; body byte-proved against the native headers by the placeholder lane)
#include "Replicator.h"

float __fastcall sub_005ca400(void* self)
{
    const unsigned char* p = (const unsigned char*)self;
    if (p[4] != 0)
        return 1.0f;
    if (p[5] != 0)
        return -1.0f;
    return 0.0f;
}
