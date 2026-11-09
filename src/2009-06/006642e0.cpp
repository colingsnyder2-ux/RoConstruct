// from server: 100% by EspClaude
// roc 2009-06 006642e0  unit: RBX::$00W4SurfaceType::?$SurfaceEnumPropDescriptor  size: 163 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006642e0
//
// 006642e0  6aff                 push -1
// 006642e2  68f8a28500           push 0x85a2f8
// 006642e7  64a100000000         mov eax, dword ptr fs:[0]
// 006642ed  50                   push eax
// 006642ee  64892500000000       mov dword ptr fs:[0], esp
// 006642f5  51                   push ecx
// 006642f6  56                   push esi
// 006642f7  57                   push edi
// 006642f8  8bf1                 mov esi, ecx
// 006642fa  6830f25e00           push 0x5ef230
// 006642ff  68c0a4a400           push 0xa4a4c0
// 00664304  89742410             mov dword ptr [esp + 0x10], esi
// 00664308  e803d4d9ff           call 0x401710
// 0066430d  83c408               add esp, 8
// 00664310  e8bbaef8ff           call 0x5ef1d0
// 00664315  8bf8                 mov edi, eax
// 00664317  e85465f8ff           call 0x5ea870
// 0066431c  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 00664320  8b542420             mov edx, dword ptr [esp + 0x20]
// 00664324  51                   push ecx
// 00664325  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 00664329  52                   push edx
// 0066432a  51                   push ecx
// 0066432b  57                   push edi
// 0066432c  50                   push eax
// 0066432d  8bce                 mov ecx, esi
// 0066432f  e8fc44f9ff           call 0x5f8830
// 00664334  897e18               mov dword ptr [esi + 0x18], edi
// 00664337  6a0c                 push 0xc
// 00664339  c744241800000000     mov dword ptr [esp + 0x18], 0
// 00664341  c706f4208e00         mov dword ptr [esi], 0x8e20f4
// 00664347  e8ec460b00           call 0x718a38
// 0066434c  83c404               add esp, 4
// 0066434f  85c0                 test eax, eax
// 00664351  7416                 je 0x664369
// 00664353  8b542424             mov edx, dword ptr [esp + 0x24]
// 00664357  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 0066435b  c700341b8e00         mov dword ptr [eax], 0x8e1b34
// 00664361  895004               mov dword ptr [eax + 4], edx
// 00664364  894808               mov dword ptr [eax + 8], ecx
// 00664367  eb02                 jmp 0x66436b
// 00664369  33c0                 xor eax, eax
// 0066436b  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0066436f  89461c               mov dword ptr [esi + 0x1c], eax
// 00664372  5f                   pop edi
// 00664373  8bc6                 mov eax, esi
// 00664375  5e                   pop esi
// 00664376  64890d00000000       mov dword ptr fs:[0], ecx
// 0066437d  83c410               add esp, 0x10
// 00664380  c21400               ret 0x14
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