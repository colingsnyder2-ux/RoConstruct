// from server: 100% by EspClaude
// roc 2009-06 00663d90  unit: RBX::$00W4SurfaceType::?$SurfaceEnumPropDescriptor  size: 163 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00663d90
//
// 00663d90  6aff                 push -1
// 00663d92  68f8a28500           push 0x85a2f8
// 00663d97  64a100000000         mov eax, dword ptr fs:[0]
// 00663d9d  50                   push eax
// 00663d9e  64892500000000       mov dword ptr fs:[0], esp
// 00663da5  51                   push ecx
// 00663da6  56                   push esi
// 00663da7  57                   push edi
// 00663da8  8bf1                 mov esi, ecx
// 00663daa  6830f25e00           push 0x5ef230
// 00663daf  68c0a4a400           push 0xa4a4c0
// 00663db4  89742410             mov dword ptr [esp + 0x10], esi
// 00663db8  e853d9d9ff           call 0x401710
// 00663dbd  83c408               add esp, 8
// 00663dc0  e80bb4f8ff           call 0x5ef1d0
// 00663dc5  8bf8                 mov edi, eax
// 00663dc7  e8a46af8ff           call 0x5ea870
// 00663dcc  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 00663dd0  8b542420             mov edx, dword ptr [esp + 0x20]
// 00663dd4  51                   push ecx
// 00663dd5  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 00663dd9  52                   push edx
// 00663dda  51                   push ecx
// 00663ddb  57                   push edi
// 00663ddc  50                   push eax
// 00663ddd  8bce                 mov ecx, esi
// 00663ddf  e84c4af9ff           call 0x5f8830
// 00663de4  897e18               mov dword ptr [esi + 0x18], edi
// 00663de7  6a0c                 push 0xc
// 00663de9  c744241800000000     mov dword ptr [esp + 0x18], 0
// 00663df1  c706b41f8e00         mov dword ptr [esi], 0x8e1fb4
// 00663df7  e83c4c0b00           call 0x718a38
// 00663dfc  83c404               add esp, 4
// 00663dff  85c0                 test eax, eax
// 00663e01  7416                 je 0x663e19
// 00663e03  8b542424             mov edx, dword ptr [esp + 0x24]
// 00663e07  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 00663e0b  c700bc1a8e00         mov dword ptr [eax], 0x8e1abc
// 00663e11  895004               mov dword ptr [eax + 4], edx
// 00663e14  894808               mov dword ptr [eax + 8], ecx
// 00663e17  eb02                 jmp 0x663e1b
// 00663e19  33c0                 xor eax, eax
// 00663e1b  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00663e1f  89461c               mov dword ptr [esi + 0x1c], eax
// 00663e22  5f                   pop edi
// 00663e23  8bc6                 mov eax, esi
// 00663e25  5e                   pop esi
// 00663e26  64890d00000000       mov dword ptr fs:[0], ecx
// 00663e2d  83c410               add esp, 0x10
// 00663e30  c21400               ret 0x14
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