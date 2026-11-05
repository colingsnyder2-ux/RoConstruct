// from server: 100% by Yeetserama
// roc 2011-06 0071fca0  unit: RBX::$01::?$SurfaceDescriptor  size: 167 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0071fca0
//
// 0071fca0  64a100000000         mov eax, dword ptr fs:[0]
// 0071fca6  6aff                 push -1
// 0071fca8  68d86b9f00           push 0x9f6bd8
// 0071fcad  50                   push eax
// 0071fcae  64892500000000       mov dword ptr fs:[0], esp
// 0071fcb5  83ec08               sub esp, 8
// 0071fcb8  56                   push esi
// 0071fcb9  8bf1                 mov esi, ecx
// 0071fcbb  8b06                 mov eax, dword ptr [esi]
// 0071fcbd  8b4008               mov eax, dword ptr [eax + 8]
// 0071fcc0  50                   push eax
// 0071fcc1  b9dcd8c300           mov ecx, 0xc3d8dc
// 0071fcc6  ff15500aa400         call dword ptr [0xa40a50]
// 0071fccc  84c0                 test al, al
// 0071fcce  741e                 je 0x71fcee
// 0071fcd0  83c604               add esi, 4
// 0071fcd3  56                   push esi
// 0071fcd4  e88741eaff           call 0x5c3e60
// 0071fcd9  8b00                 mov eax, dword ptr [eax]
// 0071fcdb  83c404               add esp, 4
// 0071fcde  5e                   pop esi
// 0071fcdf  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0071fce3  64890d00000000       mov dword ptr fs:[0], ecx
// 0071fcea  83c414               add esp, 0x14
// 0071fced  c3                   ret 
// 0071fcee  8b0e                 mov ecx, dword ptr [esi]
// 0071fcf0  894c2404             mov dword ptr [esp + 4], ecx
// 0071fcf4  8b4e04               mov ecx, dword ptr [esi + 4]
// 0071fcf7  85c9                 test ecx, ecx
// 0071fcf9  7409                 je 0x71fd04
// 0071fcfb  8b11                 mov edx, dword ptr [ecx]
// 0071fcfd  8b4208               mov eax, dword ptr [edx + 8]
// 0071fd00  ffd0                 call eax
// 0071fd02  eb02                 jmp 0x71fd06
// 0071fd04  33c0                 xor eax, eax
// 0071fd06  89442408             mov dword ptr [esp + 8], eax
// 0071fd0a  8d4c2404             lea ecx, [esp + 4]
// 0071fd0e  c744241400000000     mov dword ptr [esp + 0x14], 0
// 0071fd16  e8b5f6ffff           call 0x71f3d0
// 0071fd1b  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0071fd1f  8b30                 mov esi, dword ptr [eax]
// 0071fd21  c7442414ffffffff     mov dword ptr [esp + 0x14], 0xffffffff
// 0071fd29  85c9                 test ecx, ecx
// 0071fd2b  7408                 je 0x71fd35
// 0071fd2d  8b11                 mov edx, dword ptr [ecx]
// 0071fd2f  8b02                 mov eax, dword ptr [edx]
// 0071fd31  6a01                 push 1
// 0071fd33  ffd0                 call eax
// 0071fd35  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0071fd39  8bc6                 mov eax, esi
// 0071fd3b  5e                   pop esi
// 0071fd3c  64890d00000000       mov dword ptr fs:[0], ecx
// 0071fd43  83c414               add esp, 0x14
// 0071fd46  c3                   ret 
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
