// from server: 100% by nuck16
// roc 2009-12 00698cd0  unit: RBX::DecalTool  size: 34 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00698cd0
//
// 00698cd0  51                   push ecx
// 00698cd1  56                   push esi
// 00698cd2  8b74240c             mov esi, dword ptr [esp + 0xc]
// 00698cd6  68fc229d00           push 0x9d22fc
// 00698cdb  8bce                 mov ecx, esi
// 00698cdd  c744240800000000     mov dword ptr [esp + 8], 0
// 00698ce5  ff15f4b69800         call dword ptr [0x98b6f4]
// 00698ceb  8bc6                 mov eax, esi
// 00698ced  5e                   pop esi
// 00698cee  59                   pop ecx
// 00698cef  c20400               ret 4

#include <string>

struct S
{
    std::string f() const;
};

std::string S::f() const
{
    return "ArrowCursorDecalDrag";
}
