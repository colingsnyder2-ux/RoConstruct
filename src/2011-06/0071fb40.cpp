// from server: 100% by Yeetserama
// roc 2011-06 0071fb40  unit: RBX::$01::?$SurfaceDescriptor  size: 167 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0071fb40
//
// 0071fb40  64a100000000         mov eax, dword ptr fs:[0]
// 0071fb46  6aff                 push -1
// 0071fb48  68d86b9f00           push 0x9f6bd8
// 0071fb4d  50                   push eax
// 0071fb4e  64892500000000       mov dword ptr fs:[0], esp
// 0071fb55  83ec08               sub esp, 8
// 0071fb58  56                   push esi
// 0071fb59  8bf1                 mov esi, ecx
// 0071fb5b  8b06                 mov eax, dword ptr [esi]
// 0071fb5d  8b4008               mov eax, dword ptr [eax + 8]
// 0071fb60  50                   push eax
// 0071fb61  b940e9c300           mov ecx, 0xc3e940
// 0071fb66  ff15500aa400         call dword ptr [0xa40a50]
// 0071fb6c  84c0                 test al, al
// 0071fb6e  741e                 je 0x71fb8e
// 0071fb70  83c604               add esi, 4
// 0071fb73  56                   push esi
// 0071fb74  e89782eaff           call 0x5c7e10
// 0071fb79  8b00                 mov eax, dword ptr [eax]
// 0071fb7b  83c404               add esp, 4
// 0071fb7e  5e                   pop esi
// 0071fb7f  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0071fb83  64890d00000000       mov dword ptr fs:[0], ecx
// 0071fb8a  83c414               add esp, 0x14
// 0071fb8d  c3                   ret 
// 0071fb8e  8b0e                 mov ecx, dword ptr [esi]
// 0071fb90  894c2404             mov dword ptr [esp + 4], ecx
// 0071fb94  8b4e04               mov ecx, dword ptr [esi + 4]
// 0071fb97  85c9                 test ecx, ecx
// 0071fb99  7409                 je 0x71fba4
// 0071fb9b  8b11                 mov edx, dword ptr [ecx]
// 0071fb9d  8b4208               mov eax, dword ptr [edx + 8]
// 0071fba0  ffd0                 call eax
// 0071fba2  eb02                 jmp 0x71fba6
// 0071fba4  33c0                 xor eax, eax
// 0071fba6  89442408             mov dword ptr [esp + 8], eax
// 0071fbaa  8d4c2404             lea ecx, [esp + 4]
// 0071fbae  c744241400000000     mov dword ptr [esp + 0x14], 0
// 0071fbb6  e855f7ffff           call 0x71f310
// 0071fbbb  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0071fbbf  8b30                 mov esi, dword ptr [eax]
// 0071fbc1  c7442414ffffffff     mov dword ptr [esp + 0x14], 0xffffffff
// 0071fbc9  85c9                 test ecx, ecx
// 0071fbcb  7408                 je 0x71fbd5
// 0071fbcd  8b11                 mov edx, dword ptr [ecx]
// 0071fbcf  8b02                 mov eax, dword ptr [edx]
// 0071fbd1  6a01                 push 1
// 0071fbd3  ffd0                 call eax
// 0071fbd5  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0071fbd9  8bc6                 mov eax, esi
// 0071fbdb  5e                   pop esi
// 0071fbdc  64890d00000000       mov dword ptr fs:[0], ecx
// 0071fbe3  83c414               add esp, 0x14
// 0071fbe6  c3                   ret 
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
