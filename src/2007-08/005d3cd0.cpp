// from server: 100% by EspClaude
// from server: 51% by colin
// roc 2007-08 005d3cd0  unit: RBX::Tool  size: 366 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 005d3cd0
//
// 005d3cd0  83ec6c               sub esp, 0x6c
// 005d3cd3  56                   push esi
// 005d3cd4  57                   push edi
// 005d3cd5  8bf9                 mov edi, ecx
// 005d3cd7  8db774010000         lea esi, [edi + 0x174]
// 005d3cdd  56                   push esi
// 005d3cde  8d4c2448             lea ecx, [esp + 0x48]
// 005d3ce2  e8e958f3ff           call 0x5095d0
// 005d3ce7  d94624               fld dword ptr [esi + 0x24]
// 005d3cea  d95c2468             fstp dword ptr [esp + 0x68]
// 005d3cee  6a00                 push 0
// 005d3cf0  d94628               fld dword ptr [esi + 0x28]
// 005d3cf3  8d442430             lea eax, [esp + 0x30]
// 005d3cf7  d95c2470             fstp dword ptr [esp + 0x70]
// 005d3cfb  50                   push eax
// 005d3cfc  d9462c               fld dword ptr [esi + 0x2c]
// 005d3cff  8d4c244c             lea ecx, [esp + 0x4c]
// 005d3d03  d95c2478             fstp dword ptr [esp + 0x78]
// 005d3d07  e83459f3ff           call 0x509640
// 005d3d0c  6a02                 push 2
// 005d3d0e  8d4c243c             lea ecx, [esp + 0x3c]
// 005d3d12  51                   push ecx
// 005d3d13  8d4c244c             lea ecx, [esp + 0x4c]
// 005d3d17  e82459f3ff           call 0x509640
// 005d3d1c  8b442478             mov eax, dword ptr [esp + 0x78]
// 005d3d20  d94008               fld dword ptr [eax + 8]
// 005d3d23  51                   push ecx
// 005d3d24  d94004               fld dword ptr [eax + 4]
// 005d3d27  8d4c240c             lea ecx, [esp + 0xc]
// 005d3d2b  d900                 fld dword ptr [eax]
// 005d3d2d  dcc8                 fmul st(0), st(0)
// 005d3d2f  d9c1                 fld st(1)
// 005d3d31  deca                 fmulp st(2)
// 005d3d33  dec1                 faddp st(1)
// 005d3d35  d9c1                 fld st(1)
// 005d3d37  deca                 fmulp st(2)
// 005d3d39  dec1                 faddp st(1)
// 005d3d3b  d9fa                 fsqrt 
// 005d3d3d  d9e8                 fld1 
// 005d3d3f  def1                 fdivrp st(1)
// 005d3d41  d900                 fld dword ptr [eax]
// 005d3d43  d8c9                 fmul st(1)
// 005d3d45  d9542418             fst dword ptr [esp + 0x18]
// 005d3d49  d94004               fld dword ptr [eax + 4]
// 005d3d4c  d8ca                 fmul st(2)
// 005d3d4e  d954241c             fst dword ptr [esp + 0x1c]
// 005d3d52  d94008               fld dword ptr [eax + 8]
// 005d3d55  decb                 fmulp st(3)
// 005d3d57  d9ca                 fxch st(2)
// 005d3d59  d9542420             fst dword ptr [esp + 0x20]
// 005d3d5d  d9442434             fld dword ptr [esp + 0x34]
// 005d3d61  d9c0                 fld st(0)
// 005d3d63  d8ca                 fmul st(2)
// 005d3d65  d9442438             fld dword ptr [esp + 0x38]
// 005d3d69  d9c0                 fld st(0)
// 005d3d6b  d8ce                 fmul st(6)
// 005d3d6d  deea                 fsubp st(2)
// 005d3d6f  d9c9                 fxch st(1)
// 005d3d71  d95c240c             fstp dword ptr [esp + 0xc]
// 005d3d75  d8cb                 fmul st(3)
// 005d3d77  d9442430             fld dword ptr [esp + 0x30]
// 005d3d7b  dccb                 fmul st(3), st(0)
// 005d3d7d  d9c9                 fxch st(1)
// 005d3d7f  dee3                 fsubrp st(3)
// 005d3d81  d9ca                 fxch st(2)
// 005d3d83  d95c2410             fstp dword ptr [esp + 0x10]
// 005d3d87  d9cb                 fxch st(3)
// 005d3d89  dec9                 fmulp st(1)
// 005d3d8b  d9ca                 fxch st(2)
// 005d3d8d  dec9                 fmulp st(1)
// 005d3d8f  dee9                 fsubp st(1)
// 005d3d91  d95c2414             fstp dword ptr [esp + 0x14]
// 005d3d95  d90550fe7900         fld dword ptr [0x79fe50]
// 005d3d9b  d91c24               fstp dword ptr [esp]
// 005d3d9e  e8fdb5f3ff           call 0x50f3a0
// 005d3da3  ddd8                 fstp st(0)
// 005d3da5  d9442410             fld dword ptr [esp + 0x10]
// 005d3da9  d9c0                 fld st(0)
// 005d3dab  d9442418             fld dword ptr [esp + 0x18]
// 005d3daf  dcc9                 fmul st(1), st(0)
// 005d3db1  d944240c             fld dword ptr [esp + 0xc]
// 005d3db5  d9c0                 fld st(0)
// 005d3db7  d944241c             fld dword ptr [esp + 0x1c]
// 005d3dbb  51                   push ecx
// 005d3dbc  dcc9                 fmul st(1), st(0)
// 005d3dbe  8d4c2424             lea ecx, [esp + 0x24]
// 005d3dc2  d9cc                 fxch st(4)
// 005d3dc4  dee1                 fsubrp st(1)
// 005d3dc6  d95c2424             fstp dword ptr [esp + 0x24]
// 005d3dca  d944240c             fld dword ptr [esp + 0xc]
// 005d3dce  dccb                 fmul st(3), st(0)
// 005d3dd0  d9442418             fld dword ptr [esp + 0x18]
// 005d3dd4  dccd                 fmul st(5), st(0)
// 005d3dd6  d9cc                 fxch st(4)
// 005d3dd8  dee5                 fsubrp st(5)
// 005d3dda  d9cc                 fxch st(4)
// 005d3ddc  d95c2428             fstp dword ptr [esp + 0x28]
// 005d3de0  deca                 fmulp st(2)
// 005d3de2  deca                 fmulp st(2)
// 005d3de4  dee1                 fsubrp st(1)
// 005d3de6  d95c242c             fstp dword ptr [esp + 0x2c]
// 005d3dea  d90550fe7900         fld dword ptr [0x79fe50]
// 005d3df0  d91c24               fstp dword ptr [esp]
// 005d3df3  e8a8b5f3ff           call 0x50f3a0
// 005d3df8  8d542420             lea edx, [esp + 0x20]
// 005d3dfc  ddd8                 fstp st(0)
// 005d3dfe  52                   push edx
// 005d3dff  6a00                 push 0
// 005d3e01  8d4c244c             lea ecx, [esp + 0x4c]
// 005d3e05  e85658f3ff           call 0x509660
// 005d3e0a  8d442414             lea eax, [esp + 0x14]
// 005d3e0e  50                   push eax
// 005d3e0f  6a01                 push 1
// 005d3e11  8d4c244c             lea ecx, [esp + 0x4c]
// 005d3e15  e84658f3ff           call 0x509660
// 005d3e1a  8d4c2408             lea ecx, [esp + 8]
// 005d3e1e  51                   push ecx
// 005d3e1f  6a02                 push 2
// 005d3e21  8d4c244c             lea ecx, [esp + 0x4c]
// 005d3e25  e83658f3ff           call 0x509660
// 005d3e2a  8d542444             lea edx, [esp + 0x44]
// 005d3e2e  52                   push edx
// 005d3e2f  8bcf                 mov ecx, edi
// 005d3e31  e83afcffff           call 0x5d3a70
// 005d3e36  5f                   pop edi
// 005d3e37  5e                   pop esi
// 005d3e38  83c46c               add esp, 0x6c
// 005d3e3b  c20400               ret 4

