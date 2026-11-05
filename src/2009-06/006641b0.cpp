// from server: 100% by EspClaude
// roc 2009-06 006641b0  unit: RBX::LegacyController::$00W4InputType::?$SurfaceEnumPropDescriptor  size: 163 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006641b0
//
// 006641b0  6aff                 push -1
// 006641b2  68f8a28500           push 0x85a2f8
// 006641b7  64a100000000         mov eax, dword ptr fs:[0]
// 006641bd  50                   push eax
// 006641be  64892500000000       mov dword ptr fs:[0], esp
// 006641c5  51                   push ecx
// 006641c6  56                   push esi
// 006641c7  57                   push edi
// 006641c8  8bf1                 mov esi, ecx
// 006641ca  6800f75e00           push 0x5ef700
// 006641cf  68eca4a400           push 0xa4a4ec
// 006641d4  89742410             mov dword ptr [esp + 0x10], esi
// 006641d8  e833d5d9ff           call 0x401710
// 006641dd  83c408               add esp, 8
// 006641e0  e8bbb4f8ff           call 0x5ef6a0
// 006641e5  8bf8                 mov edi, eax
// 006641e7  e88466f8ff           call 0x5ea870
// 006641ec  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 006641f0  8b542420             mov edx, dword ptr [esp + 0x20]
// 006641f4  51                   push ecx
// 006641f5  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 006641f9  52                   push edx
// 006641fa  51                   push ecx
// 006641fb  57                   push edi
// 006641fc  50                   push eax
// 006641fd  8bce                 mov ecx, esi
// 006641ff  e82c46f9ff           call 0x5f8830
// 00664204  897e18               mov dword ptr [esi + 0x18], edi
// 00664207  6a0c                 push 0xc
// 00664209  c744241800000000     mov dword ptr [esp + 0x18], 0
// 00664211  c706a4208e00         mov dword ptr [esi], 0x8e20a4
// 00664217  e81c480b00           call 0x718a38
// 0066421c  83c404               add esp, 4
// 0066421f  85c0                 test eax, eax
// 00664221  7416                 je 0x664239
// 00664223  8b542424             mov edx, dword ptr [esp + 0x24]
// 00664227  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 0066422b  c700201b8e00         mov dword ptr [eax], 0x8e1b20
// 00664231  895004               mov dword ptr [eax + 4], edx
// 00664234  894808               mov dword ptr [eax + 8], ecx
// 00664237  eb02                 jmp 0x66423b
// 00664239  33c0                 xor eax, eax
// 0066423b  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0066423f  89461c               mov dword ptr [esi + 0x1c], eax
// 00664242  5f                   pop edi
// 00664243  8bc6                 mov eax, esi
// 00664245  5e                   pop esi
// 00664246  64890d00000000       mov dword ptr fs:[0], ecx
// 0066424d  83c410               add esp, 0x10
// 00664250  c21400               ret 0x14
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