// from server: 100% by EspClaude
// roc 2009-06 006644c0  unit: RBX::LegacyController::$00W4InputType::?$SurfaceEnumPropDescriptor  size: 163 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006644c0
//
// 006644c0  6aff                 push -1
// 006644c2  68f8a28500           push 0x85a2f8
// 006644c7  64a100000000         mov eax, dword ptr fs:[0]
// 006644cd  50                   push eax
// 006644ce  64892500000000       mov dword ptr fs:[0], esp
// 006644d5  51                   push ecx
// 006644d6  56                   push esi
// 006644d7  57                   push edi
// 006644d8  8bf1                 mov esi, ecx
// 006644da  6800f75e00           push 0x5ef700
// 006644df  68eca4a400           push 0xa4a4ec
// 006644e4  89742410             mov dword ptr [esp + 0x10], esi
// 006644e8  e823d2d9ff           call 0x401710
// 006644ed  83c408               add esp, 8
// 006644f0  e8abb1f8ff           call 0x5ef6a0
// 006644f5  8bf8                 mov edi, eax
// 006644f7  e87463f8ff           call 0x5ea870
// 006644fc  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 00664500  8b542420             mov edx, dword ptr [esp + 0x20]
// 00664504  51                   push ecx
// 00664505  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 00664509  52                   push edx
// 0066450a  51                   push ecx
// 0066450b  57                   push edi
// 0066450c  50                   push eax
// 0066450d  8bce                 mov ecx, esi
// 0066450f  e81c43f9ff           call 0x5f8830
// 00664514  897e18               mov dword ptr [esi + 0x18], edi
// 00664517  6a0c                 push 0xc
// 00664519  c744241800000000     mov dword ptr [esp + 0x18], 0
// 00664521  c70644218e00         mov dword ptr [esi], 0x8e2144
// 00664527  e80c450b00           call 0x718a38
// 0066452c  83c404               add esp, 4
// 0066452f  85c0                 test eax, eax
// 00664531  7416                 je 0x664549
// 00664533  8b542424             mov edx, dword ptr [esp + 0x24]
// 00664537  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 0066453b  c7005c1b8e00         mov dword ptr [eax], 0x8e1b5c
// 00664541  895004               mov dword ptr [eax + 4], edx
// 00664544  894808               mov dword ptr [eax + 8], ecx
// 00664547  eb02                 jmp 0x66454b
// 00664549  33c0                 xor eax, eax
// 0066454b  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0066454f  89461c               mov dword ptr [esi + 0x1c], eax
// 00664552  5f                   pop edi
// 00664553  8bc6                 mov eax, esi
// 00664555  5e                   pop esi
// 00664556  64890d00000000       mov dword ptr fs:[0], ecx
// 0066455d  83c410               add esp, 0x10
// 00664560  c21400               ret 0x14
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