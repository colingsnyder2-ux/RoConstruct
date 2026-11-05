// from server: 100% by EspClaude
// roc 2009-06 0065fe50  unit: G3D::VCoordinateFrame::?$TypedPropertyDescriptor  size: 209 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0065fe50
//
// 0065fe50  64a100000000         mov eax, dword ptr fs:[0]
// 0065fe56  6aff                 push -1
// 0065fe58  68c8828600           push 0x8682c8
// 0065fe5d  50                   push eax
// 0065fe5e  64892500000000       mov dword ptr fs:[0], esp
// 0065fe65  83ec08               sub esp, 8
// 0065fe68  56                   push esi
// 0065fe69  8bf1                 mov esi, ecx
// 0065fe6b  8b06                 mov eax, dword ptr [esi]
// 0065fe6d  8b4008               mov eax, dword ptr [eax + 8]
// 0065fe70  50                   push eax
// 0065fe71  b9c410a000           mov ecx, 0xa010c4
// 0065fe76  ff15a4e98900         call dword ptr [0x89e9a4]
// 0065fe7c  84c0                 test al, al
// 0065fe7e  7434                 je 0x65feb4
// 0065fe80  83c604               add esi, 4
// 0065fe83  56                   push esi
// 0065fe84  e8b777fdff           call 0x637640
// 0065fe89  d900                 fld dword ptr [eax]
// 0065fe8b  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 0065fe8f  d919                 fstp dword ptr [ecx]
// 0065fe91  83c404               add esp, 4
// 0065fe94  d94004               fld dword ptr [eax + 4]
// 0065fe97  5e                   pop esi
// 0065fe98  d95904               fstp dword ptr [ecx + 4]
// 0065fe9b  d94008               fld dword ptr [eax + 8]
// 0065fe9e  8bc1                 mov eax, ecx
// 0065fea0  d95908               fstp dword ptr [ecx + 8]
// 0065fea3  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0065fea7  64890d00000000       mov dword ptr fs:[0], ecx
// 0065feae  83c414               add esp, 0x14
// 0065feb1  c20400               ret 4
// 0065feb4  8b0e                 mov ecx, dword ptr [esi]
// 0065feb6  894c2404             mov dword ptr [esp + 4], ecx
// 0065feba  8b4e04               mov ecx, dword ptr [esi + 4]
// 0065febd  85c9                 test ecx, ecx
// 0065febf  7409                 je 0x65feca
// 0065fec1  8b11                 mov edx, dword ptr [ecx]
// 0065fec3  8b4208               mov eax, dword ptr [edx + 8]
// 0065fec6  ffd0                 call eax
// 0065fec8  eb02                 jmp 0x65fecc
// 0065feca  33c0                 xor eax, eax
// 0065fecc  89442408             mov dword ptr [esp + 8], eax
// 0065fed0  8d4c2404             lea ecx, [esp + 4]
// 0065fed4  c744241400000000     mov dword ptr [esp + 0x14], 0
// 0065fedc  e84f7af8ff           call 0x5e7930
// 0065fee1  d900                 fld dword ptr [eax]
// 0065fee3  8b74241c             mov esi, dword ptr [esp + 0x1c]
// 0065fee7  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0065feeb  d91e                 fstp dword ptr [esi]
// 0065feed  d94004               fld dword ptr [eax + 4]
// 0065fef0  c7442414ffffffff     mov dword ptr [esp + 0x14], 0xffffffff
// 0065fef8  d95e04               fstp dword ptr [esi + 4]
// 0065fefb  d94008               fld dword ptr [eax + 8]
// 0065fefe  d95e08               fstp dword ptr [esi + 8]
// 0065ff01  85c9                 test ecx, ecx
// 0065ff03  7408                 je 0x65ff0d
// 0065ff05  8b11                 mov edx, dword ptr [ecx]
// 0065ff07  8b02                 mov eax, dword ptr [edx]
// 0065ff09  6a01                 push 1
// 0065ff0b  ffd0                 call eax
// 0065ff0d  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0065ff11  8bc6                 mov eax, esi
// 0065ff13  5e                   pop esi
// 0065ff14  64890d00000000       mov dword ptr fs:[0], ecx
// 0065ff1b  83c414               add esp, 0x14
// 0065ff1e  c20400               ret 4
// copied from an identical function in another client (function ?get@Value@ns_ROCX000001@@QAE?AUVector3@2@XZ)

namespace ns_ROCX000001 {
// from server: 93% by king_originala
struct type_info {};

extern const type_info colorType;
extern bool (__thiscall *compareType)(const type_info*, const type_info&);

struct Vector3 {
    float x, y, z;

    Vector3(float a, float b, float c);
    Vector3(const Vector3& other);
};

inline Vector3::Vector3(float a, float b, float c)
    : x(a), y(b), z(c)
{
}

inline Vector3::Vector3(const Vector3& other)
    : x(other.x), y(other.y), z(other.z)
{
}

struct TypeRecord {
    char padding[8];
    const type_info* info;
};

struct Payload {
    virtual ~Payload();
    virtual void unused();
    virtual Payload* clone();
};

inline Payload* copyPayload(Payload* source)
{
    if (source)
        return source->clone();
    return 0;
}

struct Value;

struct Temporary {
    TypeRecord* type;
    Payload* payload;

    Temporary(const Value& value);
    ~Temporary();
    const Vector3& convert();
};

extern const Vector3& __cdecl extractVector(Payload* const*);

struct Value {
    TypeRecord* type;
    Payload* payload;

    Vector3 get();
};

inline Temporary::Temporary(const Value& value)
{
    type = value.type;
    payload = copyPayload(value.payload);
}

inline Temporary::~Temporary()
{
    if (payload)
        delete payload;
}

Vector3 Value::get()
{
    const type_info* t = type->info;
    if (compareType(&colorType, *t)) {
        const Vector3& v = extractVector(&payload);
        return Vector3(v.x, v.y, v.z);
    }

    Temporary temporary(*this);
    return temporary.convert();
}
}
