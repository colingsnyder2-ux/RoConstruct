// from server: 100% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 0060e970  unit: RBX::BlockBlockContact  size: 347 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0060e970
//
// 0060e970  6aff                 push -1
// 0060e972  68908d7d00           push 0x7d8d90
// 0060e977  64a100000000         mov eax, dword ptr fs:[0]
// 0060e97d  50                   push eax
// 0060e97e  64892500000000       mov dword ptr fs:[0], esp
// 0060e985  83ec30               sub esp, 0x30
// 0060e988  8b442444             mov eax, dword ptr [esp + 0x44]
// 0060e98c  56                   push esi
// 0060e98d  50                   push eax
// 0060e98e  8d4c241c             lea ecx, [esp + 0x1c]
// 0060e992  51                   push ecx
// 0060e993  e8586f0000           call 0x6158f0
// 0060e998  83c408               add esp, 8
// 0060e99b  8b742450             mov esi, dword ptr [esp + 0x50]
// 0060e99f  8b54244c             mov edx, dword ptr [esp + 0x4c]
// 0060e9a3  8b4c2444             mov ecx, dword ptr [esp + 0x44]
// 0060e9a7  68b8be9700           push 0x97beb8
// 0060e9ac  56                   push esi
// 0060e9ad  6a00                 push 0
// 0060e9af  52                   push edx
// 0060e9b0  8d442428             lea eax, [esp + 0x28]
// 0060e9b4  50                   push eax
// 0060e9b5  c744245000000000     mov dword ptr [esp + 0x50], 0
// 0060e9bd  e81eedffff           call 0x60d6e0
// 0060e9c2  85c0                 test eax, eax
// 0060e9c4  0f85d1000000         jne 0x60ea9b
// 0060e9ca  f60550f0960001       test byte ptr [0x96f050], 1
// 0060e9d1  d9ee                 fldz 
// 0060e9d3  7519                 jne 0x60e9ee
// 0060e9d5  830d50f0960001       or dword ptr [0x96f050], 1
// 0060e9dc  d91544f09600         fst dword ptr [0x96f044]
// 0060e9e2  d91548f09600         fst dword ptr [0x96f048]
// 0060e9e8  d9154cf09600         fst dword ptr [0x96f04c]
// 0060e9ee  f605a428970001       test byte ptr [0x9728a4], 1
// 0060e9f5  751d                 jne 0x60ea14
// 0060e9f7  830da428970001       or dword ptr [0x9728a4], 1
// 0060e9fe  d91598289700         fst dword ptr [0x972898]
// 0060ea04  d9e8                 fld1 
// 0060ea06  d91d9c289700         fstp dword ptr [0x97289c]
// 0060ea0c  d91da0289700         fstp dword ptr [0x9728a0]
// 0060ea12  eb02                 jmp 0x60ea16
// 0060ea14  ddd8                 fstp st(0)
// 0060ea16  6844f09600           push 0x96f044
// 0060ea1b  6898289700           push 0x972898
// 0060ea20  8d4c240c             lea ecx, [esp + 0xc]
// 0060ea24  e8b76ff1ff           call 0x5259e0
// 0060ea29  56                   push esi
// 0060ea2a  50                   push eax
// 0060ea2b  8d4c2420             lea ecx, [esp + 0x20]
// 0060ea2f  51                   push ecx
// 0060ea30  c644244801           mov byte ptr [esp + 0x48], 1
// 0060ea35  e84609fdff           call 0x5df380
// 0060ea3a  83c40c               add esp, 0xc
// 0060ea3d  84c0                 test al, al
// 0060ea3f  0f94c0               sete al
// 0060ea42  c644243c00           mov byte ptr [esp + 0x3c], 0
// 0060ea47  84c0                 test al, al
// 0060ea49  7450                 je 0x60ea9b
// 0060ea4b  f60550f0960001       test byte ptr [0x96f050], 1
// 0060ea52  751b                 jne 0x60ea6f
// 0060ea54  d9ee                 fldz 
// 0060ea56  830d50f0960001       or dword ptr [0x96f050], 1
// 0060ea5d  d91544f09600         fst dword ptr [0x96f044]
// 0060ea63  d91548f09600         fst dword ptr [0x96f048]
// 0060ea69  d91d4cf09600         fstp dword ptr [0x96f04c]
// 0060ea6f  d90544f09600         fld dword ptr [0x96f044]
// 0060ea75  32c0                 xor al, al
// 0060ea77  d91e                 fstp dword ptr [esi]
// 0060ea79  d90548f09600         fld dword ptr [0x96f048]
// 0060ea7f  d95e04               fstp dword ptr [esi + 4]
// 0060ea82  d9054cf09600         fld dword ptr [0x96f04c]
// 0060ea88  d95e08               fstp dword ptr [esi + 8]
// 0060ea8b  5e                   pop esi
// 0060ea8c  8b4c2430             mov ecx, dword ptr [esp + 0x30]
// 0060ea90  64890d00000000       mov dword ptr fs:[0], ecx
// 0060ea97  83c43c               add esp, 0x3c
// 0060ea9a  c3                   ret 
// 0060ea9b  8d542404             lea edx, [esp + 4]
// 0060ea9f  56                   push esi
// 0060eaa0  52                   push edx
// 0060eaa1  e8fa130000           call 0x60fea0
// 0060eaa6  d900                 fld dword ptr [eax]
// 0060eaa8  8b4c243c             mov ecx, dword ptr [esp + 0x3c]
// 0060eaac  d91e                 fstp dword ptr [esi]
// 0060eaae  d94004               fld dword ptr [eax + 4]
// 0060eab1  83c408               add esp, 8
// 0060eab4  d95e04               fstp dword ptr [esi + 4]
// 0060eab7  d94008               fld dword ptr [eax + 8]
// 0060eaba  b001                 mov al, 1
// 0060eabc  d95e08               fstp dword ptr [esi + 8]
// 0060eabf  5e                   pop esi
// 0060eac0  64890d00000000       mov dword ptr fs:[0], ecx
// 0060eac7  83c43c               add esp, 0x3c
// 0060eaca  c3                   ret 

