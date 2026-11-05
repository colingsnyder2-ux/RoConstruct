// from server: 100% by nuck16
// roc 2009-12 006d5200  unit: RBX::GlueTool  size: 34 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 006d5200
//
// 006d5200  51                   push ecx
// 006d5201  56                   push esi
// 006d5202  8b74240c             mov esi, dword ptr [esp + 0xc]
// 006d5206  68dc859d00           push 0x9d85dc
// 006d520b  8bce                 mov ecx, esi
// 006d520d  c744240800000000     mov dword ptr [esp + 8], 0
// 006d5215  ff15f4b69800         call dword ptr [0x98b6f4]
// 006d521b  8bc6                 mov eax, esi
// 006d521d  5e                   pop esi
// 006d521e  59                   pop ecx
// 006d521f  c20400               ret 4

#include <string>

struct S
{
    std::string f() const;
};

std::string S::f() const
{
    return "GlueCursor";
}
