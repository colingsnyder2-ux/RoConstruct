// from server: 100% by EspClaude
// roc 2009-06 00664760  unit: RBX::LegacyController::$00W4InputType::?$SurfaceEnumPropDescriptor  size: 163 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00664760
//
// 00664760  6aff                 push -1
// 00664762  68f8a28500           push 0x85a2f8
// 00664767  64a100000000         mov eax, dword ptr fs:[0]
// 0066476d  50                   push eax
// 0066476e  64892500000000       mov dword ptr fs:[0], esp
// 00664775  51                   push ecx
// 00664776  56                   push esi
// 00664777  57                   push edi
// 00664778  8bf1                 mov esi, ecx
// 0066477a  6800f75e00           push 0x5ef700
// 0066477f  68eca4a400           push 0xa4a4ec
// 00664784  89742410             mov dword ptr [esp + 0x10], esi
// 00664788  e883cfd9ff           call 0x401710
// 0066478d  83c408               add esp, 8
// 00664790  e80baff8ff           call 0x5ef6a0
// 00664795  8bf8                 mov edi, eax
// 00664797  e8d460f8ff           call 0x5ea870
// 0066479c  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 006647a0  8b542420             mov edx, dword ptr [esp + 0x20]
// 006647a4  51                   push ecx
// 006647a5  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 006647a9  52                   push edx
// 006647aa  51                   push ecx
// 006647ab  57                   push edi
// 006647ac  50                   push eax
// 006647ad  8bce                 mov ecx, esi
// 006647af  e87c40f9ff           call 0x5f8830
// 006647b4  897e18               mov dword ptr [esi + 0x18], edi
// 006647b7  6a0c                 push 0xc
// 006647b9  c744241800000000     mov dword ptr [esp + 0x18], 0
// 006647c1  c706e4218e00         mov dword ptr [esi], 0x8e21e4
// 006647c7  e86c420b00           call 0x718a38
// 006647cc  83c404               add esp, 4
// 006647cf  85c0                 test eax, eax
// 006647d1  7416                 je 0x6647e9
// 006647d3  8b542424             mov edx, dword ptr [esp + 0x24]
// 006647d7  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 006647db  c700981b8e00         mov dword ptr [eax], 0x8e1b98
// 006647e1  895004               mov dword ptr [eax + 4], edx
// 006647e4  894808               mov dword ptr [eax + 8], ecx
// 006647e7  eb02                 jmp 0x6647eb
// 006647e9  33c0                 xor eax, eax
// 006647eb  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 006647ef  89461c               mov dword ptr [esi + 0x1c], eax
// 006647f2  5f                   pop edi
// 006647f3  8bc6                 mov eax, esi
// 006647f5  5e                   pop esi
// 006647f6  64890d00000000       mov dword ptr fs:[0], ecx
// 006647fd  83c410               add esp, 0x10
// 00664800  c21400               ret 0x14
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