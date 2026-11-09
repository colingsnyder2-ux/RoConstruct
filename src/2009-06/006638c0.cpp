// from server: 100% by EspClaude
// roc 2009-06 006638c0  unit: RBX::$00W4SurfaceType::?$SurfaceEnumPropDescriptor  size: 76 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006638c0
//
// 006638c0  51                   push ecx
// 006638c1  8b491c               mov ecx, dword ptr [ecx + 0x1c]
// 006638c4  8b01                 mov eax, dword ptr [ecx]
// 006638c6  8b54240c             mov edx, dword ptr [esp + 0xc]
// 006638ca  8b4008               mov eax, dword ptr [eax + 8]
// 006638cd  56                   push esi
// 006638ce  52                   push edx
// 006638cf  c744240800000000     mov dword ptr [esp + 8], 0
// 006638d7  ffd0                 call eax
// 006638d9  6800f75e00           push 0x5ef700
// 006638de  68eca4a400           push 0xa4a4ec
// 006638e3  89442418             mov dword ptr [esp + 0x18], eax
// 006638e7  e824ded9ff           call 0x401710
// 006638ec  83c408               add esp, 8
// 006638ef  e8acbdf8ff           call 0x5ef6a0
// 006638f4  8b74240c             mov esi, dword ptr [esp + 0xc]
// 006638f8  8d4c2410             lea ecx, [esp + 0x10]
// 006638fc  51                   push ecx
// 006638fd  56                   push esi
// 006638fe  8bc8                 mov ecx, eax
// 00663900  e83bd40a00           call 0x710d40
// 00663905  8bc6                 mov eax, esi
// 00663907  5e                   pop esi
// 00663908  59                   pop ecx
// 00663909  c20800               ret 8
// copied from an identical function in another client (function ?get@Property@ns_ROCX000002@@QAEPAXPAXH@Z)

namespace ns_ROCX000002 {
struct Accessor {
    virtual void slot0();
    virtual void slot1();
    virtual int get(void* object);
};

struct EnumDescriptor {
    void convert(void* output, const int* value);
};

extern "C" void __cdecl initialize(void (__cdecl* callback)(), void* storage);
extern "C" void __cdecl callback();
extern "C" EnumDescriptor* __cdecl descriptor();
extern unsigned char storage;

struct Property {
    unsigned char padding[28];
    Accessor* accessor;

    void* get(void* output, int object);
};

void* Property::get(void* output, int object)
{
    volatile int initial = 0;
    object = accessor->get(reinterpret_cast<void*>(object));
    initialize(callback, &storage);
    EnumDescriptor* desc = descriptor();
    desc->convert(output, &object);
    return output;
}
}
