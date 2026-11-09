// from server: 100% by Yeetserama
// roc 2010-06 0040a930  unit: RBX::Reflection::ClassDescriptor  size: 169 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0040a930
//
// 0040a930  64a100000000         mov eax, dword ptr fs:[0]
// 0040a936  6aff                 push -1
// 0040a938  6878149800           push 0x981478
// 0040a93d  50                   push eax
// 0040a93e  64892500000000       mov dword ptr fs:[0], esp
// 0040a945  83ec08               sub esp, 8
// 0040a948  56                   push esi
// 0040a949  8bf1                 mov esi, ecx
// 0040a94b  8b06                 mov eax, dword ptr [esi]
// 0040a94d  8b4008               mov eax, dword ptr [eax + 8]
// 0040a950  50                   push eax
// 0040a951  b93c93b700           mov ecx, 0xb7933c
// 0040a956  ff15d8a89e00         call dword ptr [0x9ea8d8]
// 0040a95c  84c0                 test al, al
// 0040a95e  741e                 je 0x40a97e
// 0040a960  83c604               add esi, 4
// 0040a963  56                   push esi
// 0040a964  e8b7fcffff           call 0x40a620
// 0040a969  8a00                 mov al, byte ptr [eax]
// 0040a96b  83c404               add esp, 4
// 0040a96e  5e                   pop esi
// 0040a96f  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0040a973  64890d00000000       mov dword ptr fs:[0], ecx
// 0040a97a  83c414               add esp, 0x14
// 0040a97d  c3                   ret 
// 0040a97e  8b0e                 mov ecx, dword ptr [esi]
// 0040a980  894c2404             mov dword ptr [esp + 4], ecx
// 0040a984  8b4e04               mov ecx, dword ptr [esi + 4]
// 0040a987  85c9                 test ecx, ecx
// 0040a989  7409                 je 0x40a994
// 0040a98b  8b11                 mov edx, dword ptr [ecx]
// 0040a98d  8b4208               mov eax, dword ptr [edx + 8]
// 0040a990  ffd0                 call eax
// 0040a992  eb02                 jmp 0x40a996
// 0040a994  33c0                 xor eax, eax
// 0040a996  53                   push ebx
// 0040a997  8944240c             mov dword ptr [esp + 0xc], eax
// 0040a99b  8d4c2408             lea ecx, [esp + 8]
// 0040a99f  c744241800000000     mov dword ptr [esp + 0x18], 0
// 0040a9a7  e824e21900           call 0x5a8bd0
// 0040a9ac  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0040a9b0  8a18                 mov bl, byte ptr [eax]
// 0040a9b2  c7442418ffffffff     mov dword ptr [esp + 0x18], 0xffffffff
// 0040a9ba  85c9                 test ecx, ecx
// 0040a9bc  7408                 je 0x40a9c6
// 0040a9be  8b11                 mov edx, dword ptr [ecx]
// 0040a9c0  8b02                 mov eax, dword ptr [edx]
// 0040a9c2  6a01                 push 1
// 0040a9c4  ffd0                 call eax
// 0040a9c6  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0040a9ca  8ac3                 mov al, bl
// 0040a9cc  5b                   pop ebx
// 0040a9cd  5e                   pop esi
// 0040a9ce  64890d00000000       mov dword ptr fs:[0], ecx
// 0040a9d5  83c414               add esp, 0x14
// 0040a9d8  c3                   ret 
// copied from an identical function in another client (function ?get@FactoryProduct@ns_ROCX000006@@QAE_NXZ)

namespace ns_ROCX000006 {
// from server: 100% by colin
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
