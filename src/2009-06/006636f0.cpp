// from server: 100% by EspClaude
// roc 2009-06 006636f0  unit: RBX::$01::?$SurfaceDescriptor  size: 163 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006636f0
//
// 006636f0  6aff                 push -1
// 006636f2  68f8a28500           push 0x85a2f8
// 006636f7  64a100000000         mov eax, dword ptr fs:[0]
// 006636fd  50                   push eax
// 006636fe  64892500000000       mov dword ptr fs:[0], esp
// 00663705  51                   push ecx
// 00663706  56                   push esi
// 00663707  57                   push edi
// 00663708  8bf1                 mov esi, ecx
// 0066370a  6800f75e00           push 0x5ef700
// 0066370f  68eca4a400           push 0xa4a4ec
// 00663714  89742410             mov dword ptr [esp + 0x10], esi
// 00663718  e8f3dfd9ff           call 0x401710
// 0066371d  83c408               add esp, 8
// 00663720  e87bbff8ff           call 0x5ef6a0
// 00663725  8bf8                 mov edi, eax
// 00663727  e84471f8ff           call 0x5ea870
// 0066372c  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 00663730  8b542420             mov edx, dword ptr [esp + 0x20]
// 00663734  51                   push ecx
// 00663735  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 00663739  52                   push edx
// 0066373a  51                   push ecx
// 0066373b  57                   push edi
// 0066373c  50                   push eax
// 0066373d  8bce                 mov ecx, esi
// 0066373f  e8ec50f9ff           call 0x5f8830
// 00663744  897e18               mov dword ptr [esi + 0x18], edi
// 00663747  6a0c                 push 0xc
// 00663749  c744241800000000     mov dword ptr [esp + 0x18], 0
// 00663751  c706c41e8e00         mov dword ptr [esi], 0x8e1ec4
// 00663757  e8dc520b00           call 0x718a38
// 0066375c  83c404               add esp, 4
// 0066375f  85c0                 test eax, eax
// 00663761  7416                 je 0x663779
// 00663763  8b542424             mov edx, dword ptr [esp + 0x24]
// 00663767  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 0066376b  c7006c1a8e00         mov dword ptr [eax], 0x8e1a6c
// 00663771  895004               mov dword ptr [eax + 4], edx
// 00663774  894808               mov dword ptr [eax + 8], ecx
// 00663777  eb02                 jmp 0x66377b
// 00663779  33c0                 xor eax, eax
// 0066377b  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0066377f  89461c               mov dword ptr [esi + 0x1c], eax
// 00663782  5f                   pop edi
// 00663783  8bc6                 mov eax, esi
// 00663785  5e                   pop esi
// 00663786  64890d00000000       mov dword ptr fs:[0], ecx
// 0066378d  83c410               add esp, 0x10
// 00663790  c21400               ret 0x14
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