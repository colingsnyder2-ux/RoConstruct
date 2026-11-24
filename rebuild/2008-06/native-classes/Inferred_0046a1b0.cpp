// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast
// 0046a1b0 (registry placeholder func_0046a1b0; caller DxUserInput::applyMouseDelta 00467f10): sub_0046a010 with
// count 20 (0x14) and 0.05f (0081c430), then the vertical delta is dropped and the position keeps a.y + c.y.
// Signature from native-headers/util/DxUserInput.h (sub_0046a1b0, cdecl, references); flags copied from DxUserInput.cpp.
#include <G3D/Vector2.h>

void __cdecl sub_0046a010(const G3D::Vector2& a, G3D::Vector2& b, G3D::Vector2& c, const G3D::Vector2& d, int n, float f); // 0046a010 (Inferred_0046a100.cpp)

void sub_0046a1b0(const G3D::Vector2& a, G3D::Vector2& b, G3D::Vector2& c, const G3D::Vector2& d)
{
	float y = a.y + c.y;
	sub_0046a010(a, b, c, d, 20, 0.05f);
	b.y = 0.0f;
	c.y = y;
}
