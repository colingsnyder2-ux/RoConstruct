// from server: 100% by EspClaude
// roc 2009-06 0040a710  unit: RBX::Reflection::ClassDescriptor  size: 169 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0040a710
//
// 0040a710  64a100000000         mov eax, dword ptr fs:[0]
// 0040a716  6aff                 push -1
// 0040a718  68c8828600           push 0x8682c8
// 0040a71d  50                   push eax
// 0040a71e  64892500000000       mov dword ptr fs:[0], esp
// 0040a725  83ec08               sub esp, 8
// 0040a728  56                   push esi
// 0040a729  8bf1                 mov esi, ecx
// 0040a72b  8b06                 mov eax, dword ptr [esi]
// 0040a72d  8b4008               mov eax, dword ptr [eax + 8]
// 0040a730  50                   push eax
// 0040a731  b904c39d00           mov ecx, 0x9dc304
// 0040a736  ff15a4e98900         call dword ptr [0x89e9a4]
// 0040a73c  84c0                 test al, al
// 0040a73e  741e                 je 0x40a75e
// 0040a740  83c604               add esi, 4
// 0040a743  56                   push esi
// 0040a744  e8b7fcffff           call 0x40a400
// 0040a749  8a00                 mov al, byte ptr [eax]
// 0040a74b  83c404               add esp, 4
// 0040a74e  5e                   pop esi
// 0040a74f  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0040a753  64890d00000000       mov dword ptr fs:[0], ecx
// 0040a75a  83c414               add esp, 0x14
// 0040a75d  c3                   ret 
// 0040a75e  8b0e                 mov ecx, dword ptr [esi]
// 0040a760  894c2404             mov dword ptr [esp + 4], ecx
// 0040a764  8b4e04               mov ecx, dword ptr [esi + 4]
// 0040a767  85c9                 test ecx, ecx
// 0040a769  7409                 je 0x40a774
// 0040a76b  8b11                 mov edx, dword ptr [ecx]
// 0040a76d  8b4208               mov eax, dword ptr [edx + 8]
// 0040a770  ffd0                 call eax
// 0040a772  eb02                 jmp 0x40a776
// 0040a774  33c0                 xor eax, eax
// 0040a776  53                   push ebx
// 0040a777  8944240c             mov dword ptr [esp + 0xc], eax
// 0040a77b  8d4c2408             lea ecx, [esp + 8]
// 0040a77f  c744241800000000     mov dword ptr [esp + 0x18], 0
// 0040a787  e8c4d71d00           call 0x5e7f50
// 0040a78c  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0040a790  8a18                 mov bl, byte ptr [eax]
// 0040a792  c7442418ffffffff     mov dword ptr [esp + 0x18], 0xffffffff
// 0040a79a  85c9                 test ecx, ecx
// 0040a79c  7408                 je 0x40a7a6
// 0040a79e  8b11                 mov edx, dword ptr [ecx]
// 0040a7a0  8b02                 mov eax, dword ptr [edx]
// 0040a7a2  6a01                 push 1
// 0040a7a4  ffd0                 call eax
// 0040a7a6  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0040a7aa  8ac3                 mov al, bl
// 0040a7ac  5b                   pop ebx
// 0040a7ad  5e                   pop esi
// 0040a7ae  64890d00000000       mov dword ptr fs:[0], ecx
// 0040a7b5  83c414               add esp, 0x14
// 0040a7b8  c3                   ret 
// copied from an identical function in another client (function ?get@FactoryProduct@ns_ROCX000065@@QAE_NXZ)

namespace ns_ROCX000065 {
struct TypeInfo;
extern TypeInfo boolType;
extern bool (__thiscall *equalType)(const TypeInfo *, const TypeInfo &);

struct Holder {
    virtual ~Holder();
    virtual const TypeInfo &type() const;
    virtual Holder *clone() const;
};

struct Descriptor {
    unsigned char padding[8];
    const TypeInfo *type;
};

extern bool *__cdecl getStoredBool(Holder **);

inline Holder *cloneHolder(Holder *holder)
{
    if (holder)
        return holder->clone();
    return 0;
}

struct Value {
    Descriptor *descriptor;
    Holder *holder;

    Value(const Value &other);
    ~Value();
    bool *convert();
};

inline Value::Value(const Value &other)
    : descriptor(other.descriptor),
      holder(cloneHolder(other.holder))
{
}

inline Value::~Value()
{
    if (holder)
        delete holder;
}

struct FactoryProduct : Value {
    bool get();
};

bool FactoryProduct::get()
{
    const TypeInfo *typeInfo = descriptor->type;
    if (equalType(&boolType, *typeInfo))
        return *getStoredBool(&holder);

    Value temporary(*this);
    return *temporary.convert();
}
}
