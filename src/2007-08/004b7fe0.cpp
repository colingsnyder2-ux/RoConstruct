// from server: 100% by EspClaude
// from server: 49% by colin
// roc 2007-08 004b7fe0  unit: Exposer  size: 306 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004b7fe0
//
// 004b7fe0  83ec24               sub esp, 0x24
// 004b7fe3  56                   push esi
// 004b7fe4  8b742430             mov esi, dword ptr [esp + 0x30]
// 004b7fe8  57                   push edi
// 004b7fe9  8b7c2430             mov edi, dword ptr [esp + 0x30]
// 004b7fed  d94724               fld dword ptr [edi + 0x24]
// 004b7ff0  d86624               fsub dword ptr [esi + 0x24]
// 004b7ff3  d95c2430             fstp dword ptr [esp + 0x30]
// 004b7ff7  d9442430             fld dword ptr [esp + 0x30]
// 004b7ffb  d9e1                 fabs 
// 004b7ffd  d95c2430             fstp dword ptr [esp + 0x30]
// 004b8001  d9442430             fld dword ptr [esp + 0x30]
// 004b8005  dd0540eb7900         fld qword ptr [0x79eb40]
// 004b800b  d8d1                 fcom st(1)
// 004b800d  dfe0                 fnstsw ax
// 004b800f  ddd9                 fstp st(1)
// 004b8011  f6c405               test ah, 5
// 004b8014  7a0a                 jp 0x4b8020
// 004b8016  ddd8                 fstp st(0)
// 004b8018  5f                   pop edi
// 004b8019  32c0                 xor al, al
// 004b801b  5e                   pop esi
// 004b801c  83c424               add esp, 0x24
// 004b801f  c3                   ret 
// 004b8020  d94728               fld dword ptr [edi + 0x28]
// 004b8023  d86628               fsub dword ptr [esi + 0x28]
// 004b8026  d95c2430             fstp dword ptr [esp + 0x30]
// 004b802a  d9442430             fld dword ptr [esp + 0x30]
// 004b802e  d9e1                 fabs 
// 004b8030  d95c2430             fstp dword ptr [esp + 0x30]
// 004b8034  d9442430             fld dword ptr [esp + 0x30]
// 004b8038  d8d9                 fcomp st(1)
// 004b803a  dfe0                 fnstsw ax
// 004b803c  f6c441               test ah, 0x41
// 004b803f  74d5                 je 0x4b8016
// 004b8041  d9472c               fld dword ptr [edi + 0x2c]
// 004b8044  d8662c               fsub dword ptr [esi + 0x2c]
// 004b8047  d95c2430             fstp dword ptr [esp + 0x30]
// 004b804b  d9442430             fld dword ptr [esp + 0x30]
// 004b804f  d9e1                 fabs 
// 004b8051  d95c2430             fstp dword ptr [esp + 0x30]
// 004b8055  d9442430             fld dword ptr [esp + 0x30]
// 004b8059  ded9                 fcompp 
// 004b805b  dfe0                 fnstsw ax
// 004b805d  f6c441               test ah, 0x41
// 004b8060  74b6                 je 0x4b8018
// 004b8062  d90538eb7900         fld dword ptr [0x79eb38]
// 004b8068  53                   push ebx
// 004b8069  8bde                 mov ebx, esi
// 004b806b  33d2                 xor edx, edx
// 004b806d  8d4f18               lea ecx, [edi + 0x18]
// 004b8070  2bdf                 sub ebx, edi
// 004b8072  d941e8               fld dword ptr [ecx - 0x18]
// 004b8075  d95c240c             fstp dword ptr [esp + 0xc]
// 004b8079  d941f4               fld dword ptr [ecx - 0xc]
// 004b807c  d95c2410             fstp dword ptr [esp + 0x10]
// 004b8080  d901                 fld dword ptr [ecx]
// 004b8082  d95c2414             fstp dword ptr [esp + 0x14]
// 004b8086  d90496               fld dword ptr [esi + edx*4]
// 004b8089  d95c2418             fstp dword ptr [esp + 0x18]
// 004b808d  d944960c             fld dword ptr [esi + edx*4 + 0xc]
// 004b8091  d95c241c             fstp dword ptr [esp + 0x1c]
// 004b8095  d9040b               fld dword ptr [ebx + ecx]
// 004b8098  d95c2420             fstp dword ptr [esp + 0x20]
// 004b809c  d944240c             fld dword ptr [esp + 0xc]
// 004b80a0  d8642418             fsub dword ptr [esp + 0x18]
// 004b80a4  d95c2424             fstp dword ptr [esp + 0x24]
// 004b80a8  d9442410             fld dword ptr [esp + 0x10]
// 004b80ac  d864241c             fsub dword ptr [esp + 0x1c]
// 004b80b0  d95c2428             fstp dword ptr [esp + 0x28]
// 004b80b4  d9442414             fld dword ptr [esp + 0x14]
// 004b80b8  d8642420             fsub dword ptr [esp + 0x20]
// 004b80bc  d95c242c             fstp dword ptr [esp + 0x2c]
// 004b80c0  d9442428             fld dword ptr [esp + 0x28]
// 004b80c4  d9442424             fld dword ptr [esp + 0x24]
// 004b80c8  d944242c             fld dword ptr [esp + 0x2c]
// 004b80cc  d9c1                 fld st(1)
// 004b80ce  deca                 fmulp st(2)
// 004b80d0  d9c2                 fld st(2)
// 004b80d2  decb                 fmulp st(3)
// 004b80d4  d9c9                 fxch st(1)
// 004b80d6  dec2                 faddp st(2)
// 004b80d8  dcc8                 fmul st(0), st(0)
// 004b80da  dec1                 faddp st(1)
// 004b80dc  d95c2434             fstp dword ptr [esp + 0x34]
// 004b80e0  d9442434             fld dword ptr [esp + 0x34]
// 004b80e4  d8d9                 fcomp st(1)
// 004b80e6  dfe0                 fnstsw ax
// 004b80e8  f6c441               test ah, 0x41
// 004b80eb  741a                 je 0x4b8107
// 004b80ed  83c201               add edx, 1
// 004b80f0  83c104               add ecx, 4
// 004b80f3  83fa03               cmp edx, 3
// 004b80f6  0f8c76ffffff         jl 0x4b8072
// 004b80fc  5b                   pop ebx
// 004b80fd  ddd8                 fstp st(0)
// 004b80ff  5f                   pop edi
// 004b8100  b001                 mov al, 1
// 004b8102  5e                   pop esi
// 004b8103  83c424               add esp, 0x24
// 004b8106  c3                   ret 
// 004b8107  5b                   pop ebx
// 004b8108  ddd8                 fstp st(0)
// 004b810a  5f                   pop edi
// 004b810b  32c0                 xor al, al
// 004b810d  5e                   pop esi
// 004b810e  83c424               add esp, 0x24
// 004b8111  c3                   ret 

