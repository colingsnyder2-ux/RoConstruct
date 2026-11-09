// from server: 100% by EspClaude
// roc 2009-06 006ca1a0  unit: RBX::$$A6AXABVStepped::?$signal::slot  size: 70 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006ca1a0
//
// 006ca1a0  8b442408             mov eax, dword ptr [esp + 8]
// 006ca1a4  8a08                 mov cl, byte ptr [eax]
// 006ca1a6  56                   push esi
// 006ca1a7  8b742408             mov esi, dword ptr [esp + 8]
// 006ca1ab  6a00                 push 0
// 006ca1ad  6850f99d00           push 0x9df950
// 006ca1b2  6840be9d00           push 0x9dbe40
// 006ca1b7  6a00                 push 0
// 006ca1b9  56                   push esi
// 006ca1ba  884c2420             mov byte ptr [esp + 0x20], cl
// 006ca1be  e8b7fa0400           call 0x719c7a
// 006ca1c3  83c414               add esp, 0x14
// 006ca1c6  85c0                 test eax, eax
// 006ca1c8  740e                 je 0x6ca1d8
// 006ca1ca  8b54240c             mov edx, dword ptr [esp + 0xc]
// 006ca1ce  52                   push edx
// 006ca1cf  8bc8                 mov ecx, eax
// 006ca1d1  e86a63f9ff           call 0x660540
// 006ca1d6  5e                   pop esi
// 006ca1d7  c3                   ret 
// 006ca1d8  8b44240c             mov eax, dword ptr [esp + 0xc]
// 006ca1dc  50                   push eax
// 006ca1dd  8bce                 mov ecx, esi
// 006ca1df  e81c010000           call 0x6ca300
// 006ca1e4  5e                   pop esi
// 006ca1e5  c3                   ret 
// copied from an identical function in another client (function ?setValue@ns_ROCX000013@@YAXPAUInstance@1@AB_N@Z)

namespace ns_ROCX000013 {
extern char instanceType;
extern char partType;

extern "C" void* __cdecl castObject(
    void* object, int offset, void* sourceType, void* targetType, int isReference);

struct Instance
{
    void setValue(bool value);
};

struct Part
{
    void setValue(bool value);
};

void __cdecl setValue(Instance* instance, const bool& value)
{
    bool newValue = value;
    Part* part = static_cast<Part*>(
        castObject(instance, 0, &instanceType, &partType, 0));

    if (part)
        part->setValue(newValue);
    else
        instance->setValue(newValue);
}
}
