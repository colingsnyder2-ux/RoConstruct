// from server: 100% by colin
// roc 2007-08 005ac2c0  unit: RBX::World  size: 261 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 005ac2c0
//
// 005ac2c0  83ec30               sub esp, 0x30
// 005ac2c3  8b442438             mov eax, dword ptr [esp + 0x38]
// 005ac2c7  d94004               fld dword ptr [eax + 4]
// 005ac2ca  8b4c243c             mov ecx, dword ptr [esp + 0x3c]
// 005ac2ce  d94008               fld dword ptr [eax + 8]
// 005ac2d1  d95c2410             fstp dword ptr [esp + 0x10]
// 005ac2d5  d9400c               fld dword ptr [eax + 0xc]
// 005ac2d8  d95c2414             fstp dword ptr [esp + 0x14]
// 005ac2dc  d94104               fld dword ptr [ecx + 4]
// 005ac2df  d94108               fld dword ptr [ecx + 8]
// 005ac2e2  d9410c               fld dword ptr [ecx + 0xc]
// 005ac2e5  d95c242c             fstp dword ptr [esp + 0x2c]
// 005ac2e9  d94010               fld dword ptr [eax + 0x10]
// 005ac2ec  d94014               fld dword ptr [eax + 0x14]
// 005ac2ef  d94018               fld dword ptr [eax + 0x18]
// 005ac2f2  d94110               fld dword ptr [ecx + 0x10]
// 005ac2f5  d95c2418             fstp dword ptr [esp + 0x18]
// 005ac2f9  d94114               fld dword ptr [ecx + 0x14]
// 005ac2fc  d94118               fld dword ptr [ecx + 0x18]
// 005ac2ff  d9542420             fst dword ptr [esp + 0x20]
// 005ac303  d9ce                 fxch st(6)
// 005ac305  d8e7                 fsub st(7)
// 005ac307  d91c24               fstp dword ptr [esp]
// 005ac30a  d9cc                 fxch st(4)
// 005ac30c  d8642410             fsub dword ptr [esp + 0x10]
// 005ac310  d95c2404             fstp dword ptr [esp + 4]
// 005ac314  d944242c             fld dword ptr [esp + 0x2c]
// 005ac318  d8642414             fsub dword ptr [esp + 0x14]
// 005ac31c  d95c2408             fstp dword ptr [esp + 8]
// 005ac320  dccc                 fmul st(4), st(0)
// 005ac322  d9c3                 fld st(3)
// 005ac324  d8ca                 fmul st(2)
// 005ac326  dec5                 faddp st(5)
// 005ac328  d9442418             fld dword ptr [esp + 0x18]
// 005ac32c  d8cb                 fmul st(3)
// 005ac32e  dec5                 faddp st(5)
// 005ac330  d9c4                 fld st(4)
// 005ac332  d8cd                 fmul st(5)
// 005ac334  d9e8                 fld1 
// 005ac336  dee1                 fsubrp st(1)
// 005ac338  d9542438             fst dword ptr [esp + 0x38]
// 005ac33c  dc1d08597b00         fcomp qword ptr [0x7b5908]
// 005ac342  dfe0                 fnstsw ax
// 005ac344  f6c441               test ah, 0x41
// 005ac347  8b442434             mov eax, dword ptr [esp + 0x34]
// 005ac34b  755a                 jne 0x5ac3a7
// 005ac34d  d9442408             fld dword ptr [esp + 8]
// 005ac351  d84c2420             fmul dword ptr [esp + 0x20]
// 005ac355  d9442404             fld dword ptr [esp + 4]
// 005ac359  decd                 fmulp st(5)
// 005ac35b  dec4                 faddp st(4)
// 005ac35d  d90424               fld dword ptr [esp]
// 005ac360  d84c2418             fmul dword ptr [esp + 0x18]
// 005ac364  dec4                 faddp st(4)
// 005ac366  d9cb                 fxch st(3)
// 005ac368  d9e0                 fchs 
// 005ac36a  decc                 fmulp st(4)
// 005ac36c  d9442408             fld dword ptr [esp + 8]
// 005ac370  d8cb                 fmul st(3)
// 005ac372  d9442404             fld dword ptr [esp + 4]
// 005ac376  d8ca                 fmul st(2)
// 005ac378  dec1                 faddp st(1)
// 005ac37a  d90424               fld dword ptr [esp]
// 005ac37d  d8cb                 fmul st(3)
// 005ac37f  dec1                 faddp st(1)
// 005ac381  dec4                 faddp st(4)
// 005ac383  d9cb                 fxch st(3)
// 005ac385  d8742438             fdiv dword ptr [esp + 0x38]
// 005ac389  dcc9                 fmul st(1), st(0)
// 005ac38b  dccb                 fmul st(3), st(0)
// 005ac38d  deca                 fmulp st(2)
// 005ac38f  dec3                 faddp st(3)
// 005ac391  d9ca                 fxch st(2)
// 005ac393  d918                 fstp dword ptr [eax]
// 005ac395  d8442410             fadd dword ptr [esp + 0x10]
// 005ac399  d95804               fstp dword ptr [eax + 4]
// 005ac39c  d8442414             fadd dword ptr [esp + 0x14]
// 005ac3a0  d95808               fstp dword ptr [eax + 8]
// 005ac3a3  83c430               add esp, 0x30
// 005ac3a6  c3                   ret 
// 005ac3a7  dddc                 fstp st(4)
// 005ac3a9  ddd9                 fstp st(1)
// 005ac3ab  ddd8                 fstp st(0)
// 005ac3ad  ddd9                 fstp st(1)
// 005ac3af  ddd8                 fstp st(0)
// 005ac3b1  d918                 fstp dword ptr [eax]
// 005ac3b3  d9442410             fld dword ptr [esp + 0x10]
// 005ac3b7  d95804               fstp dword ptr [eax + 4]
// 005ac3ba  d9442414             fld dword ptr [esp + 0x14]
// 005ac3be  d95808               fstp dword ptr [eax + 8]
// 005ac3c1  83c430               add esp, 0x30
// 005ac3c4  c3                   ret 
// copied from an identical function in another client (function ?closestPoint@RBX@@YA?AVVector3@G3D@@ABVRbxRay@1@0@Z)

