// from server: 100% by nuck16
// roc 2009-12 006d6060  unit: RBX::MaterialTool  size: 34 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 006d6060
//
// 006d6060  51                   push ecx
// 006d6061  56                   push esi
// 006d6062  8b74240c             mov esi, dword ptr [esp + 0xc]
// 006d6066  68b08d9d00           push 0x9d8db0
// 006d606b  8bce                 mov ecx, esi
// 006d606d  c744240800000000     mov dword ptr [esp + 8], 0
// 006d6075  ff15f4b69800         call dword ptr [0x98b6f4]
// 006d607b  8bc6                 mov eax, esi
// 006d607d  5e                   pop esi
// 006d607e  59                   pop ecx
// 006d607f  c20400               ret 4

#include <string>

struct S
{
    std::string f() const;
};

std::string S::f() const
{
    return "MaterialCursor";
}
