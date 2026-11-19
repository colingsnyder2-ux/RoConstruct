// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL
// INFERRED: sub_004692f0 (placeholder name for 004692f0 from the identity tier; body byte-proved against the native headers by the placeholder lane)
#include <G3D/Vector2.h>
#include "util/Name.h"

void sub_004692f0(const G3D::Vector2& input, G3D::Vector2& first, G3D::Vector2& second)
{
    const G3D::Vector2& zero = G3D::Vector2::zero();
    first.x = zero.x;
    first.y = zero.y;
    second.x = input.x + second.x;
    second.y = input.y + second.y;
}