struct Vector3 {
    float x, y, z;
    Vector3();
    Vector3(float, float, float);
    Vector3& operator=(const Vector3&);
    static const Vector3& zero();
    static const Vector3& up();
};

inline Vector3::Vector3() : x(0.0f), y(0.0f), z(0.0f) {}
inline Vector3::Vector3(float a, float b, float c) : x(a), y(b), z(c) {}

inline Vector3& Vector3::operator=(const Vector3& value) {
    x = value.x;
    y = value.y;
    z = value.z;
    return *this;
}

inline const Vector3& Vector3::zero() {
    static const Vector3 value;
    return value;
}

inline const Vector3& Vector3::up() {
    static const Vector3 value(0.0f, 1.0f, 0.0f);
    return value;
}

struct Ray {
    Vector3 origin;
    Vector3 direction;
    virtual ~Ray();
};

inline Ray::~Ray() {}

struct Plane {
    Vector3 normal;
    float distance;
    Plane(const Vector3&, const Vector3&);
    virtual ~Plane();
};

inline Plane::~Plane() {}

struct Contact {
    int query(const Ray&, const void*, int, Vector3*, const void*);
};

extern const unsigned char queryData;
extern Ray __cdecl makeRay(const void*);
extern bool __cdecl intersect(const Ray&, const Plane&, Vector3*);
extern Vector3 __cdecl normalize(const Vector3&);

bool __cdecl calculate(Contact* contact, const void* source,
                       const void* geometry, Vector3* result) {
    Ray ray = makeRay(source);
    if (!contact->query(ray, geometry, 0, result, &queryData)) {
        if (!intersect(ray, Plane(Vector3::up(), Vector3::zero()), result)) {
            *result = Vector3::zero();
            return false;
        }
    }
    *result = normalize(*result);
    return true;
}
