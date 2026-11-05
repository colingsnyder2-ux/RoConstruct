// from server: 100% by EspClaude
// roc 2009-06 0064d230  unit: RBX::VGameSettings::?$GlobalSettingsItem  size: 167 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0064d230
//
// 0064d230  56                   push esi
// 0064d231  8bf1                 mov esi, ecx
// 0064d233  807e0800             cmp byte ptr [esi + 8], 0
// 0064d237  7405                 je 0x64d23e
// 0064d239  e852c40700           call 0x6c9690
// 0064d23e  8b442408             mov eax, dword ptr [esp + 8]
// 0064d242  d9869c000000         fld dword ptr [esi + 0x9c]
// 0064d248  d800                 fadd dword ptr [eax]
// 0064d24a  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0064d24e  d99e9c000000         fstp dword ptr [esi + 0x9c]
// 0064d254  d94004               fld dword ptr [eax + 4]
// 0064d257  d886a0000000         fadd dword ptr [esi + 0xa0]
// 0064d25d  d99ea0000000         fstp dword ptr [esi + 0xa0]
// 0064d263  d94008               fld dword ptr [eax + 8]
// 0064d266  d886a4000000         fadd dword ptr [esi + 0xa4]
// 0064d26c  d99ea4000000         fstp dword ptr [esi + 0xa4]
// 0064d272  d901                 fld dword ptr [ecx]
// 0064d274  d86630               fsub dword ptr [esi + 0x30]
// 0064d277  d94104               fld dword ptr [ecx + 4]
// 0064d27a  d86634               fsub dword ptr [esi + 0x34]
// 0064d27d  d94108               fld dword ptr [ecx + 8]
// 0064d280  d86638               fsub dword ptr [esi + 0x38]
// 0064d283  d94008               fld dword ptr [eax + 8]
// 0064d286  d8ca                 fmul st(2)
// 0064d288  d94004               fld dword ptr [eax + 4]
// 0064d28b  d8ca                 fmul st(2)
// 0064d28d  dee9                 fsubp st(1)
// 0064d28f  d900                 fld dword ptr [eax]
// 0064d291  deca                 fmulp st(2)
// 0064d293  d94008               fld dword ptr [eax + 8]
// 0064d296  d8cc                 fmul st(4)
// 0064d298  deea                 fsubp st(2)
// 0064d29a  d94004               fld dword ptr [eax + 4]
// 0064d29d  decc                 fmulp st(4)
// 0064d29f  d900                 fld dword ptr [eax]
// 0064d2a1  decb                 fmulp st(3)
// 0064d2a3  d9cb                 fxch st(3)
// 0064d2a5  dee2                 fsubrp st(2)
// 0064d2a7  d986a8000000         fld dword ptr [esi + 0xa8]
// 0064d2ad  dec3                 faddp st(3)
// 0064d2af  d9ca                 fxch st(2)
// 0064d2b1  d99ea8000000         fstp dword ptr [esi + 0xa8]
// 0064d2b7  d986ac000000         fld dword ptr [esi + 0xac]
// 0064d2bd  dec2                 faddp st(2)
// 0064d2bf  d9c9                 fxch st(1)
// 0064d2c1  d99eac000000         fstp dword ptr [esi + 0xac]
// 0064d2c7  d886b0000000         fadd dword ptr [esi + 0xb0]
// 0064d2cd  d99eb0000000         fstp dword ptr [esi + 0xb0]
// 0064d2d3  5e                   pop esi
// 0064d2d4  c20800               ret 8
// copied from an identical function in another client (function ?accumulateForce@SimBody@RBX@@QAEXABVVector3@G3D@@0@Z)

// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
namespace G3D {
class Vector3 {
public:
    float x, y, z;
    Vector3() {}
    Vector3(float a, float b, float c) : x(a), y(b), z(c) {}
    Vector3 operator-(const Vector3& v) const { return Vector3(x - v.x, y - v.y, z - v.z); }
    Vector3& operator+=(const Vector3& v) { x += v.x; y += v.y; z += v.z; return *this; }
    Vector3 cross(const Vector3& r) const { return Vector3(y * r.z - z * r.y, z * r.x - x * r.z, x * r.y - y * r.x); }
};
}
namespace RBX {
class Body;
class SimBody {
    void update();
    void updateIfDirty() { if (dirty) update(); }
public:
    Body* body;
    float dt;
    bool dirty;
    float rotation[9];
    G3D::Vector3 translation;
    char rest[0x9c - 0x3c];
    G3D::Vector3 force;
    G3D::Vector3 torque;
    static G3D::Vector3 accumulateInline(const G3D::Vector3& _force, const G3D::Vector3& pvWorld, const G3D::Vector3& worldPos)
    {
        G3D::Vector3 temp = worldPos - pvWorld;
        return temp.cross(_force);
    }
    void accumulateForce(const G3D::Vector3& _force, const G3D::Vector3& worldPos);
};
void SimBody::accumulateForce(const G3D::Vector3& _force, const G3D::Vector3& worldPos)
{
    updateIfDirty();
    force += _force;
    torque += accumulateInline(_force, translation, worldPos);
}
}