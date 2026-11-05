// from server: 100% by EspClaude
// roc 2009-06 00663910  unit: RBX::$00W4SurfaceType::?$SurfaceEnumPropDescriptor  size: 163 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00663910
//
// 00663910  6aff                 push -1
// 00663912  68f8a28500           push 0x85a2f8
// 00663917  64a100000000         mov eax, dword ptr fs:[0]
// 0066391d  50                   push eax
// 0066391e  64892500000000       mov dword ptr fs:[0], esp
// 00663925  51                   push ecx
// 00663926  56                   push esi
// 00663927  57                   push edi
// 00663928  8bf1                 mov esi, ecx
// 0066392a  6830f25e00           push 0x5ef230
// 0066392f  68c0a4a400           push 0xa4a4c0
// 00663934  89742410             mov dword ptr [esp + 0x10], esi
// 00663938  e8d3ddd9ff           call 0x401710
// 0066393d  83c408               add esp, 8
// 00663940  e88bb8f8ff           call 0x5ef1d0
// 00663945  8bf8                 mov edi, eax
// 00663947  e8246ff8ff           call 0x5ea870
// 0066394c  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 00663950  8b542420             mov edx, dword ptr [esp + 0x20]
// 00663954  51                   push ecx
// 00663955  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 00663959  52                   push edx
// 0066395a  51                   push ecx
// 0066395b  57                   push edi
// 0066395c  50                   push eax
// 0066395d  8bce                 mov ecx, esi
// 0066395f  e8cc4ef9ff           call 0x5f8830
// 00663964  897e18               mov dword ptr [esi + 0x18], edi
// 00663967  6a0c                 push 0xc
// 00663969  c744241800000000     mov dword ptr [esp + 0x18], 0
// 00663971  c706141f8e00         mov dword ptr [esi], 0x8e1f14
// 00663977  e8bc500b00           call 0x718a38
// 0066397c  83c404               add esp, 4
// 0066397f  85c0                 test eax, eax
// 00663981  7416                 je 0x663999
// 00663983  8b542424             mov edx, dword ptr [esp + 0x24]
// 00663987  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 0066398b  c700801a8e00         mov dword ptr [eax], 0x8e1a80
// 00663991  895004               mov dword ptr [eax + 4], edx
// 00663994  894808               mov dword ptr [eax + 8], ecx
// 00663997  eb02                 jmp 0x66399b
// 00663999  33c0                 xor eax, eax
// 0066399b  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0066399f  89461c               mov dword ptr [esi + 0x1c], eax
// 006639a2  5f                   pop edi
// 006639a3  8bc6                 mov eax, esi
// 006639a5  5e                   pop esi
// 006639a6  64890d00000000       mov dword ptr fs:[0], ecx
// 006639ad  83c410               add esp, 0x10
// 006639b0  c21400               ret 0x14
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