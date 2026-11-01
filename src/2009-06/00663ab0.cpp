// from server: 100% by EspClaude
// roc 2009-06 00663ab0  unit: RBX::LegacyController::$00W4InputType::?$SurfaceEnumPropDescriptor  size: 163 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00663ab0
//
// 00663ab0  6aff                 push -1
// 00663ab2  68f8a28500           push 0x85a2f8
// 00663ab7  64a100000000         mov eax, dword ptr fs:[0]
// 00663abd  50                   push eax
// 00663abe  64892500000000       mov dword ptr fs:[0], esp
// 00663ac5  51                   push ecx
// 00663ac6  56                   push esi
// 00663ac7  57                   push edi
// 00663ac8  8bf1                 mov esi, ecx
// 00663aca  6800f75e00           push 0x5ef700
// 00663acf  68eca4a400           push 0xa4a4ec
// 00663ad4  89742410             mov dword ptr [esp + 0x10], esi
// 00663ad8  e833dcd9ff           call 0x401710
// 00663add  83c408               add esp, 8
// 00663ae0  e8bbbbf8ff           call 0x5ef6a0
// 00663ae5  8bf8                 mov edi, eax
// 00663ae7  e8846df8ff           call 0x5ea870
// 00663aec  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 00663af0  8b542420             mov edx, dword ptr [esp + 0x20]
// 00663af4  51                   push ecx
// 00663af5  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 00663af9  52                   push edx
// 00663afa  51                   push ecx
// 00663afb  57                   push edi
// 00663afc  50                   push eax
// 00663afd  8bce                 mov ecx, esi
// 00663aff  e82c4df9ff           call 0x5f8830
// 00663b04  897e18               mov dword ptr [esi + 0x18], edi
// 00663b07  6a0c                 push 0xc
// 00663b09  c744241800000000     mov dword ptr [esp + 0x18], 0
// 00663b11  c706641f8e00         mov dword ptr [esi], 0x8e1f64
// 00663b17  e81c4f0b00           call 0x718a38
// 00663b1c  83c404               add esp, 4
// 00663b1f  85c0                 test eax, eax
// 00663b21  7416                 je 0x663b39
// 00663b23  8b542424             mov edx, dword ptr [esp + 0x24]
// 00663b27  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 00663b2b  c700a81a8e00         mov dword ptr [eax], 0x8e1aa8
// 00663b31  895004               mov dword ptr [eax + 4], edx
// 00663b34  894808               mov dword ptr [eax + 8], ecx
// 00663b37  eb02                 jmp 0x663b3b
// 00663b39  33c0                 xor eax, eax
// 00663b3b  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00663b3f  89461c               mov dword ptr [esi + 0x1c], eax
// 00663b42  5f                   pop edi
// 00663b43  8bc6                 mov eax, esi
// 00663b45  5e                   pop esi
// 00663b46  64890d00000000       mov dword ptr fs:[0], ecx
// 00663b4d  83c410               add esp, 0x10
// 00663b50  c21400               ret 0x14
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