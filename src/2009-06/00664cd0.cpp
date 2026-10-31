// from server: 100% by EspClaude
// roc 2009-06 00664cd0  unit: RBX::LegacyController::$00W4InputType::?$SurfaceEnumPropDescriptor  size: 167 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00664cd0
//
// 00664cd0  64a100000000         mov eax, dword ptr fs:[0]
// 00664cd6  6aff                 push -1
// 00664cd8  68c8828600           push 0x8682c8
// 00664cdd  50                   push eax
// 00664cde  64892500000000       mov dword ptr fs:[0], esp
// 00664ce5  83ec08               sub esp, 8
// 00664ce8  56                   push esi
// 00664ce9  8bf1                 mov esi, ecx
// 00664ceb  8b06                 mov eax, dword ptr [esi]
// 00664ced  8b4008               mov eax, dword ptr [eax + 8]
// 00664cf0  50                   push eax
// 00664cf1  b9243ca100           mov ecx, 0xa13c24
// 00664cf6  ff15a4e98900         call dword ptr [0x89e9a4]
// 00664cfc  84c0                 test al, al
// 00664cfe  741e                 je 0x664d1e
// 00664d00  83c604               add esi, 4
// 00664d03  56                   push esi
// 00664d04  e8b7ecffff           call 0x6639c0
// 00664d09  8b00                 mov eax, dword ptr [eax]
// 00664d0b  83c404               add esp, 4
// 00664d0e  5e                   pop esi
// 00664d0f  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00664d13  64890d00000000       mov dword ptr fs:[0], ecx
// 00664d1a  83c414               add esp, 0x14
// 00664d1d  c3                   ret 
// 00664d1e  8b0e                 mov ecx, dword ptr [esi]
// 00664d20  894c2404             mov dword ptr [esp + 4], ecx
// 00664d24  8b4e04               mov ecx, dword ptr [esi + 4]
// 00664d27  85c9                 test ecx, ecx
// 00664d29  7409                 je 0x664d34
// 00664d2b  8b11                 mov edx, dword ptr [ecx]
// 00664d2d  8b4208               mov eax, dword ptr [edx + 8]
// 00664d30  ffd0                 call eax
// 00664d32  eb02                 jmp 0x664d36
// 00664d34  33c0                 xor eax, eax
// 00664d36  89442408             mov dword ptr [esp + 8], eax
// 00664d3a  8d4c2404             lea ecx, [esp + 4]
// 00664d3e  c744241400000000     mov dword ptr [esp + 0x14], 0
// 00664d46  e8c5fcffff           call 0x664a10
// 00664d4b  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00664d4f  8b30                 mov esi, dword ptr [eax]
// 00664d51  c7442414ffffffff     mov dword ptr [esp + 0x14], 0xffffffff
// 00664d59  85c9                 test ecx, ecx
// 00664d5b  7408                 je 0x664d65
// 00664d5d  8b11                 mov edx, dword ptr [ecx]
// 00664d5f  8b02                 mov eax, dword ptr [edx]
// 00664d61  6a01                 push 1
// 00664d63  ffd0                 call eax
// 00664d65  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00664d69  8bc6                 mov eax, esi
// 00664d6b  5e                   pop esi
// 00664d6c  64890d00000000       mov dword ptr fs:[0], ecx
// 00664d73  83c414               add esp, 0x14
// 00664d76  c3                   ret 
// copied from an identical function in another client (function ?f@S@ns_ROCX000014@@QAEHXZ)

namespace ns_ROCX000014 {
struct TypeInfo {};
extern bool (__thiscall *type_equal)(const TypeInfo *, const TypeInfo &);
extern TypeInfo string_type;

struct Metadata {
    unsigned char padding[8];
    const TypeInfo* type;
};

struct Value {
    virtual ~Value();
    virtual void reserved();
    virtual Value* clone();
};

extern int* __cdecl access_value(Value**);

struct S {
    Metadata* metadata;
    Value* value;

    S(const S&);
    ~S();
    int* convert();
    int f();
};

inline S::S(const S& other)
{
    *reinterpret_cast<Metadata* volatile*>(&metadata) = other.metadata;

    Value* p = other.value;
    Value* copy;
    if (p)
        copy = p->clone();
    else
        copy = 0;
    value = copy;
}

inline S::~S()
{
    delete value;
}

int S::f()
{
    const TypeInfo* type =
        *reinterpret_cast<const TypeInfo* volatile*>(&metadata->type);
    if (type_equal(&string_type, *type))
        return *access_value(&value);

    S temporary(*this);
    return *temporary.convert();
}
}
