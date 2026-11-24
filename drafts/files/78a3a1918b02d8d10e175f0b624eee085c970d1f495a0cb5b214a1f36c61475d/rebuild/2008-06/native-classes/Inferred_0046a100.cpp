// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast /I{headers}/widget-rect-2008
// INFERRED: sub_0046a100 (placeholder name for 0046a100 from the identity tier): forwards to sub_0046a010 with count 6 and 0.0f; body byte-proved
// sub_0046a010 (placeholder 0046a010, DxUserInput unit 004675e0..0046a1f0): flags copied from DxUserInput.cpp (/fp:fast,
// the x87 values stay in registers) plus the Rect header the binary's unionWith 005cf000 caller needs.
#include "G3D/Vector2.h"
#include "util/Rect.h"

// 0046a010 (cdecl, 6 args; callers 0046a100 / 0046a130 / 0046a1b0). Half-size a4 * 0.5f (00819bac) Rect inset by n
// (inline Rect::inset(int)), Rect::unionWith 005cf000 with the point a3 (Rect(p, p)), the moved point a1 + p clamped by
// G3D::Vector2::clamp 00469fa0 into the same slot, then a3 = clamped + overshoot * f and a2 += overshoot.
// INFERRED: argument roles from the disassembly (a1 delta, a2 accumulated overshoot, a3 position, a4 window size).
void __cdecl sub_0046a010(const G3D::Vector2& a, G3D::Vector2& b, G3D::Vector2& c, const G3D::Vector2& d, int n, float f)
{
	G3D::Vector2 half = d * 0.5f;
	RBX::Rect bounds = RBX::Rect(-half, half).inset(n);

	G3D::Vector2 position = c;
	bounds.unionWith(RBX::Rect(position, position));

	G3D::Vector2 moved = a + position;
	G3D::Vector2 clamped = moved.clamp(bounds.low, bounds.high);

	G3D::Vector2 overshoot = moved - clamped;
	c = clamped + overshoot * f;
	b += overshoot;
}

// 0046a100: util/DxUserInput.h declares the reference signature its caller DxUserInput::applyMouseDelta 00467f10 uses.
void sub_0046a100(const G3D::Vector2& a, G3D::Vector2& b, G3D::Vector2& c, const G3D::Vector2& d)
{
	sub_0046a010(a, b, c, d, 6, 0.0f);
}
