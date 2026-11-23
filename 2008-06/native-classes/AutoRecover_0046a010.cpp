// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include "util/Rect.h"

// INFERRED: Rect lives in namespace RBX and has a (min, max) Vector2 constructor;
// the header was not visible, so this is a guess. Its two corners are read back
// through a pointer cast so no member names have to be guessed.
// INFERRED: the constant at 0x819bac is taken to be 0.5f (half-extent scale).
// INFERRED: argument roles, from the disassembly:
//   a1 = delta added to the point before clamping
//   a2 = accumulated offset, advanced by the amount clamping moved the point
//   a3 = point, moved by f times that amount
//   a4 = size scale
extern "C" void fn_0046a010(G3D::Vector2* a1, G3D::Vector2* a2, G3D::Vector2* a3,
                            const G3D::Vector2* a4, int margin, float f)
{
    const float kx = a4->x * 0.5f;
    const float ky = 0.5f * a4->y;
    const float m = (float)margin;

    RBX::Rect r(G3D::Vector2(m - kx, m - ky), G3D::Vector2(kx - m, ky - m));

    G3D::Vector2 pos(a3->x, a3->y);
    RBX::Rect other(pos, pos);
    r.unionWith(other);

    // INFERRED: the Rect is laid out as { Vector2 min; Vector2 max; }
    const G3D::Vector2* corners = reinterpret_cast<const G3D::Vector2*>(&r);

    G3D::Vector2 v(a1->x + pos.x, a1->y + pos.y);
    pos = v.clamp(corners[0], corners[1]);

    float dx = v.x - pos.x;
    float dy = v.y - pos.y;

    a3->x = pos.x + dx * f;
    a3->y = pos.y + dy * f;

    a2->x += dx;
    a2->y += dy;
}
