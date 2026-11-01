// from server: 100% by Yeetserama
// roc 2010-06 0069e070  unit: RBX::$00W4SurfaceType::?$SurfaceEnumPropDescriptor  size: 167 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0069e070
//
// 0069e070  64a100000000         mov eax, dword ptr fs:[0]
// 0069e076  6aff                 push -1
// 0069e078  6878149800           push 0x981478
// 0069e07d  50                   push eax
// 0069e07e  64892500000000       mov dword ptr fs:[0], esp
// 0069e085  83ec08               sub esp, 8
// 0069e088  56                   push esi
// 0069e089  8bf1                 mov esi, ecx
// 0069e08b  8b06                 mov eax, dword ptr [esi]
// 0069e08d  8b4008               mov eax, dword ptr [eax + 8]
// 0069e090  50                   push eax
// 0069e091  b9ec0cba00           mov ecx, 0xba0cec
// 0069e096  ff15d8a89e00         call dword ptr [0x9ea8d8]
// 0069e09c  84c0                 test al, al
// 0069e09e  741e                 je 0x69e0be
// 0069e0a0  83c604               add esi, 4
// 0069e0a3  56                   push esi
// 0069e0a4  e81706f1ff           call 0x5ae6c0
// 0069e0a9  8b00                 mov eax, dword ptr [eax]
// 0069e0ab  83c404               add esp, 4
// 0069e0ae  5e                   pop esi
// 0069e0af  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0069e0b3  64890d00000000       mov dword ptr fs:[0], ecx
// 0069e0ba  83c414               add esp, 0x14
// 0069e0bd  c3                   ret 
// 0069e0be  8b0e                 mov ecx, dword ptr [esi]
// 0069e0c0  894c2404             mov dword ptr [esp + 4], ecx
// 0069e0c4  8b4e04               mov ecx, dword ptr [esi + 4]
// 0069e0c7  85c9                 test ecx, ecx
// 0069e0c9  7409                 je 0x69e0d4
// 0069e0cb  8b11                 mov edx, dword ptr [ecx]
// 0069e0cd  8b4208               mov eax, dword ptr [edx + 8]
// 0069e0d0  ffd0                 call eax
// 0069e0d2  eb02                 jmp 0x69e0d6
// 0069e0d4  33c0                 xor eax, eax
// 0069e0d6  89442408             mov dword ptr [esp + 8], eax
// 0069e0da  8d4c2404             lea ecx, [esp + 4]
// 0069e0de  c744241400000000     mov dword ptr [esp + 0x14], 0
// 0069e0e6  e825f6ffff           call 0x69d710
// 0069e0eb  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0069e0ef  8b30                 mov esi, dword ptr [eax]
// 0069e0f1  c7442414ffffffff     mov dword ptr [esp + 0x14], 0xffffffff
// 0069e0f9  85c9                 test ecx, ecx
// 0069e0fb  7408                 je 0x69e105
// 0069e0fd  8b11                 mov edx, dword ptr [ecx]
// 0069e0ff  8b02                 mov eax, dword ptr [edx]
// 0069e101  6a01                 push 1
// 0069e103  ffd0                 call eax
// 0069e105  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0069e109  8bc6                 mov eax, esi
// 0069e10b  5e                   pop esi
// 0069e10c  64890d00000000       mov dword ptr fs:[0], ecx
// 0069e113  83c414               add esp, 0x14
// 0069e116  c3                   ret 
// copied from an identical function in another client (function ?f@S@ns_ROCX00000d@@QAEHXZ)

namespace ns_ROCX00000d {
// from server: 100% by king_originala
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
