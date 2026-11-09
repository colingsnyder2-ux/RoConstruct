// from server: 100% by EspClaude
// roc 2009-06 006640f0  unit: RBX::LegacyController::$00W4InputType::?$SurfaceEnumPropDescriptor  size: 76 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006640f0
//
// 006640f0  51                   push ecx
// 006640f1  8b491c               mov ecx, dword ptr [ecx + 0x1c]
// 006640f4  8b01                 mov eax, dword ptr [ecx]
// 006640f6  8b54240c             mov edx, dword ptr [esp + 0xc]
// 006640fa  8b4008               mov eax, dword ptr [eax + 8]
// 006640fd  56                   push esi
// 006640fe  52                   push edx
// 006640ff  c744240800000000     mov dword ptr [esp + 8], 0
// 00664107  ffd0                 call eax
// 00664109  6830f25e00           push 0x5ef230
// 0066410e  68c0a4a400           push 0xa4a4c0
// 00664113  89442418             mov dword ptr [esp + 0x18], eax
// 00664117  e8f4d5d9ff           call 0x401710
// 0066411c  83c408               add esp, 8
// 0066411f  e8acb0f8ff           call 0x5ef1d0
// 00664124  8b74240c             mov esi, dword ptr [esp + 0xc]
// 00664128  8d4c2410             lea ecx, [esp + 0x10]
// 0066412c  51                   push ecx
// 0066412d  56                   push esi
// 0066412e  8bc8                 mov ecx, eax
// 00664130  e80bcc0a00           call 0x710d40
// 00664135  8bc6                 mov eax, esi
// 00664137  5e                   pop esi
// 00664138  59                   pop ecx
// 00664139  c20800               ret 8
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
