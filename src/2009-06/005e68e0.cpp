// from server: 100% by EspClaude
// roc 2009-06 005e68e0  unit: RBX::Reflection::H::?$TypedPropertyDescriptor  size: 54 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 005e68e0
//
// 005e68e0  51                   push ecx
// 005e68e1  8b4918               mov ecx, dword ptr [ecx + 0x18]
// 005e68e4  8b01                 mov eax, dword ptr [ecx]
// 005e68e6  8b54240c             mov edx, dword ptr [esp + 0xc]
// 005e68ea  8b4008               mov eax, dword ptr [eax + 8]
// 005e68ed  56                   push esi
// 005e68ee  52                   push edx
// 005e68ef  c744240800000000     mov dword ptr [esp + 8], 0
// 005e68f7  ffd0                 call eax
// 005e68f9  8b74240c             mov esi, dword ptr [esp + 0xc]
// 005e68fd  8d4c2410             lea ecx, [esp + 0x10]
// 005e6901  51                   push ecx
// 005e6902  56                   push esi
// 005e6903  89442418             mov dword ptr [esp + 0x18], eax
// 005e6907  e8844a0600           call 0x64b390
// 005e690c  83c408               add esp, 8
// 005e690f  8bc6                 mov eax, esi
// 005e6911  5e                   pop esi
// 005e6912  59                   pop ecx
// 005e6913  c20800               ret 8
// copied from an identical function in another client (function ?f@S@ns_ROCX000007@@QAEPAXPAX0@Z)

namespace ns_ROCX000007 {
struct Accessor {
    virtual void slot0();
    virtual void slot1();
    virtual void* get(void*);
};

extern "C" void __cdecl convert(void*, void**);

struct S {
    unsigned char padding[24];
    Accessor* accessor;
    void* f(void* result, void* object);
};

void* S::f(void* result, void* object)
{
    volatile unsigned int unused = 0;
    object = accessor->get(object);
    convert(result, &object);
    return result;
}
}
