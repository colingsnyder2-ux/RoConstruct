// from server: 100% by Bob535653
// from server: 99% by EspClaude
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
// from server: 60% by king_originala
// roc 2008-06 00610a60  unit: RBX::BlockBlockContact  size: 399 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00610a60
//
// 00610a60  81ec08010000         sub esp, 0x108
// 00610a66  53                   push ebx
// 00610a67  8b9c2410010000       mov ebx, dword ptr [esp + 0x110]
// 00610a6e  837b0400             cmp dword ptr [ebx + 4], 0
// 00610a72  0f846f010000         je 0x610be7
// 00610a78  8d44247c             lea eax, [esp + 0x7c]
// 00610a7c  53                   push ebx
// 00610a7d  50                   push eax
// 00610a7e  e8edf5ffff           call 0x610070
// 00610a83  d9400c               fld dword ptr [eax + 0xc]
// 00610a86  d800                 fadd dword ptr [eax]
// 00610a88  83c408               add esp, 8
// 00610a8b  f6055463970001       test byte ptr [0x976354], 1
// 00610a92  d94010               fld dword ptr [eax + 0x10]
// 00610a95  d84004               fadd dword ptr [eax + 4]
// 00610a98  d94014               fld dword ptr [eax + 0x14]
// 00610a9b  d84008               fadd dword ptr [eax + 8]
// 00610a9e  d905ac9b8100         fld dword ptr [0x819bac]
// 00610aa4  dccb                 fmul st(3), st(0)
// 00610aa6  d9cb                 fxch st(3)
// 00610aa8  d95c2404             fstp dword ptr [esp + 4]
// 00610aac  d9c9                 fxch st(1)
// 00610aae  d8ca                 fmul st(2)
// 00610ab0  d95c2408             fstp dword ptr [esp + 8]
// 00610ab4  dec9                 fmulp st(1)
// 00610ab6  d95c240c             fstp dword ptr [esp + 0xc]
// 00610aba  7521                 jne 0x610add
// 00610abc  d9e8                 fld1 
// 00610abe  830d5463970001       or dword ptr [0x976354], 1
// 00610ac5  d91548639700         fst dword ptr [0x976348]
// 00610acb  d90504e78100         fld dword ptr [0x81e704]
// 00610ad1  d91d4c639700         fstp dword ptr [0x97634c]
// 00610ad7  d91d50639700         fstp dword ptr [0x976350]
// 00610add  6848639700           push 0x976348
// 00610ae2  8d4c2408             lea ecx, [esp + 8]
// 00610ae6  51                   push ecx
// 00610ae7  8d542418             lea edx, [esp + 0x18]
// 00610aeb  52                   push edx
// 00610aec  e81fe3fcff           call 0x5dee10
// 00610af1  83c40c               add esp, 0xc
// 00610af4  e82733f0ff           call 0x513e20
// 00610af9  50                   push eax
// 00610afa  8d4c2420             lea ecx, [esp + 0x20]
// 00610afe  e81d27f0ff           call 0x513220
// 00610b03  d9442410             fld dword ptr [esp + 0x10]
// 00610b07  f60550f0960001       test byte ptr [0x96f050], 1
// 00610b0e  d95c2440             fstp dword ptr [esp + 0x40]
// 00610b12  d9442414             fld dword ptr [esp + 0x14]
// 00610b16  d95c2444             fstp dword ptr [esp + 0x44]
// 00610b1a  d9442418             fld dword ptr [esp + 0x18]
// 00610b1e  d95c2448             fstp dword ptr [esp + 0x48]
// 00610b22  751b                 jne 0x610b3f
// 00610b24  d9ee                 fldz 
// 00610b26  830d50f0960001       or dword ptr [0x96f050], 1
// 00610b2d  d91544f09600         fst dword ptr [0x96f044]
// 00610b33  d91548f09600         fst dword ptr [0x96f048]
// 00610b39  d91d4cf09600         fstp dword ptr [0x96f04c]
// 00610b3f  8b842414010000       mov eax, dword ptr [esp + 0x114]
// 00610b46  56                   push esi
// 00610b47  50                   push eax
// 00610b48  8d4c2454             lea ecx, [esp + 0x54]
// 00610b4c  e8cf26f0ff           call 0x513220
// 00610b51  d90544f09600         fld dword ptr [0x96f044]
// 00610b57  d95c2474             fstp dword ptr [esp + 0x74]
// 00610b5b  33f6                 xor esi, esi
// 00610b5d  397304               cmp dword ptr [ebx + 4], esi
// 00610b60  d90548f09600         fld dword ptr [0x96f048]
// 00610b66  d95c2478             fstp dword ptr [esp + 0x78]
// 00610b6a  d9054cf09600         fld dword ptr [0x96f04c]
// 00610b70  d95c247c             fstp dword ptr [esp + 0x7c]
// 00610b74  7e70                 jle 0x610be6
// 00610b76  57                   push edi
// 00610b77  8b0b                 mov ecx, dword ptr [ebx]
// 00610b79  8b3cb1               mov edi, dword ptr [ecx + esi*4]
// 00610b7c  8bcf                 mov ecx, edi
// 00610b7e  e83d77fdff           call 0x5e82c0
// 00610b83  50                   push eax
// 00610b84  8d942488000000       lea edx, [esp + 0x88]
// 00610b8b  52                   push edx
// 00610b8c  8d4c242c             lea ecx, [esp + 0x2c]
// 00610b90  e85bddffff           call 0x60e8f0
// 00610b95  8d842484000000       lea eax, [esp + 0x84]
// 00610b9c  50                   push eax
// 00610b9d  8d8c24b8000000       lea ecx, [esp + 0xb8]
// 00610ba4  51                   push ecx
// 00610ba5  8d4c245c             lea ecx, [esp + 0x5c]
// 00610ba9  e8525be6ff           call 0x476700
// 00610bae  8d9424b4000000       lea edx, [esp + 0xb4]
// 00610bb5  52                   push edx
// 00610bb6  8d8424e8000000       lea eax, [esp + 0xe8]
// 00610bbd  50                   push eax
// 00610bbe  8d4c242c             lea ecx, [esp + 0x2c]
// 00610bc2  e8395be6ff           call 0x476700
// 00610bc7  57                   push edi
// 00610bc8  e8b393f8ff           call 0x599f80
// 00610bcd  83c404               add esp, 4
// 00610bd0  8d8c24e4000000       lea ecx, [esp + 0xe4]
// 00610bd7  51                   push ecx
// 00610bd8  8bc8                 mov ecx, eax
// 00610bda  e8c1ccf8ff           call 0x59d8a0
// 00610bdf  46                   inc esi
// 00610be0  3b7304               cmp esi, dword ptr [ebx + 4]
// 00610be3  7c92                 jl 0x610b77
// 00610be5  5f                   pop edi
// 00610be6  5e                   pop esi
// 00610be7  5b                   pop ebx
// 00610be8  81c408010000         add esp, 0x108
// 00610bee  c3                   ret 

