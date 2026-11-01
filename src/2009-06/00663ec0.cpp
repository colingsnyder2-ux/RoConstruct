// from server: 100% by EspClaude
// roc 2009-06 00663ec0  unit: RBX::LegacyController::$00W4InputType::?$SurfaceEnumPropDescriptor  size: 163 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00663ec0
//
// 00663ec0  6aff                 push -1
// 00663ec2  68f8a28500           push 0x85a2f8
// 00663ec7  64a100000000         mov eax, dword ptr fs:[0]
// 00663ecd  50                   push eax
// 00663ece  64892500000000       mov dword ptr fs:[0], esp
// 00663ed5  51                   push ecx
// 00663ed6  56                   push esi
// 00663ed7  57                   push edi
// 00663ed8  8bf1                 mov esi, ecx
// 00663eda  6800f75e00           push 0x5ef700
// 00663edf  68eca4a400           push 0xa4a4ec
// 00663ee4  89742410             mov dword ptr [esp + 0x10], esi
// 00663ee8  e823d8d9ff           call 0x401710
// 00663eed  83c408               add esp, 8
// 00663ef0  e8abb7f8ff           call 0x5ef6a0
// 00663ef5  8bf8                 mov edi, eax
// 00663ef7  e87469f8ff           call 0x5ea870
// 00663efc  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 00663f00  8b542420             mov edx, dword ptr [esp + 0x20]
// 00663f04  51                   push ecx
// 00663f05  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 00663f09  52                   push edx
// 00663f0a  51                   push ecx
// 00663f0b  57                   push edi
// 00663f0c  50                   push eax
// 00663f0d  8bce                 mov ecx, esi
// 00663f0f  e81c49f9ff           call 0x5f8830
// 00663f14  897e18               mov dword ptr [esi + 0x18], edi
// 00663f17  6a0c                 push 0xc
// 00663f19  c744241800000000     mov dword ptr [esp + 0x18], 0
// 00663f21  c70604208e00         mov dword ptr [esi], 0x8e2004
// 00663f27  e80c4b0b00           call 0x718a38
// 00663f2c  83c404               add esp, 4
// 00663f2f  85c0                 test eax, eax
// 00663f31  7416                 je 0x663f49
// 00663f33  8b542424             mov edx, dword ptr [esp + 0x24]
// 00663f37  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 00663f3b  c700e41a8e00         mov dword ptr [eax], 0x8e1ae4
// 00663f41  895004               mov dword ptr [eax + 4], edx
// 00663f44  894808               mov dword ptr [eax + 8], ecx
// 00663f47  eb02                 jmp 0x663f4b
// 00663f49  33c0                 xor eax, eax
// 00663f4b  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00663f4f  89461c               mov dword ptr [esi + 0x1c], eax
// 00663f52  5f                   pop edi
// 00663f53  8bc6                 mov eax, esi
// 00663f55  5e                   pop esi
// 00663f56  64890d00000000       mov dword ptr fs:[0], ecx
// 00663f5d  83c410               add esp, 0x10
// 00663f60  c21400               ret 0x14
// copied from an identical function in another client (function ??0EnumDesc@@QAE@HHHHH@Z)

typedef unsigned int size_t;

void* __cdecl operator new(size_t);
void __cdecl operator delete(void*);

extern void __cdecl registerDescriptor(void (__cdecl*)(), int*);
extern void __cdecl descriptorCallback();
extern int descriptorRegistration;
extern void* __cdecl getEnumName();
extern void* __cdecl getEnumType();

struct EnumBase {
    unsigned char data[20];

    EnumBase(void*, void*, int, int, int);
    ~EnumBase();
    virtual void describe();
};

struct EnumTypeBase : EnumBase {
    EnumTypeBase(int, int, int, void*, void*);
};

inline EnumTypeBase::EnumTypeBase(int a, int b, int e, void* n, void* t)
    : EnumBase(t, n, a, b, e)
{
}

struct NamedEnum : EnumTypeBase {
    void* name;

    NamedEnum(int, int, int, void*);
};

inline NamedEnum::NamedEnum(int a, int b, int e, void* n)
    : EnumTypeBase(a, b, e, n, getEnumType()), name(n)
{
}

struct EnumValue {
    int first;
    int second;

    EnumValue(int, int);
    virtual void invoke();
};

inline EnumValue::EnumValue(int b, int a)
    : first(a), second(b)
{
}

struct EnumDesc : NamedEnum {
    EnumValue* value;

    EnumDesc(int, int, int, int, int);
    virtual void describe();
};

EnumDesc::EnumDesc(int a, int b, int c, int d, int e)
    : NamedEnum(a, b, e,
        (registerDescriptor(descriptorCallback, &descriptorRegistration),
         getEnumName()))
{
    value = new EnumValue(d, c);
}