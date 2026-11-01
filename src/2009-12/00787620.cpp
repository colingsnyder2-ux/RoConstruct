// from server: 100% by nuck16
// roc 2009-12 00787620  unit: RBX::NullTool  size: 34 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00787620
//
// 00787620  51                   push ecx
// 00787621  56                   push esi
// 00787622  8b74240c             mov esi, dword ptr [esp + 0xc]
// 00787626  68909b9e00           push 0x9e9b90
// 0078762b  8bce                 mov ecx, esi
// 0078762d  c744240800000000     mov dword ptr [esp + 8], 0
// 00787635  ff15f4b69800         call dword ptr [0x98b6f4]
// 0078763b  8bc6                 mov eax, esi
// 0078763d  5e                   pop esi
// 0078763e  59                   pop ecx
// 0078763f  c20400               ret 4

#include <string>

struct S
{
    std::string f() const;
};

std::string S::f() const
{
    return "ArrowFarCursor";
}
