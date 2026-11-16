// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL
// INFERRED: RBX::Body::sub_005e7370 (placeholder name for 005e7370 from the identity tier; body byte-proved against the native headers by the placeholder lane)
#include "v8kernel/Body2008.h"

int RBX::Body::sub_005e7370() const
{
    if (const Body* p = getParent())
        return p->sub_005e7370() + 1;
    return 1;
}
