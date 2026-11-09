// from server: 100% by EspClaude
// roc 2009-06 00664570  unit: RBX::LegacyController::$00W4InputType::?$SurfaceEnumPropDescriptor  size: 163 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00664570
//
// 00664570  6aff                 push -1
// 00664572  68f8a28500           push 0x85a2f8
// 00664577  64a100000000         mov eax, dword ptr fs:[0]
// 0066457d  50                   push eax
// 0066457e  64892500000000       mov dword ptr fs:[0], esp
// 00664585  51                   push ecx
// 00664586  56                   push esi
// 00664587  57                   push edi
// 00664588  8bf1                 mov esi, ecx
// 0066458a  6830f25e00           push 0x5ef230
// 0066458f  68c0a4a400           push 0xa4a4c0
// 00664594  89742410             mov dword ptr [esp + 0x10], esi
// 00664598  e873d1d9ff           call 0x401710
// 0066459d  83c408               add esp, 8
// 006645a0  e82bacf8ff           call 0x5ef1d0
// 006645a5  8bf8                 mov edi, eax
// 006645a7  e8c462f8ff           call 0x5ea870
// 006645ac  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 006645b0  8b542420             mov edx, dword ptr [esp + 0x20]
// 006645b4  51                   push ecx
// 006645b5  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 006645b9  52                   push edx
// 006645ba  51                   push ecx
// 006645bb  57                   push edi
// 006645bc  50                   push eax
// 006645bd  8bce                 mov ecx, esi
// 006645bf  e86c42f9ff           call 0x5f8830
// 006645c4  897e18               mov dword ptr [esi + 0x18], edi
// 006645c7  6a0c                 push 0xc
// 006645c9  c744241800000000     mov dword ptr [esp + 0x18], 0
// 006645d1  c70694218e00         mov dword ptr [esi], 0x8e2194
// 006645d7  e85c440b00           call 0x718a38
// 006645dc  83c404               add esp, 4
// 006645df  85c0                 test eax, eax
// 006645e1  7416                 je 0x6645f9
// 006645e3  8b542424             mov edx, dword ptr [esp + 0x24]
// 006645e7  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 006645eb  c700701b8e00         mov dword ptr [eax], 0x8e1b70
// 006645f1  895004               mov dword ptr [eax + 4], edx
// 006645f4  894808               mov dword ptr [eax + 8], ecx
// 006645f7  eb02                 jmp 0x6645fb
// 006645f9  33c0                 xor eax, eax
// 006645fb  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 006645ff  89461c               mov dword ptr [esi + 0x1c], eax
// 00664602  5f                   pop edi
// 00664603  8bc6                 mov eax, esi
// 00664605  5e                   pop esi
// 00664606  64890d00000000       mov dword ptr fs:[0], ecx
// 0066460d  83c410               add esp, 0x10
// 00664610  c21400               ret 0x14
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