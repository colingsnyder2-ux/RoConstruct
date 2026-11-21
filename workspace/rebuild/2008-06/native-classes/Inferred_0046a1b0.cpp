// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL
// 0046a1b0: real name from the identity registry; body byte-proved against the native headers (named lane)
#include <G3D/Vector2.h>
#include "util/Name.h"

struct Vec2;

void __cdecl f(const G3D::Vector2* a, G3D::Vector2* b, G3D::Vector2* c, const G3D::Vector2* d, int n, float s);

void __cdecl update(struct Vec2* pa, struct Vec2* pb, struct Vec2* pc, void* context)
{
	G3D::Vector2* a = reinterpret_cast<G3D::Vector2*>(pa);
	G3D::Vector2* b = reinterpret_cast<G3D::Vector2*>(pb);
	G3D::Vector2* c = reinterpret_cast<G3D::Vector2*>(pc);
	float y = a->y + c->y;
	f(a, b, c, static_cast<const G3D::Vector2*>(context), 20, 0.05f);
	b->y = 0.0f;
	c->y = y;
}
