// from server: 100% by EspClaude
// roc 2009-06 005e6a80  unit: G3D::VVector2int16::?$TypedPropertyDescriptor  size: 55 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 005e6a80
//
// 005e6a80  51                   push ecx
// 005e6a81  8b54240c             mov edx, dword ptr [esp + 0xc]
// 005e6a85  8b4918               mov ecx, dword ptr [ecx + 0x18]
// 005e6a88  8b01                 mov eax, dword ptr [ecx]
// 005e6a8a  8b4008               mov eax, dword ptr [eax + 8]
// 005e6a8d  56                   push esi
// 005e6a8e  52                   push edx
// 005e6a8f  8d542414             lea edx, [esp + 0x14]
// 005e6a93  52                   push edx
// 005e6a94  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 005e6a9c  ffd0                 call eax
// 005e6a9e  8b74240c             mov esi, dword ptr [esp + 0xc]
// 005e6aa2  8d4c2410             lea ecx, [esp + 0x10]
// 005e6aa6  51                   push ecx
// 005e6aa7  56                   push esi
// 005e6aa8  e893500600           call 0x64bb40
// 005e6aad  83c408               add esp, 8
// 005e6ab0  8bc6                 mov eax, esi
// 005e6ab2  5e                   pop esi
// 005e6ab3  59                   pop ecx
// 005e6ab4  c20800               ret 8
// copied from an identical function in another client (function ?f@S@ns_ROCX00000c@@QAEPAXPAX0@Z)

namespace ns_ROCX00000c {
struct Accessor
{
    virtual void slot0();
    virtual void slot1();
    virtual void get(void** result, void* source);
};

extern void __cdecl copyValue(void* destination, const void* source);

struct S
{
    unsigned char padding[24];
    Accessor* accessor;
    void* f(void* destination, void* source);
};

void* S::f(void* destination, void* source)
{
    volatile unsigned long temporary = 0;
    accessor->get(&source, source);
    copyValue(destination, &source);
    return destination;
}
}
