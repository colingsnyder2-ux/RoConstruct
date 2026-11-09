// from server: 100% by Yeetserama
// roc 2010-06 0069df10  unit: RBX::$00W4SurfaceType::?$SurfaceEnumPropDescriptor  size: 167 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0069df10
//
// 0069df10  64a100000000         mov eax, dword ptr fs:[0]
// 0069df16  6aff                 push -1
// 0069df18  6878149800           push 0x981478
// 0069df1d  50                   push eax
// 0069df1e  64892500000000       mov dword ptr fs:[0], esp
// 0069df25  83ec08               sub esp, 8
// 0069df28  56                   push esi
// 0069df29  8bf1                 mov esi, ecx
// 0069df2b  8b06                 mov eax, dword ptr [esi]
// 0069df2d  8b4008               mov eax, dword ptr [eax + 8]
// 0069df30  50                   push eax
// 0069df31  b9581aba00           mov ecx, 0xba1a58
// 0069df36  ff15d8a89e00         call dword ptr [0x9ea8d8]
// 0069df3c  84c0                 test al, al
// 0069df3e  741e                 je 0x69df5e
// 0069df40  83c604               add esi, 4
// 0069df43  56                   push esi
// 0069df44  e8f740f1ff           call 0x5b2040
// 0069df49  8b00                 mov eax, dword ptr [eax]
// 0069df4b  83c404               add esp, 4
// 0069df4e  5e                   pop esi
// 0069df4f  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0069df53  64890d00000000       mov dword ptr fs:[0], ecx
// 0069df5a  83c414               add esp, 0x14
// 0069df5d  c3                   ret 
// 0069df5e  8b0e                 mov ecx, dword ptr [esi]
// 0069df60  894c2404             mov dword ptr [esp + 4], ecx
// 0069df64  8b4e04               mov ecx, dword ptr [esi + 4]
// 0069df67  85c9                 test ecx, ecx
// 0069df69  7409                 je 0x69df74
// 0069df6b  8b11                 mov edx, dword ptr [ecx]
// 0069df6d  8b4208               mov eax, dword ptr [edx + 8]
// 0069df70  ffd0                 call eax
// 0069df72  eb02                 jmp 0x69df76
// 0069df74  33c0                 xor eax, eax
// 0069df76  89442408             mov dword ptr [esp + 8], eax
// 0069df7a  8d4c2404             lea ecx, [esp + 4]
// 0069df7e  c744241400000000     mov dword ptr [esp + 0x14], 0
// 0069df86  e8c5f6ffff           call 0x69d650
// 0069df8b  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0069df8f  8b30                 mov esi, dword ptr [eax]
// 0069df91  c7442414ffffffff     mov dword ptr [esp + 0x14], 0xffffffff
// 0069df99  85c9                 test ecx, ecx
// 0069df9b  7408                 je 0x69dfa5
// 0069df9d  8b11                 mov edx, dword ptr [ecx]
// 0069df9f  8b02                 mov eax, dword ptr [edx]
// 0069dfa1  6a01                 push 1
// 0069dfa3  ffd0                 call eax
// 0069dfa5  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0069dfa9  8bc6                 mov eax, esi
// 0069dfab  5e                   pop esi
// 0069dfac  64890d00000000       mov dword ptr fs:[0], ecx
// 0069dfb3  83c414               add esp, 0x14
// 0069dfb6  c3                   ret 
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
