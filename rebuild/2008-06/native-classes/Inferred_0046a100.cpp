// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL
// INFERRED: sub_0046a100 (placeholder name for 0046a100 from the identity tier): forwards to sub_0046a010 with count 6 and 0.0f; body byte-proved
#include "G3D/Vector2.h"

void __cdecl sub_0046a010(const G3D::Vector2* a, G3D::Vector2* b, G3D::Vector2* c, const G3D::Vector2* d, int n, float f);

void __cdecl sub_0046a100(const G3D::Vector2* a, G3D::Vector2* b, G3D::Vector2* c, const G3D::Vector2* d)
{
	sub_0046a010(a, b, c, d, 6, 0.0f);
}