struct Vector3 {
    float x, y, z;
    Vector3() {}
    Vector3(float a, float b, float c) : x(a), y(b), z(c) {}
    Vector3(const Vector3& v) : x(v.x), y(v.y), z(v.z) {}
    Vector3 operator+(const Vector3& v) const { return Vector3(x + v.x, y + v.y, z + v.z); }
    Vector3 operator*(float s) const { return Vector3(s * x, s * y, s * z); }
    Vector3 operator/(float s) const { float inv = 1.0f / s; return Vector3(x * inv, y * inv, z * inv); }
    static const Vector3& zero() { static Vector3 v(0.0f, 0.0f, 0.0f); return v; }
};

struct Matrix3 {
    float m[9];
    Matrix3(const Matrix3&);
    static const Matrix3& identity();
};

struct CoordinateFrame {
    Matrix3 rotation;
    Vector3 translation;
    CoordinateFrame(const Matrix3& r, const Vector3& t) : rotation(r), translation(t) {}
    CoordinateFrame toObjectSpace(const CoordinateFrame& c) const;
    CoordinateFrame operator*(const CoordinateFrame& c) const;
};

struct Extents {
    Vector3 low;
    Vector3 high;
    Extents() {}
    Extents(const Extents& e) : low(e.low), high(e.high) {}
    Vector3 center() const { return (high + low) * 0.5f; }
};

struct PartInstance {
    const CoordinateFrame& getCoordinateFrame() const;
};

struct Primitive {
    void setCoordinateFrame(const CoordinateFrame& c);
};

Primitive* getPrimitive(PartInstance* p);

struct PartArray {
    PartInstance** data;
    int count;
    int size() const { return count; }
    PartInstance* operator[](int i) const { return data[i]; }
};

Extents computeExtents(const PartArray& parts);
Vector3 multiply(const Vector3& a, const Vector3& b);

extern unsigned int snapGuard;
extern float snapX;
extern float snapY;
extern float snapZ;
extern const float snapMiddle;

void rotateParts(const PartArray& parts, const Matrix3& rotation)
{
    if (parts.size() == 0)
        return;

    Vector3 center = computeExtents(parts).center();
    if (!(snapGuard & 1)) {
        snapGuard |= 1;
        snapX = 1.0f;
        snapY = snapMiddle;
        snapZ = 1.0f;
    }
    const Vector3& snap = *reinterpret_cast<const Vector3*>(&snapX);
    Vector3 pivot = multiply(center, snap);
    CoordinateFrame origin(Matrix3::identity(), pivot);
    CoordinateFrame change(rotation, Vector3::zero());

    for (int i = 0; i < parts.size(); ++i) {
        PartInstance* part = parts[i];
        CoordinateFrame local = origin.toObjectSpace(part->getCoordinateFrame());
        CoordinateFrame rotated = change * local;
        CoordinateFrame result = origin * rotated;
        Primitive* prim = getPrimitive(part);
        prim->setCoordinateFrame(result);
    }
}
