// from server: 100% by EspClaude
// roc 2009-06 00664810  unit: RBX::LegacyController::$00W4InputType::?$SurfaceEnumPropDescriptor  size: 163 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00664810
//
// 00664810  6aff                 push -1
// 00664812  68f8a28500           push 0x85a2f8
// 00664817  64a100000000         mov eax, dword ptr fs:[0]
// 0066481d  50                   push eax
// 0066481e  64892500000000       mov dword ptr fs:[0], esp
// 00664825  51                   push ecx
// 00664826  56                   push esi
// 00664827  57                   push edi
// 00664828  8bf1                 mov esi, ecx
// 0066482a  6830f25e00           push 0x5ef230
// 0066482f  68c0a4a400           push 0xa4a4c0
// 00664834  89742410             mov dword ptr [esp + 0x10], esi
// 00664838  e8d3ced9ff           call 0x401710
// 0066483d  83c408               add esp, 8
// 00664840  e88ba9f8ff           call 0x5ef1d0
// 00664845  8bf8                 mov edi, eax
// 00664847  e82460f8ff           call 0x5ea870
// 0066484c  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 00664850  8b542420             mov edx, dword ptr [esp + 0x20]
// 00664854  51                   push ecx
// 00664855  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 00664859  52                   push edx
// 0066485a  51                   push ecx
// 0066485b  57                   push edi
// 0066485c  50                   push eax
// 0066485d  8bce                 mov ecx, esi
// 0066485f  e8cc3ff9ff           call 0x5f8830
// 00664864  897e18               mov dword ptr [esi + 0x18], edi
// 00664867  6a0c                 push 0xc
// 00664869  c744241800000000     mov dword ptr [esp + 0x18], 0
// 00664871  c70634228e00         mov dword ptr [esi], 0x8e2234
// 00664877  e8bc410b00           call 0x718a38
// 0066487c  83c404               add esp, 4
// 0066487f  85c0                 test eax, eax
// 00664881  7416                 je 0x664899
// 00664883  8b542424             mov edx, dword ptr [esp + 0x24]
// 00664887  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 0066488b  c700ac1b8e00         mov dword ptr [eax], 0x8e1bac
// 00664891  895004               mov dword ptr [eax + 4], edx
// 00664894  894808               mov dword ptr [eax + 8], ecx
// 00664897  eb02                 jmp 0x66489b
// 00664899  33c0                 xor eax, eax
// 0066489b  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0066489f  89461c               mov dword ptr [esi + 0x1c], eax
// 006648a2  5f                   pop edi
// 006648a3  8bc6                 mov eax, esi
// 006648a5  5e                   pop esi
// 006648a6  64890d00000000       mov dword ptr fs:[0], ecx
// 006648ad  83c410               add esp, 0x10
// 006648b0  c21400               ret 0x14
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