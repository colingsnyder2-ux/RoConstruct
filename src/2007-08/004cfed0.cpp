// from server: 88% by EspClaude
// from server: 55% by Intel
// roc 2007-08 004cfed0  unit: RBX::TextureProxyBase  size: 103 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004cfed0
//
// 004cfed0  83ec08               sub esp, 8
// 004cfed3  8b44240c             mov eax, dword ptr [esp + 0xc]
// 004cfed7  d900                 fld dword ptr [eax]
// 004cfed9  d9e1                 fabs 
// 004cfedb  d95c240c             fstp dword ptr [esp + 0xc]
// 004cfedf  d944240c             fld dword ptr [esp + 0xc]
// 004cfee3  d91c24               fstp dword ptr [esp]
// 004cfee6  d94004               fld dword ptr [eax + 4]
// 004cfee9  d9e1                 fabs 
// 004cfeeb  d95c240c             fstp dword ptr [esp + 0xc]
// 004cfeef  d944240c             fld dword ptr [esp + 0xc]
// 004cfef3  d95c2404             fstp dword ptr [esp + 4]
// 004cfef7  d94008               fld dword ptr [eax + 8]
// 004cfefa  d9e1                 fabs 
// 004cfefc  d95c240c             fstp dword ptr [esp + 0xc]
// 004cff00  d944240c             fld dword ptr [esp + 0xc]
// 004cff04  d95c240c             fstp dword ptr [esp + 0xc]
// 004cff08  d90424               fld dword ptr [esp]
// 004cff0b  d9442404             fld dword ptr [esp + 4]
// 004cff0f  d8d1                 fcom st(1)
// 004cff11  dfe0                 fnstsw ax
// 004cff13  f6c405               test ah, 5
// 004cff16  7a04                 jp 0x4cff1c
// 004cff18  ddd8                 fstp st(0)
// 004cff1a  eb02                 jmp 0x4cff1e
// 004cff1c  ddd9                 fstp st(1)
// 004cff1e  d944240c             fld dword ptr [esp + 0xc]
// 004cff22  d8d1                 fcom st(1)
// 004cff24  dfe0                 fnstsw ax
// 004cff26  f6c405               test ah, 5
// 004cff29  7a06                 jp 0x4cff31
// 004cff2b  ddd8                 fstp st(0)
// 004cff2d  83c408               add esp, 8
// 004cff30  c3                   ret 
// 004cff31  ddd9                 fstp st(1)
// 004cff33  83c408               add esp, 8
#include <math.h>
namespace G3D {
inline double max(double a, double b) { return (a > b) ? a : b; }
class Vector3 { public: float x, y, z;
  Vector3(float a, float b, float c) : x(a), y(b), z(c) {}
  Vector3 abs() const { return Vector3(::fabs(x), ::fabs(y), ::fabs(z)); }
};
}
namespace RBX {
class TextureProxyBase { public: static double maxAbs(const G3D::Vector3& v); };
double TextureProxyBase::maxAbs(const G3D::Vector3& v)
{
    G3D::Vector3 a = v.abs();
    return G3D::max(G3D::max(a.x, a.y), a.z);
}
}
