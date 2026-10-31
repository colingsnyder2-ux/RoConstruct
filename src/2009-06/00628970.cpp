// from server: 100% by EspClaude
// roc 2009-06 00628970  unit: RBX::ToolMouseCommand  size: 209 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00628970
//
// 00628970  64a100000000         mov eax, dword ptr fs:[0]
// 00628976  6aff                 push -1
// 00628978  68c8828600           push 0x8682c8
// 0062897d  50                   push eax
// 0062897e  64892500000000       mov dword ptr fs:[0], esp
// 00628985  83ec08               sub esp, 8
// 00628988  56                   push esi
// 00628989  8bf1                 mov esi, ecx
// 0062898b  8b06                 mov eax, dword ptr [esi]
// 0062898d  8b4008               mov eax, dword ptr [eax + 8]
// 00628990  50                   push eax
// 00628991  b98c10a000           mov ecx, 0xa0108c
// 00628996  ff15a4e98900         call dword ptr [0x89e9a4]
// 0062899c  84c0                 test al, al
// 0062899e  7434                 je 0x6289d4
// 006289a0  83c604               add esi, 4
// 006289a3  56                   push esi
// 006289a4  e8e7f6ffff           call 0x628090
// 006289a9  d900                 fld dword ptr [eax]
// 006289ab  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 006289af  d919                 fstp dword ptr [ecx]
// 006289b1  83c404               add esp, 4
// 006289b4  d94004               fld dword ptr [eax + 4]
// 006289b7  5e                   pop esi
// 006289b8  d95904               fstp dword ptr [ecx + 4]
// 006289bb  d94008               fld dword ptr [eax + 8]
// 006289be  8bc1                 mov eax, ecx
// 006289c0  d95908               fstp dword ptr [ecx + 8]
// 006289c3  8b4c2408             mov ecx, dword ptr [esp + 8]
// 006289c7  64890d00000000       mov dword ptr fs:[0], ecx
// 006289ce  83c414               add esp, 0x14
// 006289d1  c20400               ret 4
// 006289d4  8b0e                 mov ecx, dword ptr [esi]
// 006289d6  894c2404             mov dword ptr [esp + 4], ecx
// 006289da  8b4e04               mov ecx, dword ptr [esi + 4]
// 006289dd  85c9                 test ecx, ecx
// 006289df  7409                 je 0x6289ea
// 006289e1  8b11                 mov edx, dword ptr [ecx]
// 006289e3  8b4208               mov eax, dword ptr [edx + 8]
// 006289e6  ffd0                 call eax
// 006289e8  eb02                 jmp 0x6289ec
// 006289ea  33c0                 xor eax, eax
// 006289ec  89442408             mov dword ptr [esp + 8], eax
// 006289f0  8d4c2404             lea ecx, [esp + 4]
// 006289f4  c744241400000000     mov dword ptr [esp + 0x14], 0
// 006289fc  e8ffeefbff           call 0x5e7900
// 00628a01  d900                 fld dword ptr [eax]
// 00628a03  8b74241c             mov esi, dword ptr [esp + 0x1c]
// 00628a07  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00628a0b  d91e                 fstp dword ptr [esi]
// 00628a0d  d94004               fld dword ptr [eax + 4]
// 00628a10  c7442414ffffffff     mov dword ptr [esp + 0x14], 0xffffffff
// 00628a18  d95e04               fstp dword ptr [esi + 4]
// 00628a1b  d94008               fld dword ptr [eax + 8]
// 00628a1e  d95e08               fstp dword ptr [esi + 8]
// 00628a21  85c9                 test ecx, ecx
// 00628a23  7408                 je 0x628a2d
// 00628a25  8b11                 mov edx, dword ptr [ecx]
// 00628a27  8b02                 mov eax, dword ptr [edx]
// 00628a29  6a01                 push 1
// 00628a2b  ffd0                 call eax
// 00628a2d  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00628a31  8bc6                 mov eax, esi
// 00628a33  5e                   pop esi
// 00628a34  64890d00000000       mov dword ptr fs:[0], ecx
// 00628a3b  83c414               add esp, 0x14
// 00628a3e  c20400               ret 4
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