#include <math.h>

struct Vector3 {
    float x, y, z;
    Vector3() {}
    Vector3(float _x, float _y, float _z) : x(_x), y(_y), z(_z) {}
    Vector3 operator-(const Vector3& v) const { return Vector3(x - v.x, y - v.y, z - v.z); }
    float squaredLength() const { return x * x + y * y + z * z; }
};

struct Matrix3 {
    float elt[3][3];
    Vector3 getColumn(int c) const { return Vector3(elt[0][c], elt[1][c], elt[2][c]); }
};

struct CoordinateFrame {
    Matrix3 rotation;      // +0x00
    Vector3 translation;   // +0x24
};

bool fuzzyEqual(const CoordinateFrame& a, const CoordinateFrame& b)
{
    if (fabs(a.translation.x - b.translation.x) > 0.2f)
        return false;
    if (fabs(a.translation.y - b.translation.y) > 0.2f)
        return false;
    if (fabs(a.translation.z - b.translation.z) > 0.2f)
        return false;
    for (int i = 0; i < 3; ++i) {
        Vector3 c0 = a.rotation.getColumn(i);
        Vector3 c1 = b.rotation.getColumn(i);
        if ((c0 - c1).squaredLength() > 0.1f * 0.1f)
            return false;
    }
    return true;
}
