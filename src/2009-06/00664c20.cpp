// from server: 100% by EspClaude
// roc 2009-06 00664c20  unit: RBX::LegacyController::$00W4InputType::?$SurfaceEnumPropDescriptor  size: 167 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00664c20
//
// 00664c20  64a100000000         mov eax, dword ptr fs:[0]
// 00664c26  6aff                 push -1
// 00664c28  68c8828600           push 0x8682c8
// 00664c2d  50                   push eax
// 00664c2e  64892500000000       mov dword ptr fs:[0], esp
// 00664c35  83ec08               sub esp, 8
// 00664c38  56                   push esi
// 00664c39  8bf1                 mov esi, ecx
// 00664c3b  8b06                 mov eax, dword ptr [esi]
// 00664c3d  8b4008               mov eax, dword ptr [eax + 8]
// 00664c40  50                   push eax
// 00664c41  b9043ca100           mov ecx, 0xa13c04
// 00664c46  ff15a4e98900         call dword ptr [0x89e9a4]
// 00664c4c  84c0                 test al, al
// 00664c4e  741e                 je 0x664c6e
// 00664c50  83c604               add esi, 4
// 00664c53  56                   push esi
// 00664c54  e877ebffff           call 0x6637d0
// 00664c59  8b00                 mov eax, dword ptr [eax]
// 00664c5b  83c404               add esp, 4
// 00664c5e  5e                   pop esi
// 00664c5f  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00664c63  64890d00000000       mov dword ptr fs:[0], ecx
// 00664c6a  83c414               add esp, 0x14
// 00664c6d  c3                   ret 
// 00664c6e  8b0e                 mov ecx, dword ptr [esi]
// 00664c70  894c2404             mov dword ptr [esp + 4], ecx
// 00664c74  8b4e04               mov ecx, dword ptr [esi + 4]
// 00664c77  85c9                 test ecx, ecx
// 00664c79  7409                 je 0x664c84
// 00664c7b  8b11                 mov edx, dword ptr [ecx]
// 00664c7d  8b4208               mov eax, dword ptr [edx + 8]
// 00664c80  ffd0                 call eax
// 00664c82  eb02                 jmp 0x664c86
// 00664c84  33c0                 xor eax, eax
// 00664c86  89442408             mov dword ptr [esp + 8], eax
// 00664c8a  8d4c2404             lea ecx, [esp + 4]
// 00664c8e  c744241400000000     mov dword ptr [esp + 0x14], 0
// 00664c96  e8a5fcffff           call 0x664940
// 00664c9b  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00664c9f  8b30                 mov esi, dword ptr [eax]
// 00664ca1  c7442414ffffffff     mov dword ptr [esp + 0x14], 0xffffffff
// 00664ca9  85c9                 test ecx, ecx
// 00664cab  7408                 je 0x664cb5
// 00664cad  8b11                 mov edx, dword ptr [ecx]
// 00664caf  8b02                 mov eax, dword ptr [edx]
// 00664cb1  6a01                 push 1
// 00664cb3  ffd0                 call eax
// 00664cb5  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00664cb9  8bc6                 mov eax, esi
// 00664cbb  5e                   pop esi
// 00664cbc  64890d00000000       mov dword ptr fs:[0], ecx
// 00664cc3  83c414               add esp, 0x14
// 00664cc6  c3                   ret 
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
