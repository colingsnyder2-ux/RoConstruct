// from server: 100% by EspClaude
// from server: 46% by TrollStein
// roc 2007-08 005b41e0  unit: RBX::Assembly  size: 181 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 005b41e0
//
// 005b41e0  81ec90000000         sub esp, 0x90
// 005b41e6  56                   push esi
// 005b41e7  8bf1                 mov esi, ecx
// 005b41e9  d98688000000         fld dword ptr [esi + 0x88]
// 005b41ef  51                   push ecx
// 005b41f0  8d4628               lea eax, [esi + 0x28]
// 005b41f3  d91c24               fstp dword ptr [esp]
// 005b41f6  50                   push eax
// 005b41f7  8d4c246c             lea ecx, [esp + 0x6c]
// 005b41fb  51                   push ecx
// 005b41fc  e84f6dffff           call 0x5aaf50
// 005b4201  83c40c               add esp, 0xc
// 005b4204  50                   push eax
// 005b4205  8d4c2438             lea ecx, [esp + 0x38]
// 005b4209  e8c253f5ff           call 0x5095d0
// 005b420e  d9464c               fld dword ptr [esi + 0x4c]
// 005b4211  d95c2458             fstp dword ptr [esp + 0x58]
// 005b4215  8d542464             lea edx, [esp + 0x64]
// 005b4219  d94650               fld dword ptr [esi + 0x50]
// 005b421c  52                   push edx
// 005b421d  d95c2460             fstp dword ptr [esp + 0x60]
// 005b4221  8d4e58               lea ecx, [esi + 0x58]
// 005b4224  d94654               fld dword ptr [esi + 0x54]
// 005b4227  d95c2464             fstp dword ptr [esp + 0x64]
// 005b422b  e8800eecff           call 0x4750b0
// 005b4230  50                   push eax
// 005b4231  8d442408             lea eax, [esp + 8]
// 005b4235  50                   push eax
// 005b4236  8d4c243c             lea ecx, [esp + 0x3c]
// 005b423a  e8c1efebff           call 0x473200
// 005b423f  8b8c249c000000       mov ecx, dword ptr [esp + 0x9c]
// 005b4246  3b4e0c               cmp ecx, dword ptr [esi + 0xc]
// 005b4249  8bb42498000000       mov esi, dword ptr [esp + 0x98]
// 005b4250  752d                 jne 0x5b427f
// 005b4252  8d542404             lea edx, [esp + 4]
// 005b4256  52                   push edx
// 005b4257  8bce                 mov ecx, esi
// 005b4259  e87253f5ff           call 0x5095d0
// 005b425e  d9442428             fld dword ptr [esp + 0x28]
// 005b4262  d95e24               fstp dword ptr [esi + 0x24]
// 005b4265  8bc6                 mov eax, esi
// 005b4267  d944242c             fld dword ptr [esp + 0x2c]
// 005b426b  d95e28               fstp dword ptr [esi + 0x28]
// 005b426e  d9442430             fld dword ptr [esp + 0x30]
// 005b4272  d95e2c               fstp dword ptr [esi + 0x2c]
// 005b4275  5e                   pop esi
// 005b4276  81c490000000         add esp, 0x90
// 005b427c  c20800               ret 8
// 005b427f  56                   push esi
// 005b4280  8d4c2408             lea ecx, [esp + 8]
// 005b4284  e8270eecff           call 0x4750b0
// 005b4289  8bc6                 mov eax, esi
// 005b428b  5e                   pop esi
// 005b428c  81c490000000         add esp, 0x90

// 0x5095d0 copies 9 dwords (out-of-line Matrix3 copy), 0x5aaf50 is a cdecl
// static returning Matrix3 from (const Vector3&, float), 0x4750b0 is a
// thiscall returning a 0x30-byte frame (inverse), 0x473200 the frame product.
class Vector3 {
public:
    float x, y, z;
    Vector3() {}
    Vector3(const Vector3& v) : x(v.x), y(v.y), z(v.z) {}
};

class Matrix3 {
public:
    float elt[3][3];
    Matrix3(const Matrix3& m);
    static Matrix3 fromAxisAngle(const Vector3& axis, float angle);
};

class CoordinateFrame {
public:
    Matrix3 rotation;
    Vector3 translation;
    CoordinateFrame(const Matrix3& r, const Vector3& t) : rotation(r), translation(t) {}
    CoordinateFrame inverse() const;
    CoordinateFrame operator*(const CoordinateFrame& other) const;
};

namespace RBX {

class Assembly {
    char pad0[0xc];
    int field_0c;
    char pad10[0x18];
    Vector3 axis;           // 0x28
    char pad34[0x18];
    Vector3 position;       // 0x4c
    CoordinateFrame frame;  // 0x58
    float angle;            // 0x88
public:
    CoordinateFrame compute(int id) const;
};

CoordinateFrame Assembly::compute(int id) const
{
    CoordinateFrame cf(Matrix3::fromAxisAngle(axis, angle), position);
    CoordinateFrame result = cf * frame.inverse();
    if (id == field_0c)
        return result;
    return result.inverse();
}

}