// from server: 74% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast

namespace G3D {
class Vector3 {
public:
    float x, y, z;
    Vector3() {}
    Vector3(float _x, float _y, float _z) : x(_x), y(_y), z(_z) {}
    Vector3(const Vector3& v) : x(v.x), y(v.y), z(v.z) {}
    Vector3& operator=(const Vector3& v) { x = v.x; y = v.y; z = v.z; return *this; }
    Vector3 operator+(const Vector3& v) const { return Vector3(x + v.x, y + v.y, z + v.z); }
    Vector3 operator-(const Vector3& v) const { return Vector3(x - v.x, y - v.y, z - v.z); }
    Vector3 operator*(float s) const { return Vector3(x * s, y * s, z * s); }
    float dot(const Vector3& v) const { return x * v.x + y * v.y + z * v.z; }
};
}

namespace G3D { inline Vector3 operator*(float s,const Vector3&v){return v*s;} }
namespace RBX {
class RbxRay {
public:
    int reserved;
    G3D::Vector3 origin;
    G3D::Vector3 direction;
};

G3D::Vector3 closestPoint(const RbxRay& pointOnRay, const RbxRay& otherRay)
{
    G3D::Vector3 pa = pointOnRay.origin;
    G3D::Vector3 pPlane = otherRay.origin;
    G3D::Vector3 ua = pointOnRay.direction;
    G3D::Vector3 ub = otherRay.direction;
    G3D::Vector3 p = pPlane - pa;
    float uaub = ua.dot(ub);
    float q1 = ua.dot(p);
    float q2 = -ub.dot(p);
    float d = 1 - uaub*uaub;
    if (d > 1e-5) {
        float alpha = (q1 + uaub*q2) / d;
        return pa + alpha * ua;
    }
    else {
        return pa;
    }
}
}