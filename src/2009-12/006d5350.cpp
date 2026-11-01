// from server: 100% by nuck16
// roc 2009-12 006d5350  unit: RBX::WeldTool  size: 34 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 006d5350
//
// 006d5350  51                   push ecx
// 006d5351  56                   push esi
// 006d5352  8b74240c             mov esi, dword ptr [esp + 0xc]
// 006d5356  687c869d00           push 0x9d867c
// 006d535b  8bce                 mov ecx, esi
// 006d535d  c744240800000000     mov dword ptr [esp + 8], 0
// 006d5365  ff15f4b69800         call dword ptr [0x98b6f4]
// 006d536b  8bc6                 mov eax, esi
// 006d536d  5e                   pop esi
// 006d536e  59                   pop ecx
// 006d536f  c20400               ret 4

#include <string>

struct S
{
    std::string f() const;
};

std::string S::f() const
{
    return "WeldCursor";
}