// roc-flags: /O2 /GS /EHsc /MD /fp:fast
#include <math.h>

namespace G3D {
class Vector3 {
public:
    float x, y, z;
    Vector3() {}
    Vector3(float _x, float _y, float _z) : x(_x), y(_y), z(_z) {}
    float squaredLength() const { return x * x + y * y + z * z; }
    Vector3 direction() const {
        float lenSquared = squaredLength();
        float invSqrt = 1.0f / sqrtf(lenSquared);
        return Vector3(x * invSqrt, y * invSqrt, z * invSqrt);
    }
    Vector3 cross(const Vector3& r) const {
        return Vector3(y * r.z - z * r.y, z * r.x - x * r.z, x * r.y - y * r.x);
    }
    float unitize(float tolerance = 1e-06f);
};
class Matrix3 {
public:
    float elt[3][3];
    Matrix3(const Matrix3& m);
    Vector3 getColumn(int c) const;
    void setColumn(int c, const Vector3& v);
};
class CoordinateFrame {
public:
    Matrix3 rotation;
    Vector3 translation;
    CoordinateFrame(const CoordinateFrame& s) : rotation(s.rotation) {
        translation.x = s.translation.x;
        translation.y = s.translation.y;
        translation.z = s.translation.z;
    }
};
}

namespace RBX {
class Tool {
    char pad_[0x174];
    G3D::CoordinateFrame grip;          // +0x174 (read by the target)
public:
    void setGrip(const G3D::CoordinateFrame& c);
    void setGripForward(const G3D::Vector3& look);
};

void Tool::setGripForward(const G3D::Vector3& look)
{
    G3D::CoordinateFrame c = grip;
    G3D::Vector3 right = c.rotation.getColumn(0);
    G3D::Vector3 back = c.rotation.getColumn(2);
    G3D::Vector3 up = look.direction();
    G3D::Vector3 z = right.cross(up);
    z.unitize();
    G3D::Vector3 x = up.cross(z);
    x.unitize();
    c.rotation.setColumn(0, x);
    c.rotation.setColumn(1, up);
    c.rotation.setColumn(2, z);
    setGrip(c);
}
}
