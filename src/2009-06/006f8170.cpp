// from server: 100% by EspClaude
// from server: 100% by colin
// roc 2008-06 0066ced0  unit: RBX::GroupDragTool  size: 253 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0066ced0
//
// 0066ced0  81ec94000000         sub esp, 0x94
// 0066ced6  53                   push ebx
// 0066ced7  8b9c249c000000       mov ebx, dword ptr [esp + 0x9c]
// 0066cede  56                   push esi
// 0066cedf  57                   push edi
// 0066cee0  8bcb                 mov ecx, ebx
// 0066cee2  e8c9bdf2ff           call 0x598cb0
// 0066cee7  8bf0                 mov esi, eax
// 0066cee9  56                   push esi
// 0066ceea  8d4c2420             lea ecx, [esp + 0x20]
// 0066ceee  e82d63eaff           call 0x513220
// 0066cef3  d94624               fld dword ptr [esi + 0x24]
// 0066cef6  8b8c24a8000000       mov ecx, dword ptr [esp + 0xa8]
// 0066cefd  d95c2440             fstp dword ptr [esp + 0x40]
// 0066cf01  d94628               fld dword ptr [esi + 0x28]
// 0066cf04  6a00                 push 0
// 0066cf06  d95c2448             fstp dword ptr [esp + 0x48]
// 0066cf0a  8d442450             lea eax, [esp + 0x50]
// 0066cf0e  d9462c               fld dword ptr [esi + 0x2c]
// 0066cf11  50                   push eax
// 0066cf12  d95c2450             fstp dword ptr [esp + 0x50]
// 0066cf16  e82563eaff           call 0x513240
// 0066cf1b  8d4c241c             lea ecx, [esp + 0x1c]
// 0066cf1f  51                   push ecx
// 0066cf20  8d542450             lea edx, [esp + 0x50]
// 0066cf24  52                   push edx
// 0066cf25  e83616f7ff           call 0x5de560
// 0066cf2a  8bc8                 mov ecx, eax
// 0066cf2c  b856555555           mov eax, 0x55555556
// 0066cf31  f7e9                 imul ecx
// 0066cf33  8bc2                 mov eax, edx
// 0066cf35  c1e81f               shr eax, 0x1f
// 0066cf38  03c2                 add eax, edx
// 0066cf3a  8d1440               lea edx, [eax + eax*2]
// 0066cf3d  2bca                 sub ecx, edx
// 0066cf3f  03c0                 add eax, eax
// 0066cf41  83c404               add esp, 4
// 0066cf44  d9448c20             fld dword ptr [esp + ecx*4 + 0x20]
// 0066cf48  8d542414             lea edx, [esp + 0x14]
// 0066cf4c  d9448c2c             fld dword ptr [esp + ecx*4 + 0x2c]
// 0066cf50  d9448c38             fld dword ptr [esp + ecx*4 + 0x38]
// 0066cf54  b901000000           mov ecx, 1
// 0066cf59  2bc8                 sub ecx, eax
// 0066cf5b  894c2410             mov dword ptr [esp + 0x10], ecx
// 0066cf5f  8d44245c             lea eax, [esp + 0x5c]
// 0066cf63  db442410             fild dword ptr [esp + 0x10]
// 0066cf67  d9c0                 fld st(0)
// 0066cf69  decc                 fmulp st(4)
// 0066cf6b  d9cb                 fxch st(3)
// 0066cf6d  d95c2414             fstp dword ptr [esp + 0x14]
// 0066cf71  d9c2                 fld st(2)
// 0066cf73  deca                 fmulp st(2)
// 0066cf75  d9c9                 fxch st(1)
// 0066cf77  d95c2418             fstp dword ptr [esp + 0x18]
// 0066cf7b  dec9                 fmulp st(1)
// 0066cf7d  d95c241c             fstp dword ptr [esp + 0x1c]
// 0066cf81  d90574e38100         fld dword ptr [0x81e374]
// 0066cf87  d91c24               fstp dword ptr [esp]
// 0066cf8a  52                   push edx
// 0066cf8b  50                   push eax
// 0066cf8c  e8ef66eaff           call 0x513680
// 0066cf91  83c40c               add esp, 0xc
// 0066cf94  8d4c241c             lea ecx, [esp + 0x1c]
// 0066cf98  51                   push ecx
// 0066cf99  8d942480000000       lea edx, [esp + 0x80]
// 0066cfa0  52                   push edx
// 0066cfa1  8d4c2460             lea ecx, [esp + 0x60]
// 0066cfa5  e8a663eaff           call 0x513350
// 0066cfaa  8bf0                 mov esi, eax
// 0066cfac  b909000000           mov ecx, 9
// 0066cfb1  8d7c241c             lea edi, [esp + 0x1c]
// 0066cfb5  8d44241c             lea eax, [esp + 0x1c]
// 0066cfb9  f3a5                 rep movsd dword ptr es:[edi], dword ptr [esi]
// 0066cfbb  50                   push eax
// 0066cfbc  8bcb                 mov ecx, ebx
// 0066cfbe  e8dd08f3ff           call 0x59d8a0
// 0066cfc3  5f                   pop edi
// 0066cfc4  5e                   pop esi
// 0066cfc5  5b                   pop ebx
// 0066cfc6  81c494000000         add esp, 0x94
// 0066cfcc  c3                   ret 

#pragma float_control(precise, off, push)

struct Vector3 {
    float x, y, z;

    Vector3(float a, float b, float c);
    Vector3(const Vector3& v);
    Vector3 operator*(float s) const;
    Vector3& operator*=(float s);
};

inline Vector3::Vector3(float a, float b, float c)
    : x(a), y(b), z(c)
{
}

inline Vector3::Vector3(const Vector3& v)
    : x(v.x), y(v.y), z(v.z)
{
}

inline Vector3 Vector3::operator*(float s) const
{
    return Vector3(x * s, y * s, z * s);
}

inline Vector3& Vector3::operator*=(float s)
{
    x *= s;
    y *= s;
    z *= s;
    return *this;
}

struct Matrix3 {
    float m[3][3];

    Matrix3(const Matrix3&);
    Vector3 column(int) const;
    Matrix3 operator*(const Matrix3&) const;
    static Matrix3 fromAxisAngle(const Vector3&, float);
};

struct Frame {
    Matrix3 rotation;
    Vector3 translation;
};

struct Object {
    const Frame& getFrame() const;
    void setFrame(const Frame&);
};

extern int __cdecl closestAxis(const Vector3&, const Frame&);
extern const float rotationAngle;

void __cdecl rotateFrame(Object* object, const Matrix3& reference)
{
    Frame frame = object->getFrame();
    Vector3 direction = reference.column(0);
    int face = closestAxis(direction, frame);
    int column = face % 3;

    Vector3 axis(frame.rotation.m[0][column],
                frame.rotation.m[1][column],
                frame.rotation.m[2][column]);
    axis *= float(1 - 2 * (face / 3));

    Matrix3 rotation = Matrix3::fromAxisAngle(axis, rotationAngle);
    frame.rotation = rotation * frame.rotation;
    object->setFrame(frame);
}

#pragma float_control(pop)