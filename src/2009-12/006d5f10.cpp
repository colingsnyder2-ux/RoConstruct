// from server: 100% by nuck16
// roc 2009-12 006d5f10  unit: RBX::FillTool  size: 34 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 006d5f10
//
// 006d5f10  51                   push ecx
// 006d5f11  56                   push esi
// 006d5f12  8b74240c             mov esi, dword ptr [esp + 0xc]
// 006d5f16  68188d9d00           push 0x9d8d18
// 006d5f1b  8bce                 mov ecx, esi
// 006d5f1d  c744240800000000     mov dword ptr [esp + 8], 0
// 006d5f25  ff15f4b69800         call dword ptr [0x98b6f4]
// 006d5f2b  8bc6                 mov eax, esi
// 006d5f2d  5e                   pop esi
// 006d5f2e  59                   pop ecx
// 006d5f2f  c20400               ret 4

#include <string>

struct S
{
    std::string f() const;
};

std::string S::f() const
{
    return "FillCursor";
}
