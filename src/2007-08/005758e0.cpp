// from server: 91% by EspClaude
// from server: 70% by EspClaude
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-cl: 50727
// from server: 100% by king_originala
// roc 2008-06 005e7f20  unit: RBX::Primitive  size: 212 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005e7f20
//
// 005e7f20  6aff                 push -1
// 005e7f22  6828ae7d00           push 0x7dae28
// 005e7f27  64a100000000         mov eax, dword ptr fs:[0]
// 005e7f2d  50                   push eax
// 005e7f2e  64892500000000       mov dword ptr fs:[0], esp
// 005e7f35  83ec34               sub esp, 0x34
// 005e7f38  56                   push esi
// 005e7f39  8bf1                 mov esi, ecx
// 005e7f3b  57                   push edi
// 005e7f3c  8bbea0000000         mov edi, dword ptr [esi + 0xa0]
// 005e7f42  8bcf                 mov ecx, edi
// 005e7f44  e81714fbff           call 0x599360
// 005e7f49  8b44244c             mov eax, dword ptr [esp + 0x4c]
// 005e7f4d  50                   push eax
// 005e7f4e  8d4c2424             lea ecx, [esp + 0x24]
// 005e7f52  51                   push ecx
// 005e7f53  8d8f94000000         lea ecx, [edi + 0x94]
// 005e7f59  e8120af3ff           call 0x518970
// 005e7f5e  d9ee                 fldz 
// 005e7f60  8b442454             mov eax, dword ptr [esp + 0x54]
// 005e7f64  d9542408             fst dword ptr [esp + 8]
// 005e7f68  8b8e9c000000         mov ecx, dword ptr [esi + 0x9c]
// 005e7f6e  d954240c             fst dword ptr [esp + 0xc]
// 005e7f72  50                   push eax
// 005e7f73  d95c2414             fstp dword ptr [esp + 0x14]
// 005e7f77  8b11                 mov edx, dword ptr [ecx]
// 005e7f79  8b5220               mov edx, dword ptr [edx + 0x20]
// 005e7f7c  8d44240c             lea eax, [esp + 0xc]
// 005e7f80  50                   push eax
// 005e7f81  8d442428             lea eax, [esp + 0x28]
// 005e7f85  50                   push eax
// 005e7f86  c744245000000000     mov dword ptr [esp + 0x50], 0
// 005e7f8e  ffd2                 call edx
// 005e7f90  84c0                 test al, al
// 005e7f92  744b                 je 0x5e7fdf
// 005e7f94  8bb6a0000000         mov esi, dword ptr [esi + 0xa0]
// 005e7f9a  8bce                 mov ecx, esi
// 005e7f9c  e8bf13fbff           call 0x599360
// 005e7fa1  8d442408             lea eax, [esp + 8]
// 005e7fa5  50                   push eax
// 005e7fa6  8d4c2418             lea ecx, [esp + 0x18]
// 005e7faa  51                   push ecx
// 005e7fab  8d8e94000000         lea ecx, [esi + 0x94]
// 005e7fb1  e8eae6e8ff           call 0x4766a0
// 005e7fb6  d900                 fld dword ptr [eax]
// 005e7fb8  8b4c2450             mov ecx, dword ptr [esp + 0x50]
// 005e7fbc  d919                 fstp dword ptr [ecx]
// 005e7fbe  5f                   pop edi
// 005e7fbf  d94004               fld dword ptr [eax + 4]
// 005e7fc2  5e                   pop esi
// 005e7fc3  d95904               fstp dword ptr [ecx + 4]
// 005e7fc6  d94008               fld dword ptr [eax + 8]
// 005e7fc9  b001                 mov al, 1
// 005e7fcb  d95908               fstp dword ptr [ecx + 8]
// 005e7fce  8b4c2434             mov ecx, dword ptr [esp + 0x34]
// 005e7fd2  64890d00000000       mov dword ptr fs:[0], ecx
// 005e7fd9  83c440               add esp, 0x40
// 005e7fdc  c20c00               ret 0xc
// 005e7fdf  8b4c243c             mov ecx, dword ptr [esp + 0x3c]
// 005e7fe3  5f                   pop edi
// 005e7fe4  32c0                 xor al, al
// 005e7fe6  5e                   pop esi
// 005e7fe7  64890d00000000       mov dword ptr fs:[0], ecx
// 005e7fee  83c440               add esp, 0x40
// 005e7ff1  c20c00               ret 0xc

struct Vector3 {
    float x, y, z;
    Vector3& operator=(const Vector3& value);
};

inline Vector3& Vector3::operator=(const Vector3& value)
{
    x = value.x;
    y = value.y;
    z = value.z;
    return *this;
}

struct Ray {
    Vector3 origin;
    Vector3 direction;
    virtual ~Ray();
};

inline Ray::~Ray()
{
}

struct Transform {
    Ray transformRay(const Ray& ray) const;
    Vector3 transformPoint(const Vector3& point) const;
};

struct Source {
    char reserved[0x84];
    Transform transform;
    const void* get();
};

struct Body {
    char reserved[0x64];
    Source* source;
};

struct Shape;
bool __cdecl intersectShape(Shape* shape, const Ray& ray, Vector3& point, float scale);

struct Primitive {
    char reserved[0x1d8];
    Body* body;
    Shape* getShape();
    bool func_005758e0(const Ray& ray, Vector3& point);
};

bool Primitive::func_005758e0(const Ray& ray, Vector3& point)
{
    Source* current = body->source;
    current->get();
    Ray localRay = current->transform.transformRay(ray);
    Vector3 localPoint = { 0.0f, 0.0f, 0.0f };

    if (intersectShape(getShape(), localRay, localPoint, 1.0f)) {
        current = body->source;
        current->get();
        point = current->transform.transformPoint(localPoint);
        return true;
    }
    return false;
}
