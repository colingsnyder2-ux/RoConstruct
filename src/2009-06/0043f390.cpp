// from server: 100% by EspClaude
// roc 2009-06 0043f390  unit: 1RBX::Metadata::VReflection::?$FactoryProduct  size: 167 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0043f390
//
// 0043f390  64a100000000         mov eax, dword ptr fs:[0]
// 0043f396  6aff                 push -1
// 0043f398  68c8828600           push 0x8682c8
// 0043f39d  50                   push eax
// 0043f39e  64892500000000       mov dword ptr fs:[0], esp
// 0043f3a5  83ec08               sub esp, 8
// 0043f3a8  56                   push esi
// 0043f3a9  8bf1                 mov esi, ecx
// 0043f3ab  8b06                 mov eax, dword ptr [esi]
// 0043f3ad  8b4008               mov eax, dword ptr [eax + 8]
// 0043f3b0  50                   push eax
// 0043f3b1  b9dcf29d00           mov ecx, 0x9df2dc
// 0043f3b6  ff15a4e98900         call dword ptr [0x89e9a4]
// 0043f3bc  84c0                 test al, al
// 0043f3be  741e                 je 0x43f3de
// 0043f3c0  83c604               add esi, 4
// 0043f3c3  56                   push esi
// 0043f3c4  e89772fdff           call 0x416660
// 0043f3c9  8b00                 mov eax, dword ptr [eax]
// 0043f3cb  83c404               add esp, 4
// 0043f3ce  5e                   pop esi
// 0043f3cf  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0043f3d3  64890d00000000       mov dword ptr fs:[0], ecx
// 0043f3da  83c414               add esp, 0x14
// 0043f3dd  c3                   ret 
// 0043f3de  8b0e                 mov ecx, dword ptr [esi]
// 0043f3e0  894c2404             mov dword ptr [esp + 4], ecx
// 0043f3e4  8b4e04               mov ecx, dword ptr [esi + 4]
// 0043f3e7  85c9                 test ecx, ecx
// 0043f3e9  7409                 je 0x43f3f4
// 0043f3eb  8b11                 mov edx, dword ptr [ecx]
// 0043f3ed  8b4208               mov eax, dword ptr [edx + 8]
// 0043f3f0  ffd0                 call eax
// 0043f3f2  eb02                 jmp 0x43f3f6
// 0043f3f4  33c0                 xor eax, eax
// 0043f3f6  89442408             mov dword ptr [esp + 8], eax
// 0043f3fa  8d4c2404             lea ecx, [esp + 4]
// 0043f3fe  c744241400000000     mov dword ptr [esp + 0x14], 0
// 0043f406  e8e5891a00           call 0x5e7df0
// 0043f40b  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0043f40f  8b30                 mov esi, dword ptr [eax]
// 0043f411  c7442414ffffffff     mov dword ptr [esp + 0x14], 0xffffffff
// 0043f419  85c9                 test ecx, ecx
// 0043f41b  7408                 je 0x43f425
// 0043f41d  8b11                 mov edx, dword ptr [ecx]
// 0043f41f  8b02                 mov eax, dword ptr [edx]
// 0043f421  6a01                 push 1
// 0043f423  ffd0                 call eax
// 0043f425  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0043f429  8bc6                 mov eax, esi
// 0043f42b  5e                   pop esi
// 0043f42c  64890d00000000       mov dword ptr fs:[0], ecx
// 0043f433  83c414               add esp, 0x14
// 0043f436  c3                   ret 
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
