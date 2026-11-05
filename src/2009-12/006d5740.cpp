// from server: 100% by nuck16
// roc 2009-12 006d5740  unit: RBX::UniversalTool  size: 34 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 006d5740
//
// 006d5740  51                   push ecx
// 006d5741  56                   push esi
// 006d5742  8b74240c             mov esi, dword ptr [esp + 0xc]
// 006d5746  685c889d00           push 0x9d885c
// 006d574b  8bce                 mov ecx, esi
// 006d574d  c744240800000000     mov dword ptr [esp + 8], 0
// 006d5755  ff15f4b69800         call dword ptr [0x98b6f4]
// 006d575b  8bc6                 mov eax, esi
// 006d575d  5e                   pop esi
// 006d575e  59                   pop ecx
// 006d575f  c20400               ret 4

#include <string>

struct S
{
    std::string f() const;
};

std::string S::f() const
{
    return "UniversalCursor";
}
