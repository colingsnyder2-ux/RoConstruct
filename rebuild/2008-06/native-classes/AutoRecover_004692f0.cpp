// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
namespace G3D {
// INFERRED: minimal Vector2 layout (x, y floats) from the [eax]/[eax+4] accesses
class Vector2 {
public:
    float x, y;
    static const Vector2& zero();
};
}

extern "C" void fn_004692f0(const G3D::Vector2* a, G3D::Vector2* b, G3D::Vector2* c)
{
    // INFERRED: arg roles from stack slots esp+4, esp+8, esp+0xc
    const G3D::Vector2& z = G3D::Vector2::zero();
    b->x = z.x;
    b->y = z.y;
    c->x = a->x + c->x;
    c->y = a->y + c->y;
}
