// from server: 100% by EspClaude
// roc 2009-06 00664040  unit: RBX::$00W4SurfaceType::?$SurfaceEnumPropDescriptor  size: 163 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00664040
//
// 00664040  6aff                 push -1
// 00664042  68f8a28500           push 0x85a2f8
// 00664047  64a100000000         mov eax, dword ptr fs:[0]
// 0066404d  50                   push eax
// 0066404e  64892500000000       mov dword ptr fs:[0], esp
// 00664055  51                   push ecx
// 00664056  56                   push esi
// 00664057  57                   push edi
// 00664058  8bf1                 mov esi, ecx
// 0066405a  6830f25e00           push 0x5ef230
// 0066405f  68c0a4a400           push 0xa4a4c0
// 00664064  89742410             mov dword ptr [esp + 0x10], esi
// 00664068  e8a3d6d9ff           call 0x401710
// 0066406d  83c408               add esp, 8
// 00664070  e85bb1f8ff           call 0x5ef1d0
// 00664075  8bf8                 mov edi, eax
// 00664077  e8f467f8ff           call 0x5ea870
// 0066407c  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 00664080  8b542420             mov edx, dword ptr [esp + 0x20]
// 00664084  51                   push ecx
// 00664085  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 00664089  52                   push edx
// 0066408a  51                   push ecx
// 0066408b  57                   push edi
// 0066408c  50                   push eax
// 0066408d  8bce                 mov ecx, esi
// 0066408f  e89c47f9ff           call 0x5f8830
// 00664094  897e18               mov dword ptr [esi + 0x18], edi
// 00664097  6a0c                 push 0xc
// 00664099  c744241800000000     mov dword ptr [esp + 0x18], 0
// 006640a1  c70654208e00         mov dword ptr [esi], 0x8e2054
// 006640a7  e88c490b00           call 0x718a38
// 006640ac  83c404               add esp, 4
// 006640af  85c0                 test eax, eax
// 006640b1  7416                 je 0x6640c9
// 006640b3  8b542424             mov edx, dword ptr [esp + 0x24]
// 006640b7  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 006640bb  c700f81a8e00         mov dword ptr [eax], 0x8e1af8
// 006640c1  895004               mov dword ptr [eax + 4], edx
// 006640c4  894808               mov dword ptr [eax + 8], ecx
// 006640c7  eb02                 jmp 0x6640cb
// 006640c9  33c0                 xor eax, eax
// 006640cb  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 006640cf  89461c               mov dword ptr [esi + 0x1c], eax
// 006640d2  5f                   pop edi
// 006640d3  8bc6                 mov eax, esi
// 006640d5  5e                   pop esi
// 006640d6  64890d00000000       mov dword ptr fs:[0], ecx
// 006640dd  83c410               add esp, 0x10
// 006640e0  c21400               ret 0x14
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